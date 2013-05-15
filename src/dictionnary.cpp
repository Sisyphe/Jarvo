#include "dictionnary.h"
#include <algorithm>

Dictionnary::~Dictionnary()
{
    std::set<DictEntry*>::iterator t_words_it=m_known_words.begin();
    for(; t_words_it!=m_known_words.end(); ++t_words_it)
        delete *t_words_it;

    std::vector<Noun*>::iterator t_noun_it=m_nouns.begin();
    for(; t_noun_it!=m_nouns.end(); ++t_noun_it)
        delete *t_noun_it;

    std::vector<Adjective*>::iterator t_adjective_it=m_adjectives.begin();
    for(; t_adjective_it!=m_adjectives.end(); ++t_adjective_it)
        delete *t_adjective_it;
}

DictEntry* Dictionnary::getEntry(const std::string& n_str)
{
    DictEntry* t_entry;
    std::set<DictEntry*>::iterator t_found;
    t_found=std::find_if(m_known_words.begin(),m_known_words.end(),FindEntry(n_str));

    if(t_found!=m_known_words.end())
    {
        t_entry=*t_found;
    }
    else
    {
        t_entry=createNewEntry(n_str);
    }

    return t_entry;
}

DictEntry* Dictionnary::createNewEntry(const std::string& n_str)
{
    DictEntry* t_entry=new DictEntry;
    t_entry->str=n_str;
    t_entry->isPlural=false;
    t_entry->function=Word::SUBJECT;
    std::string t_str(n_str);

    unsigned int char_pos=t_str.size()-1;
    bool t_done=t_str.empty();

    while(!t_done)
    {
        switch(t_str[char_pos])
        {
            case 'j':
                t_entry->isPlural=true;
                t_str.erase(char_pos--);
                break;
            case 'n':
                t_entry->function=Word::ACCUSATIVE;
                t_str.erase(char_pos--);
                break;
            case 'o':
                t_entry->type=Word::NOUN;
                t_entry->index=m_nouns.size();
                m_nouns.push_back(new Noun(t_str));
                t_done=true;
                break;
            case 'a':
                t_entry->type=Word::ADJECTIVE;
                t_entry->index=m_adjectives.size();
                m_adjectives.push_back(new Adjective(t_str));
                t_done=true;
                break;
        }
    }

    m_known_words.insert(t_entry);

    return t_entry;
}

Noun* Dictionnary::getNoun(DictEntry* n_entry)
{
    return new Noun(*m_nouns.at(n_entry->index));
}

Adjective* Dictionnary::getAdjective(DictEntry* n_entry)
{
    return new Adjective(*m_adjectives.at(n_entry->index));
}
