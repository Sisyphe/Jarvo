#ifndef ENTITY_H
#define ENTITY_H

#include "nodecontent.h"

class Entity : public NodeContent
{
    public:

        Entity();

        unsigned int id() const;

    protected:

        enum NodeContent::Type m_type;
        unsigned int m_id;

        static unsigned int s_id_counter;

};

#endif // ENTITY_H
