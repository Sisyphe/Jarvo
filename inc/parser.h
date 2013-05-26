#ifndef PARSER_H
#define PARSER_H

#include "dictionnary.h"
#include "sentence.h"

class Parser
{
    public:

        void parse(Sentence& n_sentence, const std::string& n_str);

        void extractRawWords
        (
            const std::string& n_str,
            std::vector<std::string>& n_raw_words
        ) const;

    protected:

        Dictionnary m_dict;
};

#endif // PARSER_H
