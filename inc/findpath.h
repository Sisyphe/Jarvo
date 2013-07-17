#ifndef FIND_CONNECTION_H
#define FIND_CONNECTION_H

#include <verticeprocess.h>
#include "node.h"
#include "link.h"
#include <list>

class FindPath: public VerticeProcess<Thing,RelationContent>
{
    public:

        FindPath(ThingNode* n_out_node, const Link& n_link);

        bool isPathFound() const;
        std::list<Relation*>* foundPath() const;
        virtual bool process(ThingNode *n_node);
        virtual bool checkEdge(Relation *n_relation);
        virtual ThingNode::LinkDirection direction() const;
        virtual TraversalMode traversalMode() const;

    protected:

        ThingNode* m_out_node;
        Link m_link;
        ThingNode* m_link_found_node;
        std::list<Relation*>::iterator m_found_relation_it;
        bool m_is_found;
        bool m_is_link_found;
        std::list<Relation*>* m_relation_list;
};

#endif
