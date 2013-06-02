#include <iostream>
#include "jarvo.h"

int main()
{
    Jarvo jarvo;

    jarvo.feed("Papago estas birdo.");
    jarvo.feed("Birdo estas besto.");
    jarvo.feed("Kato estas besto.");
    jarvo.feed("Kato mangxas birdon.");
    jarvo.feed("Cxu kato estas birdo ?");
    jarvo.feed("Cxu papago estas besto ?");
    jarvo.feed("Cxu kato mangxas beston ?");

    jarvo.dumpBrain();

    return 0;
}
