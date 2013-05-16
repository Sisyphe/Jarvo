#include <iostream>
#include "parser.h"

int main()
{
    std::cout << "Hello World!" << std::endl;

    Parser parser;
    parser.parse("malgranda papagoj estas katoj");

    return 0;
}
