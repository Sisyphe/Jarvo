#ifndef WORDGROUP_H
#define WORDGROUP_H

#include "word.h"
#include <vector>
#include <string>

struct Qualifier
{
    Qualifier(Word* n_adjective):
        adverb(0),
        adjective(n_adjective){}

    Qualifier(Word* n_adverb, Word* n_adjective):
        adverb(n_adverb),
        adjective(n_adjective){}

    Word* adverb;
    Word* adjective;
};

class WordGroup
{
    public:

        WordGroup();
        virtual ~WordGroup();

        virtual bool addWord(Word* n_word);
        bool isEmpty() const;
        virtual std::string str() const;

        bool operator==(const WordGroup& other);

    protected:

        std::vector<Word*> m_word_list;
};

#endif // WORDGROUP_H
