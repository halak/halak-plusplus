#include <Halak.Samples/Samples.h>
#include <Halak/GameComponent.h>
#include <Halak/GameNode.h>
#include <Halak/GameStructure.h>
using namespace Halak;

class TestService : public GameComponent
{
    public:
        TestService() { }
        TestService(uint id) : GameComponent(id) { }
        virtual ~TestService() { }
};

void Halak::Samples::GameComponentSample(const std::vector<const char*>& /*args*/)
{
    GameStructure map1;
    GameStructure map2;

    GameNode* node1 = map1.GetRoot()->AttachChild(new TestService(map1.GenerateID()));
    GameNode* node2 = map1.GetRoot()->AttachChild(new TestService(map1.GenerateID()));
    node1->GetComponent()->SetID(map1.GenerateID());
    map2.GetRoot()->AttachChild(node1);

    int
    x = 0;
    x = 0;
}