#include "thing.h"
#include "jarvo.h"

Thing::Thing(NodeContent::Type n_type)
{
    m_type = n_type;
}

Thing::Thing(const std::string& n_str, NodeContent::Type n_type)
{
    m_type = n_type;
    m_str = n_str;
}

std::string Thing::str() const
{
    return m_str;
}

std::ostream& operator<<(std::ostream& n_out, const Thing& n_thing)
{
    n_out << "Thing";
    if(n_thing.type() == NodeContent::ENTITY) n_out << "°";
    if(n_thing.type() == NodeContent::SPECIAL_THING) n_out << "*";
    n_out << ": " << n_thing.str();

    return n_out;
}
