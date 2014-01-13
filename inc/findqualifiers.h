#ifndef FINDQUALIFIERS_H
#define FINDQUALIFIERS_H

#include <verticeprocess.h>
#include "thing.h"
#include "node.h"
#include "wordgroup.h"

class FindQualifiers: public VerticeProcess<Thing, RelationContent>
{
    public:

        FindQualifiers(const std::vector<WordGroup>& n_qualifiers = std::vector<WordGroup>());

        bool isQualifierFound(const WordGroup& n_qualifier_group) const;
        bool areQualifiersFound() const;
        std::vector<WordGroup> foundQualifiers() const;

        virtual bool process(Node* n_node);
        virtual bool checkEdge(Relation* n_relation);

    protected:

        std::vector<std::pair<Link, std::vector<std::pair<WordGroup, bool> >::iterator> > m_links;
        std::vector<std::pair<WordGroup, bool> > m_found_qualifiers;
        unsigned int m_found_count;
};

#endif // FINDQUALIFIERS_H
