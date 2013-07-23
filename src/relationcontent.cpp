#include "relationcontent.h"
#include "node.h"
#include "link.h"

RelationContent::RelationContent(Vertice<Link*,bool>* n_link_node):
    m_link_node(n_link_node),
    m_type(RelationContent::NORMAL)
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

void RelationContent::enable()
{
    if(state() == RelationContent::DISABLED)
    {
        std::pair<Time,RelationContent::State> t_log;
        time(&t_log.first);
        t_log.second=ENABLED;
        m_history.push_back(t_log);
    }
}

Link* RelationContent::link() const
{
    Link* t_link = 0;

    if(m_link_node)
    {
        t_link=m_link_node->content();
    }

    return t_link;
}

RelationContent::Type RelationContent::type() const
{
    return m_type;
}

void RelationContent::setType(Type n_type)
{
    m_type = n_type;
}

bool RelationContent::operator== (const RelationContent& n_relation_content) const
{
    return (m_link_node->content()) == (n_relation_content.m_link_node->content());
}

std::ostream& operator<<(std::ostream& n_out, const RelationContent& n_content)
{
    n_out << *n_content.link();
    return n_out;
}
