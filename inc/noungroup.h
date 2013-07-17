#ifndef NOUNGROUP_H
#define NOUNGROUP_H

#include "wordgroup.h"

class NounGroup: public WordGroup
{
    public:

        NounGroup();

        virtual bool addWord(Word* n_word);

        Word* noun;
        bool is_defined;
        bool is_entity;
        std::vector<Word*> adjectives;
        std::vector<std::pair<Word*,WordGroup*> > complements;
};

#endif // NOUNGROUP_H
