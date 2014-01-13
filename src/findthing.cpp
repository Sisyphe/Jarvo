#include "findthing.h"
#include "findpath.h"

FindThing::FindThing(const Word& n_word, NodeContent::Type n_type):
    m_str(n_word.str_base),
    m_node(0),
    m_type(n_type),
    m_filter_type(true)
{
}

FindThing::FindThing(const std::string& n_str, NodeContent::Type n_type):
    m_str(n_str),
    m_node(0),
    m_type(n_type),
    m_filter_type(true)
{
}

FindThing::FindThing(const WordGroup& n_group):
    m_node(0),
    m_type(NodeContent::THING),
    m_filter_type(true),
    m_qualifiers_finder(n_group.getComplements(WordGroup::ADJECTIVE))
{
    m_str = n_group.str();
}

FindThing::FindThing
(
    const std::string& n_str,
    const std::vector<Link>& n_links,
    NodeContent::Type n_type
):
    m_str(n_str),
    m_node(0),
    m_type(n_type),
    m_links(n_links),
    m_filter_type(true)
{
}

bool FindThing::isThingFound() const
{
    return m_node != 0;
}

Node* FindThing::thingNode() const
{
    return m_node;
}

bool FindThing::process(Node* n_node)
{
    bool t_continue = true;
    std::vector<Link>::iterator it;
    Relation::It jt;

    if((n_node->content().type() != NodeContent::ENTITY || m_type == NodeContent::ENTITY) &&
       n_node->content().str() == m_str)
    {
        m_qualifiers_finder.applyFrom(n_node);

        if(m_qualifiers_finder.areQualifiersFound())
        {
            t_continue = false;
            m_node = n_node;
        }
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
    return FindThing::POSTFIXED;
}
