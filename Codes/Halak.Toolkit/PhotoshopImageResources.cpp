#include <Halak.Toolkit/PCH.h>
#include <Halak.Toolkit/PhotoshopImageResources.h>
#include <Halak.Toolkit/PhotoshopDocumentReader.h>

namespace Halak
{
    namespace Toolkit
    {
        PhotoshopImageResource::CreationDictionary PhotoshopImageResource::imageResourceMap;

        PhotoshopImageResource::PhotoshopImageResource(Type type, const String& name)
            : type(type),
              name(name)
        {
        }

        PhotoshopImageResource::~PhotoshopImageResource()
        {
        }

        template <typename T> PhotoshopImageResourcePtr PhotoshopImageResource::NewImageResource(Type type, const String& name, unsigned int size, PhotoshopDocumentReader& reader)
        {
            return PhotoshopImageResourcePtr(new T(type, name, size, reader));
        }

        PhotoshopImageResourcePtr PhotoshopImageResource::Create(Type type, const String& name, unsigned int size, PhotoshopDocumentReader& reader)
        {
            if (imageResourceMap.empty())
            {
                imageResourceMap[PhotoshopImageResource::ResolutionInfo]    = &NewImageResource<PhotoshopResolutionInfo>;
                imageResourceMap[PhotoshopImageResource::AlphaChannelNames] = &NewImageResource<PhotoshopAlphaChannelNames>;
            }

            CreationDictionary::const_iterator it = imageResourceMap.find(type);
            if (it != imageResourceMap.end())
                return PhotoshopImageResourcePtr((*(*it).second)(type, name, size, reader));
            else
                return nullptr;
        }

        ////////////////////////////////////////////////////////////////////////////////////////////////////

        PhotoshopResolutionInfo::PhotoshopResolutionInfo(Type type, const String& name, unsigned int /*size*/, PhotoshopDocumentReader& reader)
            : PhotoshopImageResource(type, name)
        {
            horizontalResolution = reader.ReadInt16();
            horizontalResolutionUnit = (ResolutionUnit)reader.ReadInt32();
            widthUnit = (Unit)reader.ReadInt16();

            verticalResolution = reader.ReadInt16();
            verticalResolutionUnit = (ResolutionUnit)reader.ReadInt32();
            heightUnit = (Unit)reader.ReadInt16();
        }
        
        PhotoshopResolutionInfo::~PhotoshopResolutionInfo()
        {
        }

        short PhotoshopResolutionInfo::GetHorizontalResolution() const
        {
            return horizontalResolution;
        }

        short PhotoshopResolutionInfo::GetVerticalResolution() const
        {
            return verticalResolution;
        }

        PhotoshopResolutionInfo::ResolutionUnit PhotoshopResolutionInfo::GetHorizontalResolutionUnit() const
        {
            return horizontalResolutionUnit;
        }

        PhotoshopResolutionInfo::ResolutionUnit PhotoshopResolutionInfo::GetVerticalResolutionUnit() const
        {
            return verticalResolutionUnit;
        }

        PhotoshopResolutionInfo::Unit PhotoshopResolutionInfo::GetWidthUnit() const
        {
            return widthUnit;
        }

        PhotoshopResolutionInfo::Unit PhotoshopResolutionInfo::GetHeightUnit() const
        {
            return heightUnit;
        }

        ////////////////////////////////////////////////////////////////////////////////////////////////////

        PhotoshopAlphaChannelNames::PhotoshopAlphaChannelNames(Type type, const String& name, unsigned int size, PhotoshopDocumentReader& reader)
            : PhotoshopImageResource(type, name)
        {
            const unsigned int endPosition = reader.GetPosition() + size;
            while (reader.GetPosition() < endPosition)
            {
                const String name = reader.ReadPSDString();
                if (name != String::Empty)
                    names.push_back(name);
            }
        }

        PhotoshopAlphaChannelNames::~PhotoshopAlphaChannelNames()
        {
        }

        const std::vector<String>& PhotoshopAlphaChannelNames::GetNames() const
        {
            return names;
        }
    }
}