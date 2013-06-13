#ifndef WORD_H
#define WORD_H

#include <string>
#include "node.h"
#include "linkgraph.h"

class Word
{
    public:

        enum Type
        {
            UNKNOWN_TYPE,
            NOUN,
            VERB,
            ADJECTIVE,
            CONJUNCTION,
            PREPOSITION,
            ADVERB,
            PRONOUN,
            ARTICLE
        };

        enum Case
        {
            NO_CASE,
            SUBJECT,
            ACCUSATIVE // Object case
        };

        enum Tense // Stand for tenses and moods
        {
            NO_TENSE,
            PAST,
            PRESENT,
            FUTURE,
            INFINITIVE,
            JUSSIVE,
            CONDITIONAL
        };

        Word()
            :type(UNKNOWN_TYPE),
             function(NO_CASE),
             tense(NO_TENSE),
             isPlural(false),
             node(0)
        {}

        std::string str;
        std::string str_base;
        Word::Type type;
        Case function;
        Tense tense;
        bool isPlural;
        Node* node;
        LinkNode* link_node;
        bool is_special;
};

#endif // WORD_H
