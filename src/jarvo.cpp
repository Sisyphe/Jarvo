#include "jarvo.h"

Node* Jarvo::createEntityOf(Node* n_thing_node)
{
    Node* t_entity_node=m_network.addVertice(Entity());
    m_network.addEdge(RelationContent::ENTITY_IS_THING, t_entity_node, n_thing_node);
    m_network.addEdge(RelationContent::THING_HAS_ENTITY, n_thing_node, t_entity_node);
    return t_entity_node;
}

void Jarvo::feed(const std::string& n_input)
{
}
