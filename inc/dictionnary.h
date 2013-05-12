#ifndef DICTIONNARY_H
#define DICTIONNARY_H

#include <vector>
#include <set>
#include <map>
#include "word.h"
#include <node.h>

class Dictionnary
{
    public:

        Dictionnary();

        Word::Type getType(const std::string& n_str);

    protected:

        std::set<Name> m_names;
        std::set<Adjective> m_adjectives;
        //std::set<Verb> m_verbs;
        //std::set<Adverb> m_adverbs;
        //std::set<Preposition> m_prepositions;
        //std::set<Conjunction> m_conjunctions;

};

#endif // DICTIONNARY_H
