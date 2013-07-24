#include "adjectivegroup.h"
#include "adverbgroup.h"
#include "noungroup.h"
#include "verbgroup.h"

AdjectiveGroup::AdjectiveGroup(){}

std::string AdjectiveGroup::str() const
{
    std::string t_str;

    if(m_main_word)
    {
        t_str += getStr(m_adverbs);
        t_str += m_main_word->str_base + " ";
        t_str += getStr(m_verbs);
        t_str += getStr(m_nouns);
        t_str.erase(t_str.end()-1);
    }

    return t_str;
}
