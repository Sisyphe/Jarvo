#ifndef FINDQUALIFIERS_H
#define FINDQUALIFIERS_H

#include <verticeprocess.h>

class FindQualifiers: VerticeProcess<Thing, RelationContent>
{
    public:

        FindQualifiers(const std::vector<WordGroup>& n_qualifiers);

        bool isQualifierFound(const WordGroup& n_qualifier_group) const;
        bool areQualifiersFound() const;
        std::vector<WordGroup> foundQualifiers() const;

        virtual bool process(Node* n_node);
        virtual bool checkEdge(Relation* n_relation);

    protected:

        std::map<Link, std::map<WordGroup, bool>::iterator> m_links;
        std::map<WordGroup, bool> m_found_qualifiers;
};

#endif // FINDQUALIFIERS_H
