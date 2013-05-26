#include "jarvo.h"
#include "findthing.h"

Node* Jarvo::createThingFromWord(const Word& n_word)
{
    Node* t_thing_node=0;
    Node* t_entity_node=0;
    FindThing t_process(n_word);

    m_network.applyOnAllVertices(&t_process);
    if(t_process.isThingFound())
    {
        t_thing_node=m_network.addVertice(Thing(n_word.str_base,false));
    }
    else t_thing_node=t_process.thingNode();

//    t_entity_node=m_network.addVertice(Thing(n_word.str_base));

//    LinkNode* t_link_node=m_links.esti();
//    m_network.addEdge(RelationContent(t_link_node),t_entity_node,t_thing_node);

    return t_thing_node;
}

void Jarvo::feed(const std::string& n_input)
{
    Sentence t_sentence;
    Node* t_subject_node=0;
    Node* t_object_node=0;
    LinkNode* t_link_node=0;

    m_parser.parse(t_sentence,n_input);

    if(t_sentence.subject)
    {
        t_subject_node=t_sentence.subject->node;

        if(!t_subject_node)
        {
            t_subject_node=createThingFromWord(*t_sentence.subject);
        }
    }

    if(t_sentence.object)
    {
        t_object_node=t_sentence.object->node;

        if(!t_object_node)
        {
            t_object_node=createThingFromWord(*t_sentence.object);
        }
    }

    if(t_sentence.verb)
    {
        t_link_node=t_sentence.verb->link_node;

        if(!t_link_node)
        {
            Link t_link(t_sentence.verb->str_base);

            t_link_node=m_links.findLinkNode(t_link);

            if(!t_link_node)
            {
                t_link_node=m_links.addLinkNode(t_link);
            }

            //t_link_node->content().triggerOn(t_subject_node,t_object_node);
            m_network.addEdge(RelationContent(t_link_node),t_subject_node,t_object_node);
        }
    }
}

void Jarvo::dumpBrain() const
{
    std::cout << m_network.toDot() << std::endl;
}
