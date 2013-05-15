#ifndef DICTIONNARY_H
#define DICTIONNARY_H

#include <vector>
#include <set>
#include <map>
#include "word.h"
#include "noun.h"
#include "adjective.h"
#include <node.h>

struct DictEntry
{
    std::string str;
    Word::Type type;
    Word::Function function;
    bool isPlural;
    unsigned int index;
};

struct FindEntry
{
    FindEntry(const std::string& n_str_to_find) : m_str_to_find(n_str_to_find){}

    bool operator()(DictEntry* n_entry)
    {
        return n_entry->str==m_str_to_find;
    }

    std::string m_str_to_find;
};

class Dictionnary
{
    public:

        ~Dictionnary();

        DictEntry* getEntry(const std::string& n_str);
        DictEntry* createNewEntry(const std::string& n_str);
        Noun* getNoun(DictEntry* n_entry);
        Adjective* getAdjective(DictEntry* n_entry);

    protected:

        std::set<DictEntry*> m_known_words;

        std::vector<Noun*> m_nouns;
        std::vector<Adjective*> m_adjectives;
        //std::set<Verb> m_verbs;
        //std::set<Adverb> m_adverbs;
        //std::set<Preposition> m_prepositions;
        //std::set<Conjunction> m_conjunctions;

};

#endif // DICTIONNARY_H
