#include "findconnection.h"

FindConnection::FindConnection(Node* n_out_node, const Link& n_link)
    :m_out_node(n_out_node),
     m_link(n_link),
     m_link_found_node(0),
     m_is_link_found(false)
{
    m_is_found=false;
}

bool FindConnection::isConnectionFound() const
{
    return m_is_found;
}

bool FindConnection::process(Node *n_node)
{
    if(n_node == m_link_found_node)
    {
        m_is_link_found=false;
    }

    return true;
}

bool FindConnection::checkEdge(Relation *n_relation)
{
    Link* t_link=n_relation->content().link();
    bool stop=true;

    if(*t_link == m_link)
    {
        m_is_link_found=true;
        m_link_found_node=n_relation->inputVertice();
        stop=false;
    }
    else if(*t_link == Link::isEquivalentLink)
    {
        stop=false;
    }

    if(m_is_link_found &&  n_relation->inputVertice() == m_out_node)
    {
        m_is_found=true;
        stop=true;
    }

    return !stop;
}

typename Node::LinkDirection FindConnection::direction() const
{
    return Node::OUTPUT;
}

FindConnection::TraversalMode FindConnection::traversalMode() const
{
    return FindConnection::POSTFIXED;
}
