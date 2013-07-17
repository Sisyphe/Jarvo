#ifndef FINDINSTANCE_H
#define FINDINSTANCE_H

#include <verticeprocess.h>
#include "node.h"

class FindInstance: public VerticeProcess<Link*, bool>
{
    public:

        FindInstance(ThingNode* n_node, bool n_is_defined=false);

        virtual bool process(ThingNode *n_node);
        virtual bool checkEdge(Relation *n_relation);
        virtual typename ThingNode::LinkDirection direction() const;
        virtual TraversalMode traversalMode() const;
};

#endif // FINDINSTANCE_H
