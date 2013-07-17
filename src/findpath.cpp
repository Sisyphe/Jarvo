#include "findpath.h"

FindPath::FindPath(ThingNode* n_out_node, const Link& n_link)
    :m_out_node(n_out_node),
     m_link(n_link),
     m_link_found_node(0),
     m_is_link_found(false),
     m_relation_list(new std::list<Relation*>())
{
    m_is_found=false;
}

std::list<Relation*>* FindPath::foundPath() const
{
    return m_relation_list;
}

bool FindPath::isPathFound() const
{
    return m_is_found;
}

bool FindPath::process(ThingNode *n_node)
{
    if(n_node == m_link_found_node)
    {
        m_is_link_found=false;
        m_relation_list->erase(m_found_relation_it,m_relation_list->end());
    }

    return true;
}

bool FindPath::checkEdge(Relation *n_relation)
{
    Link* t_link=n_relation->content().link();
    bool stop=true;

    if(*t_link == m_link)
    {
        m_is_link_found=true;
        m_link_found_node=n_relation->inputVertice();
        m_relation_list->push_back(n_relation);
        m_found_relation_it=--m_relation_list->end();
        stop=false;
    }
    else if(*t_link == Link::isEquivalentLink)
    {
        m_relation_list->push_back(n_relation);
        stop=false;
    }

    if(m_is_link_found &&  n_relation->inputVertice() == m_out_node)
    {
        m_is_found=true;
        stop=true;
    }

    return !stop;
}

typename ThingNode::LinkDirection FindPath::direction() const
{
    return ThingNode::OUTPUT;
}

FindPath::TraversalMode FindPath::traversalMode() const
{
    return FindPath::POSTFIXED;
}
