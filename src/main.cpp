#include <iostream>
#include "jarvo.h"

int main()
{
    Jarvo jarvo;

    jarvo.feed("La papagoj estas birdoj.");
    jarvo.feed("La birdoj estas bestoj.");
    jarvo.feed("Kato estas besto.");
    jarvo.feed("Kato mangxas birdon.");
    jarvo.feed("Mi havas vin.");
    jarvo.feed("Vi estas komputilo.");
    jarvo.feed("Vi parolas Esperanton.");
    jarvo.feed("Komputilo estas masxino.");
    jarvo.feed("Cxu mi havas masxino ?");
    jarvo.feed("Cxu papago estas birdo ?");
    jarvo.feed("Cxu papago estas besto ?");
    jarvo.feed("Cxu papago mangxas katon ?");
    jarvo.feed("Cxu kato mangxas beston ?");
    jarvo.feed("Cxu martigno havas komputilon ?");

    std::string n_str;

    while(n_str!="quit")
    {
        n_str.erase();
        std::cout << "Prompt: ";
        getline(std::cin, n_str);
        jarvo.feed(n_str);
    }

    jarvo.dumpBrain();

    return 0;
}
