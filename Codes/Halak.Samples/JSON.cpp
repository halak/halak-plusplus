#include <Halak.Samples/Samples.h>
#include <Halak/JSONDocument.h>
#include <iostream>

void Halak::Samples::JSONSample(const std::vector<const char*>& /*args*/)
{
    try
    {
        JSONDocumentPtr json(new JSONDocument("TEST1.json"));
        json->GetRoot();
    }
    catch (const JSONParsingError& e)
    {
        std::cout << "What : " << e.what() << std::endl;
        std::cout << "Line : " << e.Line << std::endl;
        std::cout << "Column : " << e.Column  << std::endl;
    }
}