#ifndef WORDGROUPLIST_H
#define WORDGROUPLIST_H

#include "wordgroup.h"
#include <list>

class WordGroupList
{
    public:

        WordGroupList(const std::vector<Word*>& n_words);
        void regroupWords();

    protected:
        std::list<WordGroup> m_groups;
};

#endif // WORDGROUPLIST_H