#include "entity.h"

unsigned int Entity::s_id_counter=0;

Entity::Entity()
    :m_type(NodeContent::ENTITY)
{
    m_id=s_id_counter++;
}

unsigned int Entity::id() const
{
    return m_id;
}
