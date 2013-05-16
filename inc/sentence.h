#ifndef SENTENCE_H
#define SENTENCE_H

#include "word.h"
#include "noun.h"
#include "adjective.h"

class Sentence
{
    public:

        Sentence();

        Word* subject;
        std::vector<Word*> subject_adjs;
        Word* verb;
        Word* object;
        std::vector<Word*> object_adjs;
};

#endif // SENTENCE_H
