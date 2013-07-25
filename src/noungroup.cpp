#include "noungroup.h"
#include "adverbgroup.h"
#include "adjectivegroup.h"

NounGroup::NounGroup():
    m_is_determinate(false){}


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
