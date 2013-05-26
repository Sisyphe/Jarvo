#ifndef JARVO_H
#define JARVO_H

#include <graph.h>
#include "thing.h"
#include "entity.h"
#include "nodecontent.h"
#include "node.h"
#include "parser.h"
#include "relationcontent.h"
#include "link.h"
#include "word.h"
#include "linkgraph.h"

class Jarvo
{
    public:

        typedef Graph<Thing,RelationContent> Network;

        Node* createThingFromWord(const Word& n_word);

        void feed(const std::string& n_input);

        void dumpBrain() const;

    protected:

        Network m_network;
        LinkGraph m_links;
        Parser m_parser;
};

#endif // JARVO_H
