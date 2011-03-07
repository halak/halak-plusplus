#include <Halak.Samples/Samples.h>
#include <Halak/Any.h>
#include <Halak/Vector2.h>
#include <iostream>
#include <memory>
using Halak::Any;
using Halak::Vector2;
using std::cout; 
using std::endl;

void Halak::Samples::AnySample(const std::vector<const char*>& /*args*/)
{
    Any v1 = 10;
    Any v2 = 10.0f;

//  double d2 = v1.CastTo<double>();

    cout << std::boolalpha;
    cout << (v1.GetType() == Any::IntType) << endl;
    cout << (v2.GetType() == Any::FloatType) << endl;

    Any v3 = Any::Null;
    {
        std::tr1::shared_ptr<int> sp1(new int(24));
        std::tr1::shared_ptr<int> sp2(sp1);

        cout << "sp1 shared_count: " << sp1.use_count() << endl;
        
        v3 = sp1;

        cout << "sp1 shared_count: " << sp1.use_count() << endl;
    }

    std::tr1::shared_ptr<int> sp3 = v3.CastTo<std::tr1::shared_ptr<int>>();
    cout << "v3 shared_count: " << sp3.use_count() << endl;

    Any v4 = Vector2(1.0f, 2.0f);
    Any v5 = v4;

    int q = 10;
    const int& w = q;
    Any v6 = w;
}