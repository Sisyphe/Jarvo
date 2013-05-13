#include "noun.h"

Noun::Noun(Node* n_thing)
    :m_type(Word::NOUN)
{
    setThingNode(n_thing);
}

Noun::Noun(const std::string& n_str, Node* n_thing)
{
    setString(n_str);
    setThingNode(n_thing);
}

void Noun::setThingNode(Node* n_thing)
{
    m_thing=n_thing;
}

Node* Noun::thingNode() const
{
    return m_thing;
}

Noun* Noun::get()
{
    return this;
}
