#pragma once
#ifndef __HALAK_TOOLKIT_CHANGEPROPERTYCOMMAND_H__
#define __HALAK_TOOLKIT_CHANGEPROPERTYCOMMAND_H__

#   include <Halak.Toolkit/FWD.h>
#   include <Halak.Toolkit/AnyPtr.h>
#   include <Halak/RestorableCommand.h>
#   include <Halak/Any.h>

    namespace Halak
    {
        namespace Toolkit
        {
            class ChangePropertyCommand : public RestorableCommand
            {
                public:
                    ChangePropertyCommand(const AnyPtr& target, const PropertyInfo* propertyInfo, const Any& value);
                    virtual ~ChangePropertyCommand();

                    virtual void Execute();
                    virtual void Undo();

                    const AnyPtr& GetTargetPointee() const;
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
    }

#endif