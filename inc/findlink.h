#ifndef FINDLINK_H
#define FINDLINK_H

#include <verticeprocess.h>
#include "link.h"
#include "linkgraph.h"

class FindLink: public VerticeProcess<Link*, bool>
{
    public:

        FindLink(const Link& n_link);
        ~FindLink();

        bool isLinkFound() const;
        LinkNode* linkNode() const;

        virtual bool process(LinkNode* n_node);
        virtual bool checkEdge(LinkRelation* n_relation);

    protected:

        Link m_link;
        LinkNode* m_node;
};

#endif // FINDLINK_H
