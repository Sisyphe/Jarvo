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
    bool found;

    bool operator==(const std::string& n_str) const
    {
        return str==n_str;
    }

    bool operator==(const DictEntry& n_entry) const
    {
        return (str==n_entry.str && type==n_entry.type);
    }
};

class Dictionnary
{
    public:

        Dictionnary();

        DictEntry getEntry(const std::string& n_str);
        Noun getNoun(const DictEntry& n_entry);
        Adjective getAdjective(const DictEntry& n_entry);

    protected:

        std::set<DictEntry> m_known_words;

        std::vector<Noun> m_nouns;
        std::vector<Adjective> m_adjectives;
        //std::set<Verb> m_verbs;
        //std::set<Adverb> m_adverbs;
        //std::set<Preposition> m_prepositions;
        //std::set<Conjunction> m_conjunctions;

};

#endif // DICTIONNARY_H
