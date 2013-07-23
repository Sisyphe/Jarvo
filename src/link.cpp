#include "link.h"

Link Link::isEquivalentLink=Link("esti");

Link::Link(const std::string& n_verb)
    :m_type(NodeContent::LINK)
{
    setVerb(n_verb);
}

std::string Link::verb() const
{
    return m_verb;
}

void Link::setVerb(const std::string& n_verb)
{
    m_verb=n_verb;
}

void Link::addQualifier(const std::string& n_qualifier)
{
    m_qualifiers.push_back(n_qualifier);
}

void Link::addAdverb(const std::string& n_adverb)
{
    m_adverbs.push_back(n_adverb);
}
