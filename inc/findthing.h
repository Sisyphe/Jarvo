#ifndef FINDTHING_H
#define FINDTHING_H

#include <verticeprocess.h>
#include "node.h"
#include "thing.h"
#include "word.h"
#include "wordgroup.h"
#include "findqualifiers.h"

class FindThing: public VerticeProcess<Thing, RelationContent>
{
    public:

        FindThing(const Word& n_word, NodeContent::Type n_type);
        FindThing(const std::string& n_str, NodeContent::Type n_type);
        FindThing(const WordGroup& n_group);
        FindThing(const std::string& n_str, const std::vector<Link>& n_links, NodeContent::Type n_type);

        bool isThingFound() const;
        Node* thingNode() const;

        virtual bool process(Node* n_node);
        virtual bool checkEdge(Relation* n_relation);
        virtual typename Node::LinkDirection direction() const;
        virtual TraversalMode traversalMode() const;

    protected:

        std::string m_str;
        Node* m_node;
        NodeContent::Type m_type;
        std::vector<Link> m_links;
        bool m_filter_type;
        FindQualifiers m_qualifiers_finder;
};

#endif // FINDTHING_H
