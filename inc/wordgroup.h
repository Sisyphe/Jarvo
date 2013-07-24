#ifndef WORDGROUP_H
#define WORDGROUP_H

#include "word.h"
#include <vector>
#include <string>

class WordGroup
{
    public:

        WordGroup();
        virtual ~WordGroup();

        bool isEmpty() const;
        virtual std::string str() const;

        bool operator==(const WordGroup& other);

    protected:

        std::vector<Word*> m_word_list;
};

#endif // WORDGROUP_H
