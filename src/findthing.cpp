#include "findthing.h"

FindThing::FindThing(const Word &n_word, NodeContent::Type n_type)
    :m_str(n_word.str_base),
     m_node(0),
     m_type(n_type)
{
}

FindThing::FindThing(const std::string& n_str, NodeContent::Type n_type)
    :m_str(n_str),
     m_node(0),
     m_type(n_type)
{
}

bool FindThing::isThingFound() const
{
    return m_node!=0;
}

Node* FindThing::thingNode() const
{
    return m_node;
}

bool FindThing::process(Node* n_node)
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

bool FindThing::checkEdge(Relation* n_relation)
{
    return true;
}

typename Node::LinkDirection FindThing::direction() const
{
    return Node::BOTH;
}

FindThing::TraversalMode FindThing::traversalMode() const
{
    return FindThing::PREFIXED;
}
