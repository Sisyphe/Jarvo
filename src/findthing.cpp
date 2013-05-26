#include "findthing.h"

FindThing::FindThing(const Word &n_word)
    :m_word(n_word),
     m_node(0)
{
}

bool FindThing::isThingFound() const
{
    return m_node==0;
}

Node* FindThing::thingNode() const
{
    return m_node;
}

bool FindThing::applyOn(Node* n_node)
{
    bool t_continue=true;

    if
    (
       !n_node->content().isEntity() &&
       n_node->content().str()==m_word.str_base
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
