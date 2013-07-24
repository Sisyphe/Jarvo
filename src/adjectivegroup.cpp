#include "adjectivegroup.h"

AdjectiveGroup::AdjectiveGroup(){}

AdjectiveGroup::str()
{
    std::stringstream stream;
    std::vector<VerbGroup>::iterator verb_it = m_verbs.begin();
    std::vector<AdverbGroup>::iterator adv_it = m_adverbs.begin();
    std::vector<NounGroup>::iterator noun_it = m_nouns.begin();

    if(m_adjective)
    {
        for(; adv_it != m_adverbs.end(); ++adv_it)
        {
            stream << (*adv_it).str() << " ";
        }

        stream << m_adjective << " ";

        for(; verb_it != m_verbs.end(); ++verb_it)
        {
            stream << (*verb_it).str() << " ";
        }

        for(; noun_it != m_nouns.end(); ++noun_it)
        {
            stream << (*noun_it).str() << " ";
        }
    }
}

Word* AdjectiveGroup::adjective() const
{
    return m_adjective;
}

std::vector<VerbGroup> AdjectiveGroup::verbComplements() const
{
    return m_verbs;
}

std::vector<AdverbGroup> AdjectiveGroup::adverbComplements() const
{
    return m_adverbs;
}

std::vector<NounGroup> AdjectiveGroup::nounComplements() const
{
    return m_nouns;
}

void AdjectiveGroup::addComplement(const VerbGroup& n_verb_group)
{
    m_verbs.push_back(n_verb_group);
}

void AdjectiveGroup::addComplement(const AdverbGroup& n_adv_group)
{
    m_adverbs.push_back(n_adv_group);
}

void AdjectiveGroup::addComplement(const NounGroup& n_noun_group)
{
    m_nouns.push_back(n_noun_group);
}

