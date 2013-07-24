#ifndef VERBGROUP_H
#define VERBGROUP_H

#include "wordgroup.h"
#include <vector>

class VerbGroup: public WordGroup
{
    public:

        VerbGroup();

        Word* verb() const;
        Word* preposition() const;

        std::vector<VerbGroup> verbComplements() const;
        std::vector<AdverbGroup> adverbComplements() const;
        std::vector<NounGroup> nounComplements() const;

        void addComplement(const VerbGroup& n_verb_group);
        void addComplement(const AdverbGroup& n_adv_group);
        void addComplement(const NounGroup& n_noun_group);

    protected:

        Word* m_verb;
        Word* m_preposition;
        std::vector<AdverbGroup> m_adverbs;
        std::vector<VerbGroup> m_verbs;
        std::vector<NounGroup> m_nouns;
};

#endif // VERBGROUP_H
