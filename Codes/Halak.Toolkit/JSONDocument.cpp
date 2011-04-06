#include <Halak.Toolkit/PCH.h>
#include <Halak.Toolkit/JSONDocument.h>
#include <Halak.Toolkit/JSONNodes.h>
#include <Halak/FileStream.h>
#include <stack>
#include <json_parser.h>

namespace Halak
{
    namespace Toolkit
    {
        JSONDocument::JSONDocument(const String& filename)
        {
            SetFilename(filename);
        }

        JSONDocument::~JSONDocument()
        {
        }

        void JSONDocument::Reload()
        {
            sourceChanged = false;

            if (filename.GetLength() == 0)
            {
                root.Reset();
                return;
            }

            FileStreamPtr stream(new FileStream(filename, FileAccess::Read, FileShare::Read));
            if (stream->CanRead() == false)
            {
                root.Reset();
                return;
            }

            struct ReadingContext
            {
                JSONDocument* Document;
                JSONObjectPtr Root;

                String Key;
                std::stack<JSONNodePtr> Nodes;
            };

            struct ParserCallback
            {
                static int Do(void* ctx, int type, const struct JSON_value_struct* value)
                {
                    ReadingContext* context = reinterpret_cast<ReadingContext*>(ctx);
                    
                    switch (type)
                    {
                        case JSON_T_ARRAY_BEGIN:
                            {
                                JSONArrayPtr array_ = JSONArrayPtr(new JSONArray());
                                PushValue(context, Any(array_, JSONArray::TagName));
                                context->Nodes.push(array_);
                            }
                            break;
                        case JSON_T_ARRAY_END:
                            context->Nodes.pop();
                            break;
                        case JSON_T_OBJECT_BEGIN:
                            {
                                JSONObjectPtr object = JSONObjectPtr(new JSONObject());
                                if (context->Nodes.empty() == false)
                                    PushValue(context, Any(object, JSONObject::TagName));
                                else
                                {
                                    HKAssert(context->Root == nullptr);
                                    context->Root = object;
                                }

                                context->Nodes.push(object);
                            }
                            break;
                        case JSON_T_OBJECT_END:
                            context->Nodes.pop();
                            break;
                        case JSON_T_INTEGER:
                            PushValue(context, value->vu.integer_value);
                            break;
                        case JSON_T_FLOAT:
                            PushValue(context, value->vu.float_value);
                            break;
                        case JSON_T_NULL:
                            PushValue(context, Any::Null);
                            break;
                        case JSON_T_TRUE:
                            PushValue(context, true);
                            break;
                        case JSON_T_FALSE:
                            PushValue(context, false);
                            break;
                        case JSON_T_STRING:
                            PushValue(context, String(value->vu.str.value, 0, value->vu.str.length));
                            break;
                        case JSON_T_KEY:
                            context->Key = String(value->vu.str.value, 0, value->vu.str.length);
                            break;
                    }

                    return 1;
                }

                static void PushValue(ReadingContext* context, const Any& value)
                {
                    if (context->Key.IsEmpty())
                        StaticCast<JSONArray>(context->Nodes.top())->Add(value);
                    else
                        StaticCast<JSONObject>(context->Nodes.top())->Add(context->Key, value);
                    
                    context->Key = String::Empty;
                }
            };

            ReadingContext context;
            context.Document = this;
            context.Root.Reset();
            context.Key = String::Empty;

            JSON_config config;
            config.callback = &ParserCallback::Do;
            config.callback_ctx = &context;
            config.depth = -1; // Node 깊이 한계 없이 읽어온다.
            config.allow_comments = ~0; // C-style 주석을 허용한다.
            config.handle_floats_manually = 0;

            JSON_parser parser = new_JSON_parser(&config);

            int line = 1;
            int column = 0;
            byte previous = '\0';
            for (;;)
            {
                byte current = '\0';
                if (stream->Read(&current, sizeof(current)) == sizeof(current))
                {
                    if (JSON_parser_char(parser, current) == 0)
                        throw JSONParsingError(JSON_parser_get_last_error(parser), filename, line, column);

                    column++;
                    if (current == '\n' || previous == '\r')
                    {
                        // '\n', '\r', '\r\n'
                        column = 0;
                        line++;
                    }

                    previous = current;
                }
                else
                    break;
            }

            if (JSON_parser_done(parser) == 0)
                throw JSONParsingError(JSON_parser_get_last_error(parser), filename, line, column);

            delete_JSON_parser(parser);

            HKAssert(context.Nodes.empty());

            this->root = context.Root;

            reloaded.Emit(this);
        }

        JSONObjectPtr JSONDocument::GetRoot()
        {
            if (sourceChanged)
            {
                sourceChanged = false;
                Reload();
            }

            return root;
        }

        const String& JSONDocument::GetFilename() const
        {
            return filename;
        }

        void JSONDocument::SetFilename(const String& value)
        {
            if (GetFilename().EqualsIgnoreCase(value) == false)
            {
                filename = value;
                sourceChanged = true;
            }
        }

        Signal<JSONDocument*>& JSONDocument::Reloaded()
        {
            return reloaded;
        }

        ////////////////////////////////////////////////////////////////////////////////////////////////////

        static inline const char* JSONParsingErrorToString(int error)
        {
            switch (error)
            {
                case JSON_E_NONE:
                    return "JSON.Error.Unknown";
                case JSON_E_INVALID_CHAR:
                    return "JSON.Error.InvalidCharacter";
                case JSON_E_INVALID_KEYWORD:
                    return "JSON.Error.InvalidKeyword";
                case JSON_E_INVALID_ESCAPE_SEQUENCE:
                    return "JSON.Error.InvalidEscapeSequence";
                case JSON_E_INVALID_UNICODE_SEQUENCE:
                    return "JSON.Error.InvalidUnicodeSequence";
                case JSON_E_INVALID_NUMBER:
                    return "JSON.Error.InvalidNumber";
                case JSON_E_NESTING_DEPTH_REACHED:
                    return "JSON.Error.NestingDepthReached";
                case JSON_E_UNBALANCED_COLLECTION:
                    return "JSON.Error.UnbalancedCollection";
                case JSON_E_EXPECTED_KEY:
                    return "JSON.Error.ExpectedKey";
                case JSON_E_EXPECTED_COLON:
                    return "JSON.Error.Colon";
                case JSON_E_OUT_OF_MEMORY:
                    return "JSON.Error.OufOfMemory";
                default:
                    return "JSON.Error.Unknown";
            }
        }

        JSONParsingError::JSONParsingError(int errorCode, const String& filename, int line, int column)
            : Exception(JSONParsingErrorToString(errorCode)),
              Filename(filename),
              Line(line),
              Column(column)
        {
        }

        JSONParsingError::JSONParsingError(const JSONParsingError& original)
            : Exception(original),
              Filename(original.Filename),
              Line(original.Line),
              Column(original.Column)
        {
        }

        JSONParsingError::~JSONParsingError()
        {
        }
    }
}