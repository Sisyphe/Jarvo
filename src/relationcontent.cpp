#include "relationcontent.h"
#include "node.h"

RelationContent::RelationContent(Vertice<Link*,bool>* n_link_node)
     :m_link_node(n_link_node)
{
    std::pair<Time,RelationContent::State> t_creation_log;
    time(&t_creation_log.first);
    t_creation_log.second=ENABLED;
    m_history.push_back(t_creation_log);
}

RelationContent::State RelationContent::state() const
{
    return m_history.back().second;
}

Link* RelationContent::link() const
{
    Link* t_link=0;

    if(m_link_node)
    {
        t_link=m_link_node->content();
    }

    return t_link;
}
