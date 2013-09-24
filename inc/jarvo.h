#ifndef JARVO_H
#define JARVO_H

#include "parser.h"
#include "brain.h"
#include "mouth.h"

class Jarvo
{
    public:

        Jarvo();

        void feed(const std::string& n_input);
        void processStatement(Sentence& n_sentence);
        void processPolarQuestion(Sentence& t_sentence);
        void processCommand(Sentence& t_sentence);

        static void say(const std::string& n_str);
        void dumpBrain() const;

    protected:

        Brain m_brain;
        Parser m_parser;
        Mouth m_mouth;
};

#endif // JARVO_H
