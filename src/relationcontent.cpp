#include "relationcontent.h"
#include "node.h"

RelationContent::RelationContent(RelationContent::Type n_type)
     :m_type(n_type)
{
    std::pair<Time,RelationContent::State> t_creation_log;
    time(&t_creation_log.first);
    t_creation_log.second=ENABLED;
    m_history.push_back(t_creation_log);
}

RelationContent::Type RelationContent::type() const
{
    return m_type;
}

RelationContent::State RelationContent::state() const
{
    return m_history.back().second;
}
