#include "jarvo.h"
#include "findthing.h"
#include "findconnection.h"

Jarvo::Jarvo()
{
    say("Saluton mastro.");
}

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

    std::cout << "Input: " << n_input << std::endl;

    m_parser.parse(t_sentence,n_input);

    if(t_sentence.is_interrogative)
    {
        if(t_sentence.is_yes_no_question)
        {
            processYesNoQuestion(t_sentence);
        }
    }
    else
    {
        processStatement(t_sentence);
    }
}

void Jarvo::processStatement(Sentence& t_sentence)
{
    Node* t_subject_node=0;
    Node* t_object_node=0;
    LinkNode* t_link_node=0;

    if(t_sentence.subject)
    {
        t_subject_node=t_sentence.subject->node;

        if(!t_subject_node)
        {
            t_subject_node=createThingFromWord(*t_sentence.subject);
            t_sentence.subject->node=t_subject_node;
        }
    }

    if(t_sentence.object)
    {
        t_object_node=t_sentence.object->node;

        if(!t_object_node)
        {
            t_object_node=createThingFromWord(*t_sentence.object);
            t_sentence.object->node=t_object_node;
        }
    }

    if(t_sentence.verb)
    {
        t_link_node=t_sentence.verb->link_node;

        if(!t_link_node)
        {
            Link t_link(t_sentence.verb->str_base);

            t_link_node=m_links.findLinkNode(t_link.verb());

            if(!t_link_node)
            {
                t_link_node=m_links.addLinkNode(t_link);
            }

            //t_link_node->content().triggerOn(t_subject_node,t_object_node);
            t_subject_node->addOutputEdge(RelationContent(t_link_node),t_object_node);
        }
    }
}

void Jarvo::processYesNoQuestion(Sentence& t_sentence)
{
    Node* t_subject_node=0;
    Node* t_object_node=0;
    LinkNode* t_link_node=0;

    if(t_sentence.subject)
    {
        t_subject_node=t_sentence.subject->node;

        if(!t_subject_node)
        {
            m_mouth.speak("Mi ne sciis kio estas " + t_sentence.subject->str_base + ".");
        }
    }

    if(t_sentence.object)
    {
        t_object_node=t_sentence.object->node;

        if(!t_object_node)
        {
            m_mouth.speak("Mi ne sciis kio estas " + t_sentence.object->str_base + ".");
        }
    }

    if(t_sentence.verb)
    {
        t_link_node=t_sentence.verb->link_node;

        if(!t_link_node)
        {
            Link t_link(t_sentence.verb->str_base);

            t_link_node=m_links.findLinkNode(t_link.verb());

            if(!t_link_node)
            {
                say(t_sentence.subject->str + " ne " + t_sentence.verb->str + " " + t_sentence.object->str);
                t_link_node=m_links.addLinkNode(t_link);
            }

            //t_link_node->content().triggerOn(t_subject_node,t_object_node);
        }
    }

    FindConnection t_finder(t_object_node,*t_link_node->content());
    m_network.applyOnOutputVertices(t_subject_node,&t_finder);
    if(t_finder.isConnectionFound())
    {
        say("Je.");
    }
    else
    {
        say("Ne.");
    }
}

void Jarvo::say(const std::string& n_str)
{
    std::cout << "- " << n_str << std::endl;
    m_mouth.speak(n_str);
}

void Jarvo::dumpBrain() const
{
    std::cout << m_network.toDot() << std::endl;
}
