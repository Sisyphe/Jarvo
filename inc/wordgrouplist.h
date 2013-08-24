#ifndef WORDGROUPLIST_H
#define WORDGROUPLIST_H

#include "noungroup.h"
#include "adjectivegroup.h"
#include "adverbgroup.h"
#include "verbgroup.h"
#include <list>

class WordGroupList
{
    enum Grouping
    {
        NO_GROUPING,
        PRE_GROUPING,
        POST_GROUPING
    };

    public:

        WordGroupList(const std::vector<Word*>& n_words);
        void regroupWords();

    protected:
        std::list<WordGroup*> m_groups;
};

#endif // WORDGROUPLIST_H
