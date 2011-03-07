#include <Halak.Samples/Samples.h>
#include <Halak/String.h>
#include <iostream>
using Halak::String;

void Halak::Samples::StringSample(const std::vector<const char*>& /*args*/)
{
    String a;
    String b = "";
    String c = "HelloWorld";
    String d = a;
    String e = c;

    //c[2] = 'L';
    //std::cout << e[2];

    //c += e;

    std::cout << std::boolalpha;
    std::cout << c.Contains(String("elloW")) << std::endl;
    std::cout << c.ContainsIgnoreCase("ellowe") << std::endl;
    std::cout << c.EndsWithIgnoreCase("erld") << std::endl;

    String q = c + e;

    c.Insert(2, e);
}