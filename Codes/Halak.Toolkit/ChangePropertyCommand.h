#pragma once
#ifndef __HALAK_CHANGEPROPERTYCOMMAND_H__
#define __HALAK_CHANGEPROPERTYCOMMAND_H__

#   include <Halak/FWD.h>
#   include <Halak/RestorableCommand.h>
#   include <Halak/ICloneable.h>
#   include <Halak/Any.h>
#   include <Halak/AnyPtr.h>

    namespace Halak
    {
        class ChangePropertyCommand : public RestorableCommand, public ICloneable
        {
            public:
                ChangePropertyCommand(const AnyPtr& target, const PropertyInfo* propertyInfo, const Any& value);
                ChangePropertyCommand(const ChangePropertyCommand& original, CloningContext& context);
                virtual ~ChangePropertyCommand();

                virtual ChangePropertyCommand* CloneWith(CloningContext& context) const;

                virtual void Execute();
                virtual void Undo();

                const AnyPtr& GetTarGetPointee() const;
                const PropertyInfo* GetPropertyInfo() const;
                const Any& GetOldValue() const;
                const Any& GetNewValue() const;

            private:
                AnyPtr target;
                const PropertyInfo* propertyInfo;
                Any newValue;
                Any oldValue;

            private:
                friend void __Startup__();
                static void __Startup__();
        };
    }

#endif