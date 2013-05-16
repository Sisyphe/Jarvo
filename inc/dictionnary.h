#ifndef DICTIONNARY_H
#define DICTIONNARY_H

#include <vector>
#include <set>
#include "word.h"

struct FindEntry
{
    FindEntry(const std::string& n_str_to_find) : m_str_to_find(n_str_to_find){}

    bool operator()(Word* n_entry)
    {
        return n_entry->str==m_str_to_find;
    }

    std::string m_str_to_find;
};

class Dictionnary
{
    public:

        ~Dictionnary();

        Word* getEntry(const std::string& n_str);
        Word* createNewEntry(const std::string& n_str);

    protected:

        std::set<Word*> m_known_words;
};

#endif // DICTIONNARY_H
