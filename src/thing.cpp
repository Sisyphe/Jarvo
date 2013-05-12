#include "thing.h"
#include "jarvo.h"

Thing::Thing()
    :m_type(NodeContent::THING)
{
}

std::string Thing::str() const
{
    return m_str;
}
