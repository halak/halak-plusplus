#pragma once
#ifndef __HALAK_CLASSES_H__
#define __HALAK_CLASSES_H__

    namespace Halak
    {
#       define HKClasses(Struct, Class, ReferenceClass, Interface, TemplateStruct1, TemplateClass1) \
            /* 01. Foundation */ \
                /* (BasicTypes) */ \
                    Struct(Color) \
                    Struct(Matrix4) \
                    Struct(Point) \
                    Struct(Quaternion) \
                    TemplateStruct1(typename T, Range) \
                    Struct(Ray) \
                    Struct(Ray2D) \
                    Struct(Rectangle) \
                    Class(String) \
                    Struct(UUID) \
                    Struct(Vector2) \
                    Struct(Vector3) \
                    Struct(Vector4) \
                /* (SmartPointers) */ \
                    ReferenceClass(SharedObject) \
                    TemplateClass1(typename T, SharedPointer) \
                    TemplateClass1(typename T, WeakPointer) \
                /* Any */ \
                    Class(Any) \
                    Class(AnyPtr) \
                /* Disposal */ \
                    Class(GarbageMan) \
                    Interface(IDisposable) \
                /* Exceptions */ \
                    Class(Exception) \
                        Class(BadCastException) \
                        Class(OutOfRangeException) \
                /* Time */ \
                    Class(Clock) \
                    Class(GlobalClock) \
                    Interface(IUpdateable) \
                    Class(Timeline) \
                        Class(ParallelTimeline) \
                        Class(SubTimeline)
            //Class() \
            //ReferenceClass() \
            //Interface()

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