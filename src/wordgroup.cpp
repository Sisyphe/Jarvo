#include "wordgroup.h"

WordGroup::WordGroup():
    m_main_word(0),
    m_preposition(0){}

WordGroup::~WordGroup(){}

Word* WordGroup::mainWord() const
{
    return m_main_word;
}

Word* WordGroup::preposition() const
{
    return m_preposition;
}

std::vector<VerbGroup*> WordGroup::verbComplements() const
{
    return m_verbs;
}

std::vector<AdjectiveGroup*> WordGroup::adjectiveComplements() const
{
    return m_adjectives;
}

std::vector<AdverbGroup*> WordGroup::adverbComplements() const
{
    return m_adverbs;
}

std::vector<NounGroup*> WordGroup::nounComplements() const
{
    return m_nouns;
}

void WordGroup::addVerbComplement(VerbGroup* n_verb_group)
{
    m_verbs.push_back(n_verb_group);
}

void WordGroup::addAdjectiveComplement(AdjectiveGroup* n_adj_group)
{
    m_adjectives.push_back(n_adj_group);
}

void WordGroup::addAdverbComplement(AdverbGroup* n_adv_group)
{
    m_adverbs.push_back(n_adv_group);
}

void WordGroup::addNounComplement(NounGroup* n_noun_group)
{
    m_nouns.push_back(n_noun_group);
}
/*
std::string WordGroup::getStr(const std::vector<WordGroup*>& n_groups)
{
    std::string str;
    std::vector<WordGroup*>::const_iterator it = n_groups.begin();

    for(; it != n_groups.end(); ++it)
    {
        str += (*it)->str() + " ";
    }

    return str;
}*/
