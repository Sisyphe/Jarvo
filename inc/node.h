#ifndef NODE_H
#define NODE_H

#include <vertice.h>
#include <edge.h>
#include "thing.h"
#include "relationcontent.h"

typedef Vertice<Thing,RelationContent> ThingNode;

typedef Edge<Thing,RelationContent> Relation;

#endif // NODE_H
