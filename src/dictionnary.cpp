#include "dictionnary.h"
#include <algorithm>

Dictionnary::Dictionnary()
{
}

Name* Dictionnary::getName(const std::string& n_str)
{
    std::set<Name>::iterator t_found;
    t_found=find(m_names.begin(),m_names.end(),t_str);

    if(t_found!=m_names.end())
        return &(*t_found);
    else
        return 0;
}

Adjective* Dictionnary::getAdjective(const std::string& n_str)
{
    std::set<Adjective>::iterator t_found;
    t_found=find(m_adjectives.begin(),m_adjectives.end(),t_str);

    if(t_found!=m_adjectives.end())
        return &(*t_found);
    else
        return 0;
}
