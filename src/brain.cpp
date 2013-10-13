#include "brain.h"
#include "findlink.h"
#include "findthing.h"
#include "findpath.h"
#include <fstream>
#include "openlink.h"
#include "saylink.h"
#include <node.h>

Brain::Brain()
{
    m_io=m_network.addVertice(Thing("io",NodeContent::ENTITY));
    m_links.addVertice(new OpenLink(*this));
    m_links.addVertice(new SayLink(*this));
}

Brain::~Brain(){}

Relation* Brain::connectNodes(Node* n_out_node, LinkNode* n_link_node, Node* n_in_node)
{
    Relation* t_relation = 0;
    t_relation = n_out_node->addOutputEdge(RelationContent(n_link_node),n_in_node, true);
    return t_relation;
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

Node* Brain::getEntity(const std::string& n_str)
{
    FindThing t_process(n_str,NodeContent::ENTITY);

    m_network.applyOnAllVertices(&t_process);

    return t_process.thingNode();
}

Node* Brain::getOrCreateEntity(const WordGroup& n_word_group)
{
    Node* t_noun_node = 0;
    Node* t_specialized_node = 0;

    t_noun_node = getOrCreateEntity(n_word_group.mainWord()->str_base);

    n_word_group.mainWord()->node = t_noun_node;

    if(n_word_group.hasComplements())
    {
        t_specialized_node = getOrCreateEntity(n_word_group.str());

        Relation* t_relation = connectNodes(t_specialized_node, m_links.isLinkNode(), t_noun_node);
        t_relation->content().setType(RelationContent::SPECIALIZATION);

        addComplementsToNode(t_specialized_node, n_word_group.getComplements(WordGroup::ADJECTIVE));

        t_noun_node = t_specialized_node;
    }

    return t_noun_node;
}

Node* Brain::getOrCreateEntity(const std::string& n_str)
{
    Node* t_noun_node = 0;

    t_noun_node = getEntity(n_str);

    if(!t_noun_node) t_noun_node = createEntity(n_str);

    return t_noun_node;
}

Node* Brain::createEntity(const std::string& n_str)
{
    Node* t_entity_node=m_network.addVertice(Thing(n_str,NodeContent::ENTITY));
    connectNodes(t_entity_node,m_links.isLinkNode(),m_io);
    return t_entity_node;
}

Node* Brain::getOrCreateThing(const WordGroup& n_word_group)
{
    std::string t_str = n_word_group.mainWord()->str_base;
    Node* t_entity_node = 0;
    Node* t_thing_node = 0;

    t_entity_node = getOrCreateEntity(n_word_group);
    t_thing_node = createInstanceOf(t_entity_node);

    return t_thing_node;
}

Node* Brain::createInstanceOf(Node* n_entity_node)
{
    Node* t_thing_node=0;

    t_thing_node = m_network.addVertice(Thing(n_entity_node->content().str()));

    LinkNode* t_link_node = m_links.isLinkNode();
    connectNodes(t_thing_node,t_link_node,n_entity_node);

    return t_thing_node;
}

Node* Brain::getOrCreateSpecialThing(const WordGroup& n_word_group)
{
    Node* t_thing_node=0;
    Word n_word = *n_word_group.mainWord();
    FindThing t_process(n_word.str_base, NodeContent::SPECIAL_THING);

    m_network.applyOnAllVertices(&t_process);

    if(t_process.isThingFound())
    {
        t_thing_node=t_process.thingNode();
    }
    else
    {
        t_thing_node=m_network.addVertice(Thing(n_word.str_base, NodeContent::SPECIAL_THING));
        connectNodes(t_thing_node,m_links.isLinkNode(),m_io);
    }

    addComplementsToNode(t_thing_node, n_word_group.getComplements(WordGroup::ADJECTIVE));

    return t_thing_node;
}

Node* Brain::getOrCreateNode(const WordGroup& n_word_group)
{
    Node* t_noun_node = n_word_group.mainWord()->node;

    if(n_word_group.mainWord()->is_special)
    {
        t_noun_node = getOrCreateSpecialThing(n_word_group);
    }
    else
    {
        t_noun_node = getOrCreateEntity(n_word_group);
    }

    if(!n_word_group.mainWord()->node) n_word_group.mainWord()->node = t_noun_node;

    if(n_word_group.isDeterminate())
    {
        FindThing t_finder(n_word_group);
        traverseNetwork(&t_finder, t_noun_node);

        if(t_finder.isThingFound())
        {
            t_noun_node = t_finder.thingNode();
        }
        else
        {
            t_noun_node = createInstanceOf(t_noun_node);
        }
    }
    else if(!n_word_group.isGeneral() && !n_word_group.mainWord()->is_special)
    {
        t_noun_node = createInstanceOf(t_noun_node);
    }

    return t_noun_node;
}

LinkNode* Brain::getOrCreateLinkNode(const Link& n_link)
{
    LinkNode* t_node=0;

    t_node=getLinkNode(n_link);

    if(!t_node)
    {
        t_node=createLinkNode(n_link);
    }

    return t_node;
}

LinkNode* Brain::getLinkNode(const Link& n_link)
{
    FindLink t_process(n_link);

    m_links.applyOnAllVertices(&t_process);

    return t_process.linkNode();
}

LinkNode* Brain::createLinkNode(const Link& n_link)
{
    return m_links.addLinkNode(n_link);
}

void Brain::addComplementsToNode(Node* n_node, const std::vector<WordGroup>& n_complements)
{
    std::vector<WordGroup>::const_iterator t_complement = n_complements.begin();

    for(; t_complement != n_complements.end(); ++t_complement)
    {
        Link t_link("esti");
        t_link.addQualifier(t_complement->str());

        std::vector<WordGroup> t_adverbs(t_complement->getComplements(WordGroup::ADVERB));
        std::vector<WordGroup>::iterator t_adverb(t_adverbs.begin());

        for(; t_adverb != t_adverbs.end(); ++t_adverb)
        {
            t_link.addAdverb(t_adverb->str());
        }

        LinkNode* t_link_node = getOrCreateLinkNode(t_link);
        Relation* t_relation = connectNodes(n_node, t_link_node, n_node);
        t_relation->content().setType(RelationContent::FEATURE);
    }
}

void Brain::dump() const
{
    std::string t_out;
    t_out = m_network.toDot();
    std::cout << t_out << std::endl;

    std::ofstream t_file;
    t_file.open("brain.dot");
    t_file << t_out;
    t_file.close();
}
