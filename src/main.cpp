#include <iostream>
#include "jarvo.h"

int main()
{
    Jarvo jarvo;

    jarvo.feed("Papago estas birdo.");
    jarvo.feed("Birdo estas besto.");
    jarvo.feed("Kato estas besto.");
    jarvo.feed("Kato mangxas birdon.");
    jarvo.feed("Mi havas vin.");
    jarvo.feed("Vi estas komputilo.");
    jarvo.feed("Cxu mi havas komputilon ?");
    jarvo.feed("Cxu kato estas birdo ?");
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
