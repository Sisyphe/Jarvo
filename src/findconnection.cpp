#include "findconnection.h"

FindConnection::FindConnection(Node* n_out_node, const Link& n_link)
    :m_out_node(n_out_node),
     m_link(n_link)
{
    m_is_found=false;
}

bool FindConnection::isConnectionFound() const
{
    return m_is_found;
}

bool FindConnection::applyOn(Node *n_node)
{
    return true;
}

bool FindConnection::checkEdge(Relation *n_relation)
{
    Link* t_link=n_relation->content().link();
    bool stop=true;

    if(*t_link == m_link)
    {
        m_is_link_found=true;
        stop=false;
    }
    else if(*t_link == Link::isEquivalentLink)
    {
        stop=false;
    }
    else
    {
        m_is_link_found=false;
    }

    if(m_is_link_found &&  n_relation->inputVertice() == m_out_node)
    {
        m_is_found=true;
        stop=true;
    }

    return !stop;
}
