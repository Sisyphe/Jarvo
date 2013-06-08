#include "brain.h"
#include "findlink.h"
#include "findthing.h"
#include <fstream>

Brain::Brain(){}

Brain::~Brain(){}

void Brain::traverseNetwork(Node* n_node, NetworkProcess* n_process)
{
    m_network.applyOn(n_node,n_process);
}

void Brain::traverseLinkGraph(LinkNode* n_link_node, LinkProcess* n_process)
{
    m_links.applyOn(n_link_node,n_process);
}

Node* Brain::getEntity(const Word& n_word)
{
    FindThing t_process(n_word,true);

    m_network.applyOnAllVertices(&t_process);

    return t_process.thingNode();
}

Node* Brain::createEntityFromWord(const Word& n_word)
{
    Node* t_entity_node=0;

    t_entity_node=getEntity(n_word);

    if(!t_entity_node)
    {
        t_entity_node=m_network.addVertice(Thing(n_word.str_base,true));
    }

    return t_entity_node;
}

Node* Brain::createThingFromWord(const Word& n_word)
{
    Node* t_entity_node=0;
    Node* t_thing_node=0;

    t_entity_node=createEntityFromWord(n_word);

    t_thing_node=m_network.addVertice(Thing(n_word.str_base,false));

    LinkNode* t_link_node=m_links.esti();
    t_thing_node->addOutputEdge(RelationContent(t_link_node),t_entity_node);

    return t_thing_node;
}

Node* Brain::createThingFromEntity(Node* n_entity_node)
{
    Node* t_thing_node=0;

    t_thing_node=m_network.addVertice(Thing(n_entity_node->content().str(),false));

    LinkNode* t_link_node=m_links.esti();
    t_thing_node->addOutputEdge(RelationContent(t_link_node),n_entity_node);

    return t_thing_node;
}

LinkNode* Brain::getLink(const Link& n_link)
{
    FindLink t_process(n_link);

    m_links.applyOnAllVertices(&t_process);

    return t_process.linkNode();
}

LinkNode* Brain::createLinkNode(const Link& n_link)
{
    LinkNode* t_node=0;

    t_node=getLink(n_link);

    if(!t_node)
    {
        t_node=m_links.addLinkNode(n_link);
    }

    return t_node;
}

void Brain::dump() const
{
    std::string t_out;
    t_out=m_network.toDot();
    std::cout << t_out << std::endl;

    std::ofstream t_file;
    t_file.open("brain.dot");
    t_file << t_out;
    t_file.close();
}
