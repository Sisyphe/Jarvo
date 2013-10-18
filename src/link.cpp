#include "link.h"

Link Link::isLink = Link("esti");

Link::Link(const std::string& n_verb):
    m_type(NodeContent::LINK)
{
    setVerb(n_verb);
}

bool Link::isIsLink(const Link& n_link)
{
    return (n_link.verb() == isLink.verb());
}

std::string Link::verb() const
{
    return m_verb;
}

void Link::setVerb(const std::string& n_verb)
{
    m_verb = n_verb;
}

void Link::addQualifier(const std::string& n_qualifier)
{
    m_qualifiers.push_back(n_qualifier);
}

std::vector<std::string> Link::qualifiers() const
{
    return m_qualifiers;
}

void Link::addAdverb(const std::string& n_adverb)
{
    m_adverbs.push_back(n_adverb);
}

std::ostream& operator<<(std::ostream& n_out, const Link& n_link)
{
    std::vector<std::string>::const_iterator it;

    n_out << n_link.verb();

    for(it = n_link.m_adverbs.begin(); it != n_link.m_adverbs.end(); ++it)
    {
        n_out << " " << (*it);
    }

    for(it = n_link.m_qualifiers.begin(); it != n_link.m_qualifiers.end(); ++it)
    {
        n_out << " " << (*it);
    }

    return n_out;
}

bool Link::operator==(const Link& n_link) const
{
    bool t_is_verb_equal;
    bool t_is_found = true;
    std::vector<std::string>::const_iterator it, jt;

    t_is_verb_equal = (m_verb == n_link.verb());

    if(t_is_verb_equal)
    {
        it = m_qualifiers.begin();

        if(m_qualifiers.empty() && !n_link.m_qualifiers.empty())
        {
            t_is_found = false;
        }

        while(t_is_found && it != m_qualifiers.end())
        {
            t_is_found = false;
            jt = n_link.m_qualifiers.begin();

            while(!t_is_found && jt != n_link.m_qualifiers.end())
            {
                t_is_found = ((*it) == (*jt));
                ++jt;
            }

            ++it;
        }

        if(t_is_found)
        {
            it = m_adverbs.begin();

            if(m_adverbs.empty() && !n_link.m_adverbs.empty())
            {
                t_is_found = false;
            }

            while(t_is_found && it != m_adverbs.end())
            {
                t_is_found = false;
                jt = n_link.m_adverbs.begin();

                while(!t_is_found && jt != n_link.m_adverbs.end())
                {
                    t_is_found = ((*it) == (*jt));
                    ++jt;
                }

                ++it;
            }
        }
    }

    return t_is_verb_equal && t_is_found;
}

bool Link::tryToHandle(Node* n_node)
{
    return false;
}
