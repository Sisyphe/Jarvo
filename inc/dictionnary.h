#ifndef DICTIONNARY_H
#define DICTIONNARY_H

#include <vector>
#include <set>
#include "word.h"

struct FindEntry
{
    FindEntry
    (
        const std::string& n_str_to_find,
        bool n_search_base = false
    ):
        m_str_to_find(n_str_to_find),
        m_search_base(n_search_base)
    {
    }

    bool operator()(Word* n_entry)
    {
        if(m_search_base)
        {
            return n_entry->str_base == m_str_to_find;
        }
        else
        {
            return n_entry->str == m_str_to_find;
        }
    }

    std::string m_str_to_find;
    bool m_search_base;
};

class Dictionnary
{
    public:

        Dictionnary();
        ~Dictionnary();

        Word* getEntry(const std::string& n_str);
        Word* createNewEntry(const std::string& n_str);

    protected:

        std::set<Word*> m_known_words;
};

#endif // DICTIONNARY_H
