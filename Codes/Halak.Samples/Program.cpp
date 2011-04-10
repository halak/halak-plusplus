#include <Halak.Samples/Samples.h>
#include <Halak/Startup.h>
using namespace Halak;
using namespace Halak::Samples;

int main(int argc, const char** argv)
{
    Startup();

    std::vector<const char*> args;
    args.reserve(argc);

    for (int i = 0; i < argc; i++)
        args.push_back(argv[i]);

    SequentialParticleSample(args);

    return 0;
}