#include <iostream>
#include "jarvo.h"

int main()
{
    Jarvo jarvo;

    jarvo.feed("papago estas birdo");
    jarvo.feed("birdo estas besto");
    jarvo.feed("kato estas besto");
    jarvo.feed("kato mangxas birdon");
    jarvo.feed("cxu kato estas birdo ?");
    jarvo.feed("cxu papago estas besto ?");

    jarvo.dumpBrain();

    return 0;
}
