#include "findpath.h"

FindPath::FindPath(Node* n_out_node, const Link& n_link, Node::LinkDirection n_direction):
    m_out_node(n_out_node),
    m_link(n_link),
    m_link_found_node(0),
    m_is_found(false),
    m_is_link_found(false),
    m_direction(n_direction)
{
}

FindPath::FindPath(const Link& n_link, Node::LinkDirection n_direction):
    m_out_node(0),
    m_link(n_link),
    m_link_found_node(0),
    m_is_found(false),
    m_is_link_found(false),
    m_direction(n_direction)
{
}

std::list<Relation*> FindPath::foundPath() const
{
    return m_relation_list;
}

bool FindPath::isPathFound() const
{
    return m_is_found;
}

bool FindPath::process(Node* n_node)
{
    if(n_node == m_link_found_node)
    {
        m_is_link_found = false;
        m_relation_list.erase(m_found_relation_it, m_relation_list.end());
    }

    return true;
}

bool FindPath::checkEdge(Relation* n_relation)
{
    Link* t_link = n_relation->content().link();
    bool stop = true;

    if(*t_link == m_link)
    {
        m_is_link_found = true;
        m_link_found_node = n_relation->inputVertice();
        m_relation_list.push_back(n_relation);
        m_found_relation_it = --m_relation_list.end();
        stop = false;
    }
    else if(*t_link == Link::isLink)
    {
        m_relation_list.push_back(n_relation);
        stop = false;
    }

    if(m_is_link_found && ((n_relation->inputVertice() == m_out_node || !m_out_node)))
    {
        m_is_found = true;
        stop = true;
    }

    return !stop;
}

typename Node::LinkDirection FindPath::direction() const
{
    return m_direction;
}

FindPath::TraversalMode FindPath::traversalMode() const
{
    return FindPath::POSTFIXED;
}
