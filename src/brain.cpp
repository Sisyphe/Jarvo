#include "brain.h"
#include "findlink.h"
#include "findthing.h"
#include "findpath.h"
#include <fstream>
#include "openlink.h"
#include "saylink.h"

Brain::Brain()
{
    m_io=m_network.addVertice(Thing("io",NodeContent::ENTITY));
    m_links.addVertice(new OpenLink(*this));
    m_links.addVertice(new SayLink(*this));
}

Brain::~Brain(){}

bool Brain::connectNodes(Node* n_out_node, LinkNode* n_link_node, Node* n_in_node)
{
    n_out_node->addOutputEdge(RelationContent(n_link_node),n_in_node);
    return true;
}

bool Brain::pathExists(Node* n_out_node, const Link& n_link, Node* n_in_node)
{
    FindPath t_finder(n_in_node,n_link);
    traverseNetwork(&t_finder,n_out_node);
    return t_finder.isPathFound();
}

void Brain::traverseNetwork(NetworkProcess* n_process, Node* n_node)
{
    m_network.applyOn(n_node,n_process);
}

void Brain::traverseLinkGraph(LinkProcess* n_process, LinkNode* n_link_node)
{
    m_links.applyOn(n_link_node,n_process);
}

Node* Brain::getEntity(const Word& n_word)
{
    return getEntity(n_word.str_base);
}

Node* Brain::getEntity(const std::string& n_str)
{
    FindThing t_process(n_str,NodeContent::ENTITY);

    m_network.applyOnAllVertices(&t_process);

    return t_process.thingNode();
}

Node* Brain::getOrCreateEntity(const Word& n_word)
{
    return getOrCreateEntity(n_word.str_base);
}

Node* Brain::getOrCreateEntity(const std::string& n_str)
{
    Node* t_entity_node=0;

    t_entity_node=getEntity(n_str);

    if(!t_entity_node)
    {
        t_entity_node=createEntity(n_str);
    }

    return t_entity_node;
}

Node* Brain::createEntity(const Word& n_word)
{
    return createEntity(n_word.str_base);
}

Node* Brain::createEntity(const std::string& n_str)
{
    Node* t_entity_node=m_network.addVertice(Thing(n_str,NodeContent::ENTITY));
    connectNodes(t_entity_node,m_links.esti(),m_io);
    return t_entity_node;
}

Node* Brain::getOrCreateThing(const Word& n_word)
{
    Node* t_entity_node=0;
    Node* t_thing_node=0;

    t_entity_node=getOrCreateEntity(n_word);

    t_thing_node=m_network.addVertice(Thing(n_word.str_base));

    LinkNode* t_link_node=m_links.esti();
    connectNodes(t_thing_node,t_link_node,t_entity_node);

    return t_thing_node;
}

Node* Brain::createInstanceOf(Node* n_entity_node)
{
    Node* t_thing_node=0;

    t_thing_node=m_network.addVertice(Thing(n_entity_node->content().str()));

    LinkNode* t_link_node=m_links.esti();
    connectNodes(t_thing_node,t_link_node,n_entity_node);

    return t_thing_node;
}

Node* Brain::getOrCreateSpecialThing(const Word& n_word)
{
    Node* t_thing_node=0;
    FindThing t_process(n_word.str_base, NodeContent::SPECIAL_THING);

    m_network.applyOnAllVertices(&t_process);

    if(t_process.isThingFound())
    {
        t_thing_node=t_process.thingNode();
    }
    else
    {
        t_thing_node=m_network.addVertice(Thing(n_word.str_base, NodeContent::SPECIAL_THING));
        connectNodes(t_thing_node,m_links.esti(),m_io);
    }

    return t_thing_node;
}

Node* Brain::createSpecialInstanceOf(Node* n_entity_node)
{
    Node* t_thing_node=0;

    t_thing_node=m_network.addVertice(Thing(n_entity_node->content().str(),NodeContent::SPECIAL_THING));

    LinkNode* t_link_node=m_links.esti();
    connectNodes(t_thing_node,t_link_node,n_entity_node);

    return t_thing_node;
}

Node* Brain::getOrCreateNode(Word* n_word, bool need_instance)
{
    Node* t_node=n_word->node;

    if(!t_node)
    {
        if(n_word->is_special)
        {
            t_node = getOrCreateSpecialThing(*n_word);
        }
        else
        {
            t_node = getOrCreateEntity(n_word->str_base);
        }

        n_word->node = t_node;
    }

    if(need_instance)
    {
        t_node = createInstanceOf(t_node);
    }

    return t_node;
}

LinkNode* Brain::getLink(const Link& n_link)
{
    FindLink t_process(n_link);

    m_links.applyOnAllVertices(&t_process);

    return t_process.linkNode();
}

LinkNode* Brain::getOrCreateLinkNode(const Link& n_link)
{
    LinkNode* t_node=0;

    t_node=getLink(n_link);

    if(!t_node)
    {
        t_node=createLinkNode(n_link);
    }

    return t_node;
}

LinkNode* Brain::createLinkNode(const Link& n_link)
{
    return m_links.addLinkNode(n_link);
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
