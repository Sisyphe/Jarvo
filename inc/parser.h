#ifndef PARSER_H
#define PARSER_H

#include "dictionnary.h"

class Parser
{
        static void parse(const std::string& n_str);

    protected:

        Dictionnary m_dict;
};

#endif // PARSER_H
