#include <Halak.Samples/Samples.h>
#include <Halak/Signal.h>
#include <iostream>

class A
{
    public:
        void TEST1(int v, int, int, int, int)
        {
            std::cout << "A::TEST1(" << v << ")" << std::endl;
        }

        void TEST2(int v, int, int, int, int) const
        {
            std::cout << "A::TEST2(" << v << ")" << std::endl;
        }
};

void TEST1(int v, int, int, int, int)
{
    std::cout << "TEST1(" << v << ")" << std::endl;
}

void TEST2(int v, int, int, int, int)
{
    std::cout << "TEST2(" << v << ")" << std::endl;
}

void Halak::Samples::SignalSample(const std::vector<const char*>& /*args*/)
{
    shared_ptr<A> a(new A());
    shared_ptr<A> b = a;
    A* c = new A();

    {
    Signal<int, int, int, int, int> signal;
    signal.Connect(&TEST1);
    signal.Connect(&TEST2);
    signal.Connect(a, &A::TEST1);
    signal.Connect(a, &A::TEST2);
    signal.Connect(c, &A::TEST2);
    signal.Disconnect(a, &A::TEST1);
    signal.Disconnect(&TEST1);
    signal.Emit(12, 1, 2, 30, 20);
    }
}