#pragma once
#ifndef __HALAK_CLASSINFO_INL__
#define __HALAK_CLASSINFO_INL__

namespace Halak
{
    const ClassInfo* ClassInfo::GetBaseClass() const
    {
        if (baseClasses.empty() == false)
            return baseClasses.front();
        else
            return nullptr;
    }

    const ClassInfo::ClassCollection& ClassInfo::GetBaseClasses() const
    {
        return baseClasses;
    }

    const ClassInfo::ConstructorCollection& ClassInfo::GetConstructors() const
    {
        return constructors;
    }

    const ClassInfo::PropertyCollection& ClassInfo::GetProperties() const
    {
        return properties;
    }
}

#endif