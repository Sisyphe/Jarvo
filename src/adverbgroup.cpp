#include "adverbgroup.h"
#include"noungroup.h"

AdverbGroup::AdverbGroup(){}

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
