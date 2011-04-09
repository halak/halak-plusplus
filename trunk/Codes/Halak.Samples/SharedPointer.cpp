#include <Halak.Samples/Samples.h>
#include <Halak/SharedObject.h>
#include <Halak/SharedPointer.h>
#include <iostream>
#include <vector>
#include <stack>
using Halak::SharedObject;
using Halak::SharedPointer;
using std::cout;

class A : public SharedObject
{
    public:
        A() { }
        virtual ~A()
        {
            int i = 0;
            i = 0;
        }

        void C()
        {
            int i = 0;
            i = 0;
        }
};

void Halak::Samples::SharedPointerSample(const std::vector<const char*>& /*args*/)
{
    SharedPointer<A> i = new A();
    SharedPointer<A> s = i;

    std::vector<SharedPointer<A>> v;
    v.push_back(i);
    v.push_back(s);

    std::stack<SharedPointer<A>> stack;
    stack.push(new A());
    stack.top()->C();

    int a = 0;
    a = 0;
}