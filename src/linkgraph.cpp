#include "linkgraph.h"

LinkGraph::LinkGraph()
{
    m_esti=addLinkNode(Link("esti"));
}

LinkGraph::~LinkGraph(){}

LinkNode* LinkGraph::findLinkNode(const std::string& n_link_str)
{
    LinkNode* t_link_node=0;

    std::map<Link*,LinkNode*>::iterator it=m_link_nodes.begin();
    while(it != m_link_nodes.end() && (*it).first->verb() != n_link_str)
    {
        ++it;
    }

    if(it != m_link_nodes.end())
        t_link_node=(*it).second;

    return t_link_node;
}

LinkNode* LinkGraph::addLinkNode(const Link& n_link)
{
    Link* t_link = new Link(n_link);
    LinkNode* t_link_node=addVertice(t_link);
    m_link_nodes[t_link]=t_link_node;
    return t_link_node;
}

LinkNode* LinkGraph::esti() const
{
    return m_esti;
}
