#include "adjective.h"

Adjective::Adjective(Node* n_property)
{
    m_type=Word::ADJECTIVE;
    setPropertyNode(n_property);
}

Adjective::Adjective(const std::string& n_str, Node* n_property)
{
    m_type=Word::ADJECTIVE;
    setString(n_str);
    setPropertyNode(n_property);
}


void Adjective::setPropertyNode(Node* n_property)
{
    m_property=n_property;
}

Node* Adjective::propertyNode() const
{
    return m_property;
}
