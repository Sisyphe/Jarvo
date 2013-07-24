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

        NounGroup subjectGroup() const;
        void setSubjectGroup(const NounGroup& n_subject);

        VerbGroup verbGroup() const;
        void setVerbGroup(const VerbGroup& n_verb);

        bool isInterrogative() const;
        void setIsInterrogative(bool n_true);

    protected:

        NounGroup subject_group;
        VerbGroup verb_group;
        bool is_interrogative;
        bool is_yes_no_question;
};

#endif // SENTENCE_H
