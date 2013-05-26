#include "thing.h"
#include "jarvo.h"

Thing::Thing()
    :m_type(NodeContent::THING)
{
}

Thing::Thing(const std::string& n_str, bool n_is_entity)
    :m_type(NodeContent::THING)
{
    m_str=n_str;
    m_is_entity=n_is_entity;
}

std::string Thing::str() const
{
    return m_str;
}

bool Thing::isEntity() const
{
    return m_is_entity;
}
