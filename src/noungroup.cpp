#include "noungroup.h"

NounGroup::NounGroup():
    m_noun(0),
    m_preposition(0),
    m_is_determinate(false){}

std::string NounGroup::str() const
{
    std::stringstream stream;
    std::vector<AdjectiveGroup>::iterator adj_it = m_adjectives.begin();
    std::vector<AdverbGroup>::iterator adv_it = m_adverbs.begin();
    std::vector<NounGroup>::iterator noun_it = m_nouns.begin();

    if(m_noun)
    {
        if(m_preposition) stream << m_preposition->str_base;

        for(; adj_it != m_adjectives.end(); ++adj_it)
        {
            stream << (*adj_it).str() << " ";
        }

        for(; adv_it != m_adverbs.end(); ++adv_it)
        {
            stream << (*adv_it).str() << " ";
        }

        stream << m_noun->str_base << " ";

        for(; noun_it != m_noun.end(); ++noun_it)
        {
            stream << (*noun_it).str() << " ";
        }
    }

    return stream.str();
}

Word* NounGroup::noun() const
{
    return m_noun;
}

Word* NounGroup::preposition() const
{
    return m_preposition;
}

std::vector<AdjectiveGroup> NounGroup::adjectiveComplements() const
{
    return m_adjectives;
}

std::vector<AdverbGroup> NounGroup::adverbComplements() const
{
    return m_adverbs;
}

std::vector<NounGroup> NounGroup::nounComplements() const
{
    return m_nouns;
}

void NounGroup::addComplement(const AdjectiveGroup& n_adj_group)
{
    m_adjectives.push_back(n_adj_group);
}

void NounGroup::addComplement(const AdverbGroup& n_adv_group)
{
    m_adverbs.push_back(n_adv_group);
}

void NounGroup::addComplement(const NounGroup& n_noun_group)
{
    m_nouns.push_back(n_noun_group);
}
