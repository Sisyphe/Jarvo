#ifndef FINDTHING_H
#define FINDTHING_H

#include <verticeprocess.h>
#include "node.h"
#include "thing.h"
#include "word.h"

class FindThing : public VerticeProcess<Thing,RelationContent>
{
    public:

        FindThing(const Word& n_word, bool n_is_looking_for_entity=false);
        FindThing(const std::string& n_str, bool n_is_looking_for_entity=false);

        bool isThingFound() const;
        Node* thingNode() const;

        virtual bool process(Node *n_node);
        virtual bool checkEdge(Relation *n_relation);
        virtual typename Node::LinkDirection direction() const;
        virtual TraversalMode traversalMode() const;

    protected:

        std::string m_str;
        Node* m_node;
        bool m_is_looking_for_entity;
};

#endif // FINDTHING_H
