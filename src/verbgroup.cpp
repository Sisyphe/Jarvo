#include "verbgroup.h"

VerbGroup::VerbGroup():
    m_verb(0),
    m_preposition(0){}

std::string VerbGroup::str()
{
    std::stringstream stream;
    std::vector<VerbGroup>::iterator verb_it = m_verbs.begin();
    std::vector<AdverbGroup>::iterator adv_it = m_adverbs.begin();
    std::vector<NounGroup>::iterator noun_it = m_nouns.begin();

    if(m_verb)
    {
        if(m_preposition) stream << m_preposition->str_base;

        for(; adv_it != m_adverbs.end(); ++adv_it)
        {
            stream << (*adv_it).str() << " ";
        }

        stream << m_verb << " ";

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

Word* VerbGroup::verb() const
{
    return m_verb;
}

Word* VerbGroup::preposition() const
{
    return m_preposition;
}

std::vector<VerbGroup> VerbGroup::verbComplements() const
{
    return m_verbs;
}

std::vector<AdverbGroup> VerbGroup::adverbComplements() const
{
    return m_adverbs;
}

std::vector<NounGroup> VerbGroup::nounComplements() const
{
    return m_nouns;
}

void VerbGroup::addComplement(const VerbGroup& n_verb_group)
{
    m_verbs.push_back(n_verb_group);
}

void VerbGroup::addComplement(const AdverbGroup& n_adv_group)
{
    m_adverbs.push_back(n_adv_group);
}

void VerbGroup::addComplement(const NounGroup& n_noun_group)
{
    m_nouns.push_back(n_noun_group);
}

