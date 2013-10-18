#include "inc/findqualifiers.h"
#include <word.h>

FindQualifiers::FindQualifiers(const std::vector<WordGroup>& n_qualifiers):
    VerticeProcess<Thing, RelationContent>(FindQualifiers::POSTFIXED, Node::OUTPUT)
{
    std::vector<WordGroup> t_complements;
    std::vector<WordGroup>::const_iterator t_complement = t_complements.begin();
    std::vector<WordGroup>::iterator it = n_qualifiers.begin();

    for(; it != n_qualifiers.end(); ++it)
    {
        m_found_qualifiers[*it] = false;

        t_complements = it->getComplements(WordGroup::ADJECTIVE);

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

            m_links[t_link] = it;
        }
    }
}

bool FindQualifiers::isQualifierFound(const WordGroup& n_qualifier_group) const
{
    std::map<WordGroup, bool>::const_iterator it = m_found_qualifiers.find(n_qualifier_group);

    return (it != m_found_qualifiers.end());
}

bool FindQualifiers::areQualifiersFound() const
{
    bool t_is_found = true;
    std::map<WordGroup, bool>::const_iterator it = m_found_qualifiers.begin();

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
    std::map<WordGroup, bool>::const_iterator it = m_found_qualifiers.begin();

    for(; it != m_found_qualifiers.end(); ++it)
    {
        t_found_qualifiers.push_back(*it);
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
    std::map<Link, std::map<WordGroup, bool>::iterator>::iterator it;

    if(Link::isIsLink(*t_link))
    {
        t_continue = true;

        it = m_links.begin();
        while(it != m_links.end() && !t_is_found)
        {
            if(t_link == it->first)
            {
                t_is_found = true;
                it->second->second = true;
            }

            ++it;
        }
    }

    return t_continue;
}
