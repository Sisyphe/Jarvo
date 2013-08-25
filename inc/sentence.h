#ifndef SENTENCE_H
#define SENTENCE_H

#include "wordgroup.h"

class Sentence
{
    public:

        Sentence();

        Word* subject() const;
        Word* verb() const;

        WordGroup subjectGroup() const;
        void setSubjectGroup(const WordGroup& n_subject);

        WordGroup verbGroup() const;
        void setVerbGroup(const WordGroup& n_verb);

        bool isInterrogative() const;
        void setIsInterrogative(bool n_true);

    protected:

        WordGroup subject_group;
        WordGroup verb_group;
        bool is_interrogative;
        bool is_yes_no_question;
};

#endif // SENTENCE_H
