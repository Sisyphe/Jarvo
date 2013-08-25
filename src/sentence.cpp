#include "sentence.h"

Sentence::Sentence():
    is_interrogative(false),
    is_yes_no_question(false)
{
}

Word* Sentence::subject() const
{
    return subject_group.mainWord();
}

Word* Sentence::verb() const
{
    return verb_group.mainWord();
}

WordGroup Sentence::subjectGroup() const
{
    return subject_group;
}

void Sentence::setSubjectGroup(const WordGroup& n_subject)
{
    subject_group = n_subject;
}

WordGroup Sentence::verbGroup() const
{
    return verb_group;
}

void Sentence::setVerbGroup(const WordGroup& n_verb)
{
    verb_group = n_verb;
}

bool Sentence::isInterrogative() const
{
    return is_interrogative;
}

void Sentence::setIsInterrogative(bool n_true)
{
    is_interrogative = n_true;
}
