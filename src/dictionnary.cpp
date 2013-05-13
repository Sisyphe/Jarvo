#include "dictionnary.h"
#include <algorithm>

Dictionnary::Dictionnary()
{
}

DictEntry Dictionnary::getEntry(const std::string& n_str)
{
    DictEntry t_entry;
    std::set<DictEntry>::iterator t_found;
    t_found=find(m_known_words.begin(),m_known_words.end(),n_str);

    if(t_found!=m_known_words.end())
    {
        t_entry=*t_found;
        t_entry.found=true;
    }
    else t_entry.found=false;

    return t_entry;
}

Noun Dictionnary::getNoun(const DictEntry& n_entry)
{
    return m_nouns.at(n_entry.index);
}

Adjective Dictionnary::getAdjective(const DictEntry& n_entry)
{
    return m_adjectives.at(n_entry.index);
}
