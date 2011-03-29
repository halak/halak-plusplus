//#include <Halak.Samples/Samples.h>
//#include <Halak/ClassInfo.h>
//#include <Halak/DynamicCast.h>
//#include <Halak/ConstructorInfo.h>
//#include <Halak/InstanceInfo.h>
//#include <Halak/PropertyInfo.h>
//#include <Halak/RegistrationContexts.h>
//#include <Halak/Startup.h>
//#include <Halak/TypeLibrary.h>
//#include <Halak/Vector2.h>
//using namespace Halak;
//
//class ClassA
//{
//    public:
//        ClassA()
//            : x(1), y(2), z(3), w(4)
//        {
//        }
//        virtual ~ClassA() { }
//
//        int GetX() const
//        {
//            return x;
//        }
//
//        void SetX(int value)
//        {
//            x = value;
//        }
//
//    public:
//        int x;
//        int y;
//        int z;
//        int w;
//};
//
//class ClassB
//{
//    public:
//        ClassB()
//            : a(5), b(6), c(7)
//        {
//        }
//        virtual ~ClassB() { }
//
//        int GetA() const
//        {
//            return a;
//        }
//
//        void SetA(int value)
//        {
//            a = value;
//        }
//
//    public:
//        int a;
//        int b;
//        int c;
//};
//
//class ClassE
//{
//    public:
//        ClassE()
//            : a(5), b(6), c(7)
//        {
//        }
//        virtual ~ClassE() { }
//
//    public:
//        int a;
//        int b;
//        int c;
//};
//
//class ClassC : public ClassA, public ClassB, public ClassE
//{
//    public:
//        virtual ~ClassC() { }
//};
//
//class ClassD
//{
//    public:
//        ClassD()
//            : i(0), j(0), k(0)
//        {
//        }
//
//        int  GetI() const    { return i;  }
//        void SetI(int value) { i = value; }
//        int  GetJ() const    { return j;  }
//        void SetJ(int value) { k = value; }
//        int  GetK() const    { return k;  }
//        void SetK(int value) { j = value; }
//
//    private:
//        int i;
//        int j;
//        int k;
//};
//
//void Halak::Samples::ReflectionSample(const std::vector<const char*>& /*args*/)
//{
//    Class<ClassC>()
//        .Inherits<ClassA>()
//        .Inherits<ClassB>()
//        .Inherits<ClassE>();
//
//    const ClassInfo* ci = static_cast<const ClassInfo*>(TypeLibrary::GetInstance().GetType<ClassB>());
//
//    ClassC* i1 = new ClassC();
//    ClassA* i2 = dynamic_cast<ClassA*>(i1);
//    ClassB* i3 = dynamic_cast<ClassB*>(i2);
//    ClassB* i4 = (ClassB*)DynamicCast(ci, i2);
//
//    i1->SetA(10);
//
//    PropertyInfo propX(0, "X", &ClassA::GetX, &ClassA::SetX);
//    PropertyInfo propk(0, "K", &ClassD::GetI, &ClassD::SetI);
//
//    propX.SetValue(i3, 10);
//    int v1 = propX.GetValue<int>(i2);
//    v1 = v1;
//
//    ClassD d;
//    propk.SetValue(&d, 10);
//    int v2 = propk.GetValue<int>(&d);
//    v2 = v2;
//}