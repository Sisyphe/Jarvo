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

    jarvo.dumpBrain();

    return 0;
}
