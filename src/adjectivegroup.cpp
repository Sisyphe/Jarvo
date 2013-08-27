#include "adjectivegroup.h"
#include "adverbgroup.h"
#include "noungroup.h"
#include "verbgroup.h"

AdjectiveGroup::AdjectiveGroup(){}

std::string AdjectiveGroup::str() const
{
    std::string t_str;
    std::vector<WordGroup> t_verbs, t_adverbs, t_nouns;
    std::vector<WordGroup>::const_iterator t_group = m_complements.begin();

    for(; t_group != m_complements.end(); ++t_group)
    {
        switch(t_group->type())
        {
            case WordGroup::VERB:
                t_verbs.push_back(*t_group);
                break;
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
        t_str += getStr(t_adverbs);
        t_str += m_main_word->str_base + " ";
        t_str += getStr(t_verbs);
        t_str += getStr(t_nouns);
        t_str.erase(t_str.end()-1);
    }

    return t_str;
}
