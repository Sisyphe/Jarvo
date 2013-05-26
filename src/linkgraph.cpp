#include "inc/linkgraph.h"

LinkGraph::LinkGraph()
{
    m_esti=addLinkNode(Link("esti"));
}

LinkNode* LinkGraph::findLinkNode(const Link& n_link)
{
    return m_link_nodes[n_link];
}

LinkNode* LinkGraph::addLinkNode(const Link& n_link)
{
    LinkNode* t_link_node=addVertice(n_link);
    m_link_nodes[n_link]=t_link_node;
    return t_link_node;
}

LinkNode* LinkGraph::esti() const
{
    return m_esti;
}
