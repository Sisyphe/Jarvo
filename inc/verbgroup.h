#ifndef VERBGROUP_H
#define VERBGROUP_H

#include "wordgroup.h"
#include <vector>

class VerbGroup: public WordGroup
{
    public:

        VerbGroup();

        virtual bool addWord(Word* n_word);
        std::vector<std::string> getAdjectiveStrings() const;
        std::vector<std::string> getAdverbStrings() const;

        Word* verb;
        std::vector<Word*> adverbs;
        std::vector<Word*> adjectives;
};

#endif // VERBGROUP_H
