#ifndef WORDGROUPLIST_H
#define WORDGROUPLIST_H

#include "noungroup.h"
#include "adjectivegroup.h"
#include "adverbgroup.h"
#include "verbgroup.h"
#include <list>

class WordGroupList
{

    enum WordGroupType
    {
        NOUN,
        VERB,
        ADVERB,
        ADJECTIVE
    };

    public:

        WordGroupList(const std::vector< Word* >& n_words);
        void regroupWords();

    protected:

        std::list<WordGroupType> m_groups;
        std::list<std::pair<int, NounGroup> > m_nouns;
        std::list<std::pair<int, AdjectiveGroup> > m_adjectives;
        std::list<std::pair<int, AdverbGroup> > m_adverbs;
        std::list<std::pair<int, VerbGroup> > m_verbs;

};

#endif // WORDGROUPLIST_H
