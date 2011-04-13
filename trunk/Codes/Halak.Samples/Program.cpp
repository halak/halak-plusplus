#include <Halak.Samples/Samples.h>
#include <Halak/Startup.h>
#include <crtdbg.h>
using namespace Halak;
using namespace Halak::Samples;

int main(int argc, const char** argv)
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    Startup();

    std::vector<const char*> args;
    args.reserve(argc);

    for (int i = 0; i < argc; i++)
        args.push_back(argv[i]);

    SequentialParticleSample(args);

    return 0;
}