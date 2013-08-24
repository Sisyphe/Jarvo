#include "noungroup.h"
#include "adverbgroup.h"
#include "adjectivegroup.h"

NounGroup::NounGroup():
    m_is_determinate(false)
{
    m_type = WordGroup::NOUN;
    m_adverb_pre_grouping_priority = 0;
    m_verb_pre_grouping_priority = 0;
    m_noun_pre_grouping_priority = 0;
    m_adjective_pre_grouping_priority = 2;
    m_adverb_post_grouping_priority = 0;
    m_verb_post_grouping_priority = 0;
    m_noun_post_grouping_priority = 1;
    m_adjective_post_grouping_priority = 1;
}


bool NounGroup::isDeterminate() const
{
    return m_is_determinate;
}

void NounGroup::setDeterminate(bool n_is_determinate)
{
    m_is_determinate = n_is_determinate;
}

std::string NounGroup::str() const
{
    std::string t_str;

    if(m_main_word)
    {
        if(m_preposition) t_str += m_preposition->str_base + " ";
        t_str += getStr(m_adjectives);
        t_str += getStr(m_adverbs);
        t_str += m_main_word->str_base + " ";
        t_str += getStr(m_nouns);
        t_str.erase(t_str.end()-1);
    }

    return t_str;
}

void NounGroup::addAsComplementTo(WordGroup& n_group)
{
    n_group.addNounComplement(*this);
}
