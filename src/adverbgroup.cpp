#include "adverbgroup.h"
#include"noungroup.h"

AdverbGroup::AdverbGroup()
{
    m_type = WordGroup::ADVERB;
    m_adverb_pre_grouping_priority = 1;
    m_verb_pre_grouping_priority = 0;
    m_noun_pre_grouping_priority = 0;
    m_adjective_pre_grouping_priority = 0;
    m_adverb_post_grouping_priority = 0;
    m_verb_post_grouping_priority = 0;
    m_noun_post_grouping_priority = 1;
    m_adjective_post_grouping_priority = 0;
}

std::string AdverbGroup::str() const
{
    std::string t_str;

    if(m_main_word)
    {
        t_str += getStr(m_adverbs);
        t_str += m_main_word->str_base + " ";
        t_str += getStr(m_nouns);
        t_str.erase(t_str.end()-1);
    }

    return t_str;
}

void AdverbGroup::addAsComplementTo(WordGroup& n_group)
{
    n_group.addAdverbComplement(*this);
}
