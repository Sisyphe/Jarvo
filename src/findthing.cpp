#include "findthing.h"

FindThing::FindThing(const Word& n_word, NodeContent::Type n_type):
    m_str(n_word.str_base),
    m_node(0),
    m_type(n_type)
{
}

FindThing::FindThing(const std::string& n_str, NodeContent::Type n_type):
    m_str(n_str),
    m_node(0),
    m_type(n_type)
{
}

FindThing::FindThing(const WordGroup& n_group):
    m_node(0),
    m_type(NodeContent::THING)
{
    std::vector<WordGroup> t_complements = n_group.getComplements(WordGroup::ADJECTIVE);
    std::vector<WordGroup>::const_iterator t_complement = t_complements.begin();

    for(; t_complement != t_complements.end(); ++t_complement)
    {
        Link t_link("esti");
        t_link.addQualifier(t_complement->str());

        std::vector<WordGroup> t_adverbs(t_complement->getComplements(WordGroup::ADVERB));
        std::vector<WordGroup>::iterator t_adverb(t_adverbs.begin());

        for(; t_adverb != t_adverbs.end(); ++t_adverb)
        {
            t_link.addAdverb(t_adverb->str());
        }

        m_links.push_back(t_link);
    }

    m_str = n_group.mainWord()->str_base;
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
    m_links(n_links)
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
    bool t_is_found = true;
    std::vector<Link>::iterator it;
    Relation::It jt;

    if
    (
        n_node->content().type() == m_type &&
        n_node->content().str() == m_str
    )
    {
        it = m_links.begin();

        while(t_is_found && it != m_links.end())
        {
            t_is_found = false;
            jt = n_node->outputEdgesBegin();

            while(!t_is_found && jt != n_node->outputEdgesEnd())
            {
                t_is_found = ((*jt)->inputVertice() == n_node) && ((*it) == (*((*jt)->content().link())));
                ++jt;
            }

            ++it;
        }

        if(t_is_found)
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
    return FindThing::PREFIXED;
}
