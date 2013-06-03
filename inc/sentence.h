#ifndef SENTENCE_H
#define SENTENCE_H

#include "word.h"

class Sentence
{
    public:

        Sentence();

        Word* subject;
        std::vector<Word*> subject_adjs;
        Word* verb;
        Word* object;
        std::vector<Word*> object_adjs;
        bool is_interrogative;
        bool is_yes_no_question;
};

#endif // SENTENCE_H
