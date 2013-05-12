#ifndef NODE_H
#define NODE_H

#include <vertice.h>
#include <edge.h>
#include "nodecontent.h"
#include "relationcontent.h"

typedef Vertice<NodeContent,RelationContent> Node;

typedef Edge<NodeContent,RelationContent> Relation;

#endif // NODE_H
