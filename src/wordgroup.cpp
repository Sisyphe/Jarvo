#include "wordgroup.h"
#include "adverbgroup.h"
#include "adjectivegroup.h"
#include "verbgroup.h"
#include "noungroup.h"

WordGroup::WordGroup():
    m_main_word(0),
    m_preposition(0){}

WordGroup::~WordGroup(){}

Word* WordGroup::mainWord() const
{
    return m_main_word;
}

void WordGroup::setMainWord(Word* n_main_word)
{
    m_main_word = n_main_word;
}

Word* WordGroup::preposition() const
{
    return m_preposition;
}

void WordGroup::setPreposition(Word* n_preposition)
{
    m_preposition = n_preposition;
}

const std::vector<VerbGroup*>& WordGroup::verbComplements() const
{
    return m_verbs;
}

const std::vector<AdjectiveGroup*>& WordGroup::adjectiveComplements() const
{
    return m_adjectives;
}

const std::vector<AdverbGroup*>& WordGroup::adverbComplements() const
{
    return m_adverbs;
}

const std::vector<NounGroup*>& WordGroup::nounComplements() const
{
    return m_nouns;
}

void WordGroup::addVerbComplement(const VerbGroup& n_verb_group)
{
    m_verbs.push_back(new VerbGroup(n_verb_group));
}

void WordGroup::addAdjectiveComplement(const AdjectiveGroup& n_adj_group)
{
    m_adjectives.push_back(new AdjectiveGroup(n_adj_group));
}

void WordGroup::addAdverbComplement(const AdverbGroup& n_adv_group)
{
    m_adverbs.push_back(new AdverbGroup(n_adv_group));
}

void WordGroup::addNounComplement(const NounGroup& n_noun_group)
{
    m_nouns.push_back(new NounGroup(n_noun_group));
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
