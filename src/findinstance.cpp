#include "findinstance.h"
#include "link.h"

FindInstance::FindInstance()
{

}

bool FindInstance::process(ThingNode* n_node)
{
    bool t_continue=true;

    if
    (
        n_node->content().type()==m_type
        && n_node->content().str()==m_str
    )
    {
        t_continue=false;
        m_node=n_node;
    }

    return t_continue;
}

bool FindInstance::checkEdge(Relation* n_relation)
{
    Link* t_link=n_relation->content().link();
    bool t_continue=false;

    if(*t_link == Link::isEquivalentLink)
    {
        t_continue=true;
    }

    return t_continue;
}

typename ThingNode::LinkDirection FindInstance::direction() const
{
    return ThingNode::INPUT;
}

FindInstance::TraversalMode FindInstance::traversalMode() const
{
    return FindInstance::PREFIXED;
}
