#include "noungroup.h"
#include "adverbgroup.h"
#include "adjectivegroup.h"

NounGroup::NounGroup():
    is_determinate(false){}

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
