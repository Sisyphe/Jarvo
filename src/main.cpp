#include <iostream>
#include "jarvo.h"

int main()
{
    Jarvo jarvo;

    jarvo.feed("Papago estas bela birdo.");
    jarvo.feed("Birdo estas granda.");
//     jarvo.feed("La birdoj estas bestoj.");
//     jarvo.feed("La Katoj estas bestoj.");
//     jarvo.feed("Kato mangxas birdon.");
//     jarvo.feed("Cxu la papagoj estas birdoj ?");
//     jarvo.feed("Cxu papago estas besto ?");
//     jarvo.feed("Cxu papago mangxas katon ?");
//     jarvo.feed("Cxu kato mangxas beston ?");
//     jarvo.feed("Cxu la katoj mangxas la bestojn ?");

//     jarvo.feed("Mi havas vin.");
//    jarvo.feed("Vi estas komputilo.");
//    jarvo.feed("La Komputiloj estas masxinoj.");
//    jarvo.feed("Cxu mi havas masxino ?");
//    jarvo.feed("Cxu Noël havas komputilon ?");
//
//     jarvo.feed("brain.png estas dosiero.");
//     jarvo.feed("Apertu brain.png !");
//     jarvo.feed("brain.dot estas dosiero");
//     jarvo.feed("apertu brain.dot");
//     jarvo.feed("/home/sisyphe estas dosierujo.");
//     jarvo.feed("Apertu /home/sisyphe");
//     jarvo.feed("Diru \"Mi estas kreteno\"");
//     jarvo.feed("\"dolphin\" estas programo");
//     jarvo.feed("apertu \"dolphin\"");

    std::string n_str;
    std::cout << "Prompt: ";
    getline(std::cin, n_str);

    while(n_str!="quit")
    {
        jarvo.feed(n_str);
        n_str.erase();
        std::cout << "Prompt: ";
        getline(std::cin, n_str);
    }

    jarvo.dumpBrain();

    return 0;
}
