#pragma once
#ifndef __HALAK_CLASSES_H__
#define __HALAK_CLASSES_H__

    namespace Halak
    {
#       define HKThisIsStaticClass(classname)   private: \
                                                    classname(); \
                                                    classname(const classname&); \
                                                    classname& operator = (const classname&); \
                                                    ~classname();
#       define HKThisIsNoncopyableClass(classname)  private: \
                                                        classname(const classname&); \
                                                        classname& operator = (const classname&);

#       define HKForwardDeclareSmartPointerClass(classname) class classname; \
                                                            typedef std::tr1::shared_ptr<classname> classname##Ptr; \
                                                            typedef std::tr1::weak_ptr<classname>   classname##WeakPtr;

#       define HKMakeFOURCC(a, b, c, d) ((static_cast<uint32>(a) << 24) | \
                                         (static_cast<uint32>(b) << 16) | \
                                         (static_cast<uint32>(c) << 8) | \
                                         (static_cast<uint32>(d) << 0))

#       define HKDeclareStruct(id) \
                    static const uint ClassID = id;
#       define HKDeclareStructFOURCC(a, b, c, d) HKDeclareStruct(HKMakeFOURCC(a, b, c, d))
#       define HKDeclareClass(id) \
                    public: \
                        static const uint ClassID = id; \
                    private:
#       define HKDeclareClassFOURCC(a, b, c, d) HKDeclareClass(HKMakeFOURCC(a, b, c, d))
    }

#endif