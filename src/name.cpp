#include "name.h"

Name::Name(Node* n_thing)
    :m_type(Word::NAME)
{
    setThingNode(n_thing);
}

Name::Name(const std::string& n_str, Node* n_thing)
{
    setString(n_str);
    setThingNode(n_thing);
}

void Name::setThingNode(Node* n_thing)
{
    m_thing=n_thing;
}

Node* Name::thingNode() const
{
    return m_thing;
}
