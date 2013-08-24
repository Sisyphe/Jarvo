#include "verbgroup.h"
#include "noungroup.h"
#include "adverbgroup.h"

VerbGroup::VerbGroup()
{
    m_type = WordGroup::VERB;
    m_adverb_post_grouping_priority = 1;
    m_verb_post_grouping_priority = 1;
    m_noun_post_grouping_priority = 0;
    m_adjective_post_grouping_priority = 0;
}

std::string VerbGroup::str() const
{
    std::string t_str;

    if(m_main_word)
    {
        if(m_preposition) t_str += m_preposition->str_base + " ";
        t_str += m_main_word->str_base + " ";
        t_str += getStr(m_adverbs);
        t_str += m_nouns.back()->mainWord()->str;
        t_str.erase(t_str.end()-1);
    }

    return t_str;
}

void VerbGroup::addAsComplementTo(WordGroup& n_group)
{
    n_group.addVerbComplement(*this);
}
