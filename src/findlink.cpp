#include "findlink.h"

FindLink::FindLink(const Link& n_link):
    m_link(n_link),
    m_node(0)
{
}

FindLink::~FindLink() {}

bool FindLink::isLinkFound() const
{
    return (m_node == 0);
}

LinkNode* FindLink::linkNode() const
{
    return m_node;
}

bool FindLink::process(LinkNode* n_node)
{
    bool t_continue = true;

    if(*(n_node->content()) == m_link)
    {
        t_continue = false;
        m_node = n_node;
    }

    return t_continue;
}

bool FindLink::checkEdge(LinkRelation* n_relation)
{
    return true;
}

VerticeProcess<Link*, bool>::TraversalMode FindLink::traversalMode() const
{
    return ALL;
}
