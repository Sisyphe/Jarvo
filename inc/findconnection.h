#ifndef FIND_CONNECTION_H
#define FIND_CONNECTION_H

#include <verticeprocess.h>
#include "node.h"
#include "link.h"

class FindConnection: public VerticeProcess<Thing,RelationContent>
{
    public:

        FindConnection(Node* n_out_node, const Link& n_link);

        bool isConnectionFound() const;
        Relation* foundRelation() const;
        virtual bool process(Node *n_node);
        virtual bool checkEdge(Relation *n_relation);
        virtual Node::LinkDirection direction() const;
        virtual TraversalMode traversalMode() const;

    protected:

        Node* m_out_node;
        Link m_link;
        Node* m_link_found_node;
        bool m_is_found;
        bool m_is_link_found;
        Relation* m_relation;
};

#endif
