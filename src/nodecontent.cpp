#include "nodecontent.h"

NodeContent::NodeContent()
{
}

enum NodeContent::Type NodeContent::type() const
{
    return m_type;
}

