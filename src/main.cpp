#include <iostream>
#include "jarvo.h"

int main()
{
    Jarvo jarvo;

    //     jarvo.feed("Cxiu birdo estas bela.");
//     jarvo.feed("Kiki mangxas testulon.");
//     jarvo.feed("Kio mangxas la testulon ?");
        jarvo.feed("\"françois\" estas la \"prezidento de ISIBOT\"");
//     jarvo.feed("brain.dot estas dosiero.");
//     jarvo.feed("Kio estas dosiero ?");
//     jarvo.feed("Kato mangxas birdon.");
//     jarvo.feed("La birdo estas verda.");
//     jarvo.feed("Kiki estas malgranda testulo.");
//     jarvo.feed("Cxiu testulo estas verda.");
//     jarvo.feed("Granda testulo mangxas birdon.");
//     jarvo.feed("La malgranda testulo estas bela.");
//     jarvo.feed("Kiki estas testulo.");
//     jarvo.feed("La papago estas granda birdo.");
//     jarvo.feed("La papago mangxas belan birdon.");
//     jarvo.feed("Cxiu papago estas bela birdo.");
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
