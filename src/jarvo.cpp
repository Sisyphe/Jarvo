#include "jarvo.h"
#include "findthing.h"
#include "findconnection.h"
#include <fstream>

Jarvo::Jarvo()
{
    say("Saluton mastro.");
}

Node* Jarvo::getEntity(const Word& n_word)
{
    FindThing t_process(n_word,true);

    m_network.applyOnAllVertices(&t_process);

    return t_process.thingNode();
}

Node* Jarvo::createEntityFromWord(const Word& n_word)
{
    Node* t_entity_node=0;

    t_entity_node=getEntity(n_word);

    if(!t_entity_node)
    {
        t_entity_node=m_network.addVertice(Thing(n_word.str_base,true));
    }

    return t_entity_node;
}

Node* Jarvo::createThingFromWord(const Word& n_word)
{
    Node* t_entity_node=0;
    Node* t_thing_node=0;

    t_entity_node=createEntityFromWord(n_word);

    t_thing_node=m_network.addVertice(Thing(n_word.str_base,false));

    LinkNode* t_link_node=m_links.esti();
    t_thing_node->addOutputEdge(RelationContent(t_link_node),t_entity_node);

    return t_thing_node;
}

Node* Jarvo::createThingFromEntity(Node* n_entity_node)
{
    Node* t_thing_node=0;

    t_thing_node=m_network.addVertice(Thing(n_entity_node->content().str(),false));

    LinkNode* t_link_node=m_links.esti();
    t_thing_node->addOutputEdge(RelationContent(t_link_node),n_entity_node);

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

void Jarvo::processStatement(Sentence& n_sentence)
{
    Node* t_subject_node=0;
    Node* t_object_node=0;
    LinkNode* t_link_node=0;

    if(n_sentence.subject)
    {
        t_subject_node=n_sentence.subject->node;

        if(!t_subject_node)
        {
            t_subject_node=createEntityFromWord(*n_sentence.subject);
            n_sentence.subject->node=t_subject_node;
            if(!n_sentence.subject_is_entity)
            {
                t_subject_node=createThingFromEntity(t_subject_node);
            }
        }
    }

    if(n_sentence.object)
    {
        t_object_node=n_sentence.object->node;

        if(!t_object_node)
        {
            t_object_node=createEntityFromWord(*n_sentence.object);
            n_sentence.object->node=t_object_node;

            if(n_sentence.verb->str_base == "esti")
            {
                if(!n_sentence.subject_is_entity && !n_sentence.object_is_entity)
                {
                    t_object_node=createThingFromEntity(t_object_node);
                }
            }
            else
            {
                if(!n_sentence.subject_is_entity || !n_sentence.object_is_entity)
                {
                    t_object_node=createThingFromEntity(t_object_node);
                }
            }
        }
    }

    if(n_sentence.verb)
    {
        t_link_node=n_sentence.verb->link_node;

        if(!t_link_node)
        {
            Link t_link(n_sentence.verb->str_base);

            t_link_node=m_links.findLinkNode(t_link.verb());

            if(!t_link_node)
            {
                t_link_node=m_links.addLinkNode(t_link);
                n_sentence.verb->link_node=t_link_node;
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
    bool t_error=false;

    if(t_sentence.subject)
    {
        t_subject_node=t_sentence.subject->node;

        if(!t_subject_node)
        {
            say("Ne. Mi ne sciis kio estas " + t_sentence.subject->str_base + ".");
            t_subject_node=createThingFromWord(*t_sentence.subject);
            t_sentence.subject->node=t_subject_node;
            t_error=true;
        }
    }

    if(t_sentence.object)
    {
        t_object_node=t_sentence.object->node;

        if(!t_object_node)
        {
            say("Ne. Mi ne sciis kio estas " + t_sentence.object->str_base + ".");
            t_object_node=createThingFromWord(*t_sentence.object);
            t_sentence.object->node=t_object_node;
            t_error=true;
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
                t_sentence.verb->link_node=t_link_node;
                t_error=true;
            }
        }
    }

    if(!t_error)
    {
        FindConnection t_finder(t_object_node,*t_link_node->content());
        m_network.postfixedTraversalOf(t_subject_node,Node::OUTPUT,&t_finder);
        if(t_finder.isConnectionFound())
        {
            say("Je.");
        }
        else
        {
            say("Ne.");
        }
    }
}

void Jarvo::say(const std::string& n_str)
{
    std::cout << "- " << n_str << std::endl;
    m_mouth.speak(n_str);
}

void Jarvo::dumpBrain() const
{
    std::string t_out;
    t_out=m_network.toDot();
    std::cout << t_out << std::endl;

    std::ofstream t_file;
    t_file.open("brain.dot");
    t_file << t_out;
    t_file.close();
}
