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
        virtual bool applyOn(Node *n_node);
        virtual bool checkEdge(Relation *n_relation);

    protected:

        Node* m_in_node;
        Node* m_out_node;
        Link m_link;
        bool m_is_found;
        bool m_is_link_found;
};

#endif
