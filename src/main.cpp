#include <iostream>
#include "parser.h"

int main()
{
    std::cout << "Hello World!" << std::endl;

    Parser parser;
    parser.parse("malgrandaj papagoj katojn");

    return 0;
}
