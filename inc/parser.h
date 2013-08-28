#ifndef PARSER_H
#define PARSER_H

#include "dictionnary.h"
#include "sentence.h"
#include <list>
#include <vector>

class Parser
{
    public:

        void parse(Sentence& n_sentence, const std::string& n_str);
        //void makeGroups(std::list<WordGroup*>& n_groups, const std::vector<Word*>& n_words);
        //void regroupWords(std::list<WordGroup*>& n_groups);

    protected:

        void getEntries(const std::vector<std::string>& n_raw_words, std::vector<Word*>& n_words);
        void extractRawWords(const std::string& n_str, std::vector< std::string >& n_raw_words) const;

        Dictionnary m_dict;
        bool m_success;
};

#endif // PARSER_H
