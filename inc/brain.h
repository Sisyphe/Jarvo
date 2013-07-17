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

        void traverseNetwork(NetworkProcess* n_process, ThingNode* n_node=0);
        void traverseLinkGraph(LinkProcess* n_process, LinkNode* n_link_node=0);
        bool pathExists(ThingNode* n_out_node, const Link& n_link, ThingNode* n_in_node);
        bool connectNodes(ThingNode* n_out_node, LinkNode* n_link_node, ThingNode* n_in_node);

        ThingNode* getEntity(const Word& n_word);
        ThingNode* getEntity(const std::string& n_str);
        ThingNode* getOrCreateEntity(const Word& n_word);
        ThingNode* getOrCreateEntity(const std::string& n_str);
        ThingNode* createEntity(const Word& n_word);
        ThingNode* createEntity(const std::string& n_str);

        ThingNode* createInstanceOf(ThingNode* n_entity);
        ThingNode* getOrCreateThing(const Word& n_word);

        ThingNode* createSpecialInstanceOf(ThingNode* n_entity_node);
        ThingNode* getOrCreateSpecialThing(const Word& n_word);

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
