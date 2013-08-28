#ifndef LINKGRAPH_H
#define LINKGRAPH_H

#include "link.h"
#include "graph.h"
#include <set>

typedef Vertice<Link*, bool> LinkNode;
typedef Edge<Link*, bool> LinkRelation;
typedef VerticeProcess<Link*, bool> LinkProcess;

class LinkGraph: public Graph<Link*, bool>
{
    public:

        LinkGraph();
        virtual ~LinkGraph();

        LinkNode* findLinkNode(const std::string& n_link_str);
        LinkNode* addLinkNode(const Link& n_link);

        LinkNode* isLinkNode() const;

    protected:

        std::map<Link*, LinkNode*> m_link_nodes;
        LinkNode* m_is_link_node;
};

#endif // LINKGRAPH_H
