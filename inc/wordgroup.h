#ifndef WORDGROUP_H
#define WORDGROUP_H

#include "word.h"
#include <vector>

class WordGroup
{
    public:

        WordGroup();
        virtual ~WordGroup();

        virtual bool addWord(Word* n_word);
        bool isEmpty() const;

        bool operator==(const WordGroup& other);

    protected:

        std::vector<Word*> m_word_list;
};

#endif // WORDGROUP_H
