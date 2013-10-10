#ifndef FIND_CONNECTION_H
#define FIND_CONNECTION_H

#include <verticeprocess.h>
#include "node.h"
#include "link.h"
#include <list>

class FindPath: public VerticeProcess<Thing, RelationContent>
{
    public:

        FindPath(Node* n_out_node, const Link& n_link, Node::LinkDirection n_direction = Node::OUTPUT);
        FindPath(const Link& n_link, Node::LinkDirection n_direction = Node::OUTPUT);

        bool isPathFound() const;
        std::list<Relation*> foundPath() const;
        virtual bool process(Node* n_node);
        virtual bool checkEdge(Relation* n_relation);
        virtual Node::LinkDirection direction() const;
        virtual TraversalMode traversalMode() const;

    protected:

        Node* m_out_node;
        Link m_link;
        Node* m_link_found_node;
        std::list<Relation*>::iterator m_found_relation_it;
        bool m_is_found;
        bool m_is_link_found;
        std::list<Relation*> m_relation_list;
        Node::LinkDirection m_direction;
};

#endif
