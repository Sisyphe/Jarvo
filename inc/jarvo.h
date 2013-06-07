#ifndef JARVO_H
#define JARVO_H

#include <graph.h>
#include "thing.h"
#include "nodecontent.h"
#include "node.h"
#include "parser.h"
#include "relationcontent.h"
#include "link.h"
#include "word.h"
#include "linkgraph.h"
#include "mouth.h"

class Jarvo
{
    public:

        typedef Graph<Thing,RelationContent> Network;

        Jarvo();

        Node* getEntity(const Word& n_word);
        Node* createEntityFromWord(const Word& n_word);
        Node* createThingFromWord(const Word& n_word);

        void feed(const std::string& n_input);
        void processStatement(Sentence& n_sentence);
        void processYesNoQuestion(Sentence& t_sentence);

        void say(const std::string& n_str);
        void dumpBrain() const;

    protected:

        Network m_network;
        LinkGraph m_links;
        Parser m_parser;
        Mouth m_mouth;
};

#endif // JARVO_H
