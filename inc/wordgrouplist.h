#ifndef WORDGROUPLIST_H
#define WORDGROUPLIST_H

#include "wordgroup.h"
#include <list>

class WordGroupList
{
    public:

        static void makeGroups(const std::vector<Word*>& n_words, std::list<WordGroup>& n_groups);
        static void regroupWords(const std::vector<Word*>& n_words, std::list<WordGroup>& n_groups);
};

#endif // WORDGROUPLIST_H
