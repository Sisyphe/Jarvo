#ifndef SENTENCE_H
#define SENTENCE_H

#include "noungroup.h"
#include "verbgroup.h"

class Sentence
{
    public:

        Sentence();

        Word* subject() const;
        Word* verb() const;
        Word* object() const;

        NounGroup subject_group;
        VerbGroup verb_group;
        NounGroup object_group;
        bool is_interrogative;
        bool is_yes_no_question;
};

#endif // SENTENCE_H
