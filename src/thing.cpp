#include "thing.h"
#include "jarvo.h"

Thing::Thing(NodeContent::Type n_type)
{
    m_type=n_type;
}

Thing::Thing(const std::string& n_str, NodeContent::Type n_type)
{
    m_type=n_type;
    m_str=n_str;
}

std::string Thing::str() const
{
    return m_str;
}
