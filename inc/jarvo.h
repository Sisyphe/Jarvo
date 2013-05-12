#ifndef JARVO_H
#define JARVO_H

#include <graph.h>
#include "thing.h"
#include "entity.h"
#include "nodecontent.h"
#include "node.h"
#include "relationcontent.h"

class Jarvo
{
    public:

        typedef Graph<NodeContent,RelationContent> Network;

        Node* createEntityOf(Node* n_thing_node);

        void feed(const std::string& n_input);

    protected:

        Network m_network;
};

#endif // JARVO_H
