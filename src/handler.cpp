#include "handler.h"

const std::list<std::string>& Handler::handable() const
{
    return m_handables;
}
