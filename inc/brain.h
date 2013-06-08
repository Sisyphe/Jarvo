#ifndef BRAIN_H
#define BRAIN_H

#include <graph.h>
#include "node.h"
#include "word.h"
#include "linkgraph.h"

class Brain
{
    public:

        typedef Graph<Thing, RelationContent> Network;
        typedef VerticeProcess<Thing, RelationContent> NetworkProcess;

        Brain();
        ~Brain();

        void traverseNetwork(Node* n_node, NetworkProcess* n_process);
        void traverseLinkGraph(LinkNode* n_link_node, LinkProcess* n_process);

        Node* getEntity(const Word& n_word);
        Node* createEntityFromWord(const Word& n_word);
        Node* createThingFromWord(const Word& n_word);
        Node* createThingFromEntity(Node* n_entity);

        LinkNode* getLink(const Link& n_link);
        LinkNode* createLinkNode(const Link& n_link);

        void dump() const;

    protected:

        Network m_network;
        LinkGraph m_links;
};

#endif // BRAIN_H
