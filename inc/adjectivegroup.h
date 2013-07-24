#ifndef ADJECTIVEGROUP_H
#define ADJECTIVEGROUP_H

#include "wordgroup.h"

class AdjectiveGroup: public WordGroup
{
    public:

        AdjectiveGroup();

        virtual std::string str();

        Word* adjective() const;

        std::vector<VerbGroup> verbComplements() const;
        std::vector<AdverbGroup> adverbComplements() const;
        std::vector<NounGroup> nounComplements() const;

        void addComplement(const VerbGroup& n_verb_group);
        void addComplement(const AdverbGroup& n_adv_group);
        void addComplement(const NounGroup& n_noun_group);

    protected:

        Word* m_adjective;
        std::vector<AdverbGroup> m_adverbs;
        std::vector<VerbGroup> m_verbs;
        std::vector<NounGroup> m_nouns;
};

#endif // ADJECTIVEGROUP_H
