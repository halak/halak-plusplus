#include <Halak.Samples/Samples.h>
#include <Halak/Any.h>
#include <Halak/LuaRuntimeEnvironment.h>
using namespace Halak;

void Halak::Samples::LuaSample(const std::vector<const char*>& /*args*/)
{
    LuaRuntimeEnvironment* luaRE = new LuaRuntimeEnvironment();

    luaRE->Load("TEST1.lua");
    luaRE->Call<void>("Sum", 1, 2);
    std::tr1::tuple<int, int, Any> result = luaRE->Call<std::tr1::tuple<int, int, Any>>("Sum", 1, 2);

    delete luaRE;
}