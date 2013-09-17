#include "sentence.h"

Sentence::Sentence():
    m_is_interrogative(false),
    m_is_polar_question(false)
{
}

Word* Sentence::subject() const
{
    return m_subject_group.mainWord();
}

Word* Sentence::verb() const
{
    return m_verb_group.mainWord();
}

WordGroup Sentence::subjectGroup() const
{
    return m_subject_group;
}

void Sentence::setSubjectGroup(const WordGroup& n_subject)
{
    setIsInterrogative(isInterrogative() || n_subject.isInterrogative());
    m_subject_group = n_subject;
}

WordGroup Sentence::verbGroup() const
{
    return m_verb_group;
}

void Sentence::setVerbGroup(const WordGroup& n_verb)
{
    setIsInterrogative(isInterrogative() || n_verb.isInterrogative());
    m_verb_group = n_verb;
}

WordGroup Sentence::objectGroup() const
{
    return m_object_group;
}

void Sentence::setObjectGroup(const WordGroup& n_object)
{
    setIsInterrogative(isInterrogative() || n_object.isInterrogative());
    m_object_group = n_object;
}

bool Sentence::isInterrogative() const
{
    return m_is_interrogative;
}

void Sentence::setIsInterrogative(bool n_true)
{
    if(!n_true) setIsPolarQuestion(false);
    m_is_interrogative = n_true;
}

bool Sentence::isPolarQuestion() const
{
    return m_is_polar_question;
}

void Sentence::setIsPolarQuestion(bool n_true)
{
    if(n_true) setIsInterrogative(true);
    m_is_polar_question = n_true;
}
