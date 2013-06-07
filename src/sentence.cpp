#include "sentence.h"

Sentence::Sentence()
    :subject(0),
     subject_is_entity(false),
     verb(0),
     object(0),
     object_is_entity(false),
     is_interrogative(false),
     is_yes_no_question(false)
{
}
