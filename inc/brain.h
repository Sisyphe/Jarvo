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

        void traverseNetwork(NetworkProcess* n_process, Node* n_node=0);
        void traverseLinkGraph(LinkProcess* n_process, LinkNode* n_link_node=0);
        bool findRelation(Node* n_out_node, const Link& n_link, Node* n_in_node);

        Node* getEntity(const Word& n_word);
        Node* getEntity(const std::string& n_str);
        Node* getOrCreateEntity(const Word& n_word);
        Node* getOrCreateEntity(const std::string& n_str);
        Node* createEntity(const Word& n_word);
        Node* createEntity(const std::string& n_str);

        Node* createInstanceOf(Node* n_entity);
        Node* getOrCreateThing(const Word& n_word);

        Node* createSpecialInstanceOf(Node* n_entity_node);
        Node* getOrCreateSpecialThing(const Word& n_word);

        LinkNode* getLink(const Link& n_link);
        LinkNode* getOrCreateLinkNode(const Link& n_link);
        LinkNode* createLinkNode(const Link& n_link);

        void dump() const;

    protected:

        Network m_network;
        LinkGraph m_links;
        Vertice< Thing, RelationContent >* m_io;
};

#endif // BRAIN_H
