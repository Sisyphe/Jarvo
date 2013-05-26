#ifndef LINKGRAPH_H
#define LINKGRAPH_H

#include "link.h"
#include "graph.h"
#include <set>

typedef Vertice<Link,bool> LinkNode;
typedef Edge<Link,bool> LinkRelation;

class LinkGraph : public Graph<Link,bool>
{
    public:

        LinkGraph();

        LinkNode* findLinkNode(const Link& n_link);
        LinkNode* addLinkNode(const Link& n_link);

        LinkNode* esti() const;

    protected:

        std::map<Link,LinkNode*,Link::Comp> m_link_nodes;
        LinkNode* m_esti;
};

#endif // LINKGRAPH_H
