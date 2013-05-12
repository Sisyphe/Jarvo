#ifndef RELATION_CONTENT_H
#define RELATION_CONTENT_H

#include <ctime>
#include <vector>
#include <utility>

typedef time_t Time;

class RelationContent
{
    public:

        enum Type
        {
            NONE,
            ENTITY_IS_THING,
            THING_HAS_ENTITY,
            HAS_PROPERTY
        };

        enum State
        {
            DISABLED,
            ENABLED
        };

        typedef std::vector<std::pair<Time, State> > StateHistory;

        RelationContent(enum Type n_type=NONE);

        enum Type type() const;

        State state() const;

    protected:

        enum Type m_type;
        StateHistory m_history;

};

#endif // RELATION_CONTENT_H
