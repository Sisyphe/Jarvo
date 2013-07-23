#ifndef RELATION_CONTENT_H
#define RELATION_CONTENT_H

#include <ctime>
#include <vector>
#include <utility>
#include <string>
#include "vertice.h"
#include "thing.h"

class Link;

typedef time_t Time;

class RelationContent
{
    public:

        enum State
        {
            DISABLED,
            ENABLED
        };

        enum Type
        {
            NORMAL,
            SPECIALIZATION,
            FEATURE
        };

        typedef std::vector<std::pair<Time, State> > StateHistory;

        RelationContent(Vertice<Link*, bool> *n_link_node=0);

        State state() const;
        void enable();

        Link* link() const;

        Type type() const;
        void setType(Type n_type);

        bool operator== (const RelationContent& n_relation_content) const;
        friend std::ostream& operator<<(std::ostream& n_out, const RelationContent& n_content);

    protected:

        StateHistory m_history;
        Vertice<Link*,bool> const* m_link_node;
        Type m_type;
};

#endif // RELATION_CONTENT_H
