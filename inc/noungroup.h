#ifndef NOUNGROUP_H
#define NOUNGROUP_H

#include "wordgroup.h"

class NounGroup: public WordGroup
{
    public:

        NounGroup();

        virtual std::string str() const;

        Word* noun() const;
        Word* preposition() const;

        std::vector<AdjectiveGroup> adjectiveComplements() const;
        std::vector<AdverbGroup> adverbComplements() const;
        std::vector<NounGroup> nounComplements() const;

        void addComplement(const AdjectiveGroup& n_adj_group);
        void addComplement(const AdverbGroup& n_adv_group);
        void addComplement(const NounGroup& n_noun_group);

    protected:

        Word* m_noun;
        Word* m_preposition;
        bool m_is_determinate;
        std::vector<NounGroup> m_nouns;
        std::vector<AdjectiveGroup> m_adjectives;
        std::vector<AdverbGroup> m_adverbs;
};

#endif // NOUNGROUP_H
