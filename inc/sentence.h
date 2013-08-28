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

        WordGroup objectGroup() const;
        void setObjectGroup(const WordGroup& n_object);

        bool isInterrogative() const;
        void setIsInterrogative(bool n_true);

        bool isPolarQuestion() const;
        void setIsPolarQuestion(bool n_true);

    protected:

        WordGroup m_subject_group;
        WordGroup m_verb_group;
        WordGroup m_object_group;
        bool m_is_interrogative;
        bool m_is_polar_question;
};

#endif // SENTENCE_H
