#include "sentence.h"

Sentence::Sentence():
    is_interrogative(false),
    is_yes_no_question(false)
{
}

Word* Sentence::subject() const
{
    //return subject_group.noun;
}

Word* Sentence::verb() const
{
    //return verb_group.verb;
}

Word* Sentence::object() const
{
    //return object_group.noun;
}
