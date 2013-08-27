#include "verbgroup.h"

VerbGroup::VerbGroup(){}

std::string VerbGroup::str() const
{
    std::string t_str;
    std::vector<WordGroup> t_adverbs, t_nouns;
    std::vector<WordGroup>::const_iterator t_group = m_complements.begin();

    for(; t_group != m_complements.end(); ++t_group)
    {
        switch(t_group->type())
        {
            case WordGroup::NOUN:
                t_nouns.push_back(*t_group);
                break;
            case WordGroup::ADVERB:
                t_adverbs.push_back(*t_group);
                break;
            default: break;
        }
    }

    if(m_main_word)
    {
        if(m_preposition) t_str += m_preposition->str_base + " ";
        t_str += m_main_word->str_base + " ";
        t_str += getStr(t_adverbs);
        t_str += t_nouns.back().mainWord()->str;
        t_str.erase(t_str.end()-1);
    }

    return t_str;
}
