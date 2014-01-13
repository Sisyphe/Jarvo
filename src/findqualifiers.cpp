#include "inc/findqualifiers.h"
#include <word.h>

FindQualifiers::FindQualifiers(const std::vector<WordGroup>& n_qualifiers):
    VerticeProcess<Thing, RelationContent>(FindQualifiers::POSTFIXED, Node::OUTPUT),
    m_found_count(0)
{
    std::vector<WordGroup> t_complements;
    std::vector<WordGroup>::const_iterator t_qualifier = n_qualifiers.begin();
    std::vector<std::pair<WordGroup, bool> >::iterator it;

    for(; t_qualifier != n_qualifiers.end(); ++t_qualifier)
    {
        m_found_qualifiers.push_back(std::pair<WordGroup, bool>(*t_qualifier, false));
        it = --m_found_qualifiers.end();

        Link t_link("esti");
        t_link.addQualifier(t_qualifier->str());

        std::vector<WordGroup> t_adverbs(t_qualifier->getComplements(WordGroup::ADVERB));
        std::vector<WordGroup>::iterator t_adverb(t_adverbs.begin());

        for(; t_adverb != t_adverbs.end(); ++t_adverb)
        {
            t_link.addAdverb(t_adverb->str());
        }

        m_links.push_back(std::pair<Link, std::vector<std::pair<WordGroup, bool> >::iterator>(t_link, it));
    }
}

bool FindQualifiers::isQualifierFound(const WordGroup& n_qualifier_group) const
{
    bool t_is_found = false;
    std::vector<std::pair<WordGroup, bool> >::const_iterator it;

    it = m_found_qualifiers.begin();
    while(it != m_found_qualifiers.end() && !t_is_found)
    {
        t_is_found = (it->first.str() == n_qualifier_group.str() && it->second);
        ++it;
    }

    return t_is_found;
}

bool FindQualifiers::areQualifiersFound() const
{
    bool t_is_found = true;
    std::vector<std::pair<WordGroup, bool> >::const_iterator it = m_found_qualifiers.begin();

    while(it != m_found_qualifiers.end() && t_is_found)
    {
        t_is_found = it->second;
        ++it;
    }

    return t_is_found;
}

std::vector<WordGroup> FindQualifiers::foundQualifiers() const
{
    std::vector<WordGroup> t_found_qualifiers;
    std::vector<std::pair<WordGroup, bool> >::const_iterator it = m_found_qualifiers.begin();

    for(; it != m_found_qualifiers.end(); ++it)
    {
        t_found_qualifiers.push_back(it->first);
    }

    return t_found_qualifiers;
}

bool FindQualifiers::process(Node* n_node)
{
    return true;
}

bool FindQualifiers::checkEdge(Relation* n_relation)
{
    Link* t_link = n_relation->content().link();
    bool t_continue = false;
    bool t_is_found = false;
    std::vector<std::pair<Link, std::vector<std::pair<WordGroup, bool> >::iterator> >::iterator it;

    if(Link::isIsLink(*t_link))
    {
        t_continue = true;

        it = m_links.begin();
        while(it != m_links.end() && !t_is_found && m_found_count < m_links.size())
        {
            if(*t_link == it->first)
            {
                t_is_found = true;
                ++m_found_count;
                it->second->second = true;
            }

            ++it;
        }
    }

    return t_continue;
}
