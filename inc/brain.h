#ifndef BRAIN_H
#define BRAIN_H

#include <graph.h>
#include "node.h"
#include "word.h"
#include "wordgroup.h"
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
        bool pathExists(Node* n_out_node, const Link& n_link, Node* n_in_node);
        Relation* connectNodes(Node* n_out_node, LinkNode* n_link_node, Node* n_in_node);

        Node* getEntity(const std::string& n_str);
        Node* getOrCreateEntity(const WordGroup& n_group);
        Node* getOrCreateEntity(const std::string& n_str);
        Node* createEntity(const std::string& n_str);

        Node* createInstanceOf(Node* n_entity);
        Node* getOrCreateThing(const WordGroup& n_group);

        Node* getOrCreateSpecialThing(const WordGroup& n_word_group);

        Node* getOrCreateNode(const WordGroup& n_word_group);

        LinkNode* getLinkNode(const Link& n_link);
        LinkNode* getOrCreateLinkNode(const Link& n_link);
        LinkNode* createLinkNode(const Link& n_link);

        void addComplementsToNode(Node* n_node, const std::vector<WordGroup>& n_complements);

        void dump() const;

    protected:

        Network m_network;
        LinkGraph m_links;
        Vertice< Thing, RelationContent >* m_io;
};

#endif // BRAIN_H
