#ifndef NOUNGROUP_H
#define NOUNGROUP_H

#include "wordgroup.h"

class NounGroup: public WordGroup
{
    public:

        NounGroup();

        virtual bool addWord(Word* n_word);
        virtual std::string str() const;
        std::vector<std::string> getQualifierStrings() const;

        Word* noun;
        bool is_determinate;
        std::vector<Qualifier> qualifiers;
        std::vector<std::pair<Word*, WordGroup*> > complements;
};

#endif // NOUNGROUP_H
