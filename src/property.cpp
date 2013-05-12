#include "property.h"

Property::Property()
    :m_type(NodeContent::PROPERTY)
{
}

std::string Property::str() const
{
    return m_str;
}
