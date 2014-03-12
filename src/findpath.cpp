#include "findpath.h"

FindPath::FindPath(Node* n_out_node, const Link& n_link, Node::LinkDirection n_direction):
    VerticeProcess<Thing, RelationContent>(FindPath::PREFIXED, n_direction),
    m_out_node(n_out_node),
    m_link(n_link),
    m_link_found_node(0),
    m_is_found(false),
    m_is_link_found(false)
{
}

FindPath::FindPath(const Link& n_link, Node::LinkDirection n_direction):
    VerticeProcess<Thing, RelationContent>(FindPath::PREFIXED, n_direction),
    m_out_node(0),
    m_link(n_link),
    m_link_found_node(0),
    m_is_found(false),
    m_is_link_found(false)
{
}

std::list<Relation*> FindPath::foundPath() const
{
    return m_relation_list;
}

Node* FindPath::foundNode() const
{
    if(m_is_found)
    {
        return m_link_found_node;
    }
    else
    {
        return 0;
    }
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
        if(m_direction == Node::OUTPUT)
        {
            m_link_found_node = n_relation->inputVertice();
        }
        else
        {
            m_link_found_node = n_relation->outputVertice();
        }
        m_relation_list.push_back(n_relation);
        m_found_relation_it = --m_relation_list.end();
        stop = false;
    }
    else if(*t_link == Link::isLink)
    {
        m_relation_list.push_back(n_relation);
        stop = false;
    }

    if(m_is_link_found && ((m_link_found_node == m_out_node || !m_out_node)))
    {
        m_is_found = true;
        stop = true;
    }

    return !stop;
}
