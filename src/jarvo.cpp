#include "jarvo.h"
#include "findthing.h"
#include "findpath.h"
#include <fstream>

Jarvo::Jarvo()
{
    say("Saluton mastro.");
}

void Jarvo::feed(const std::string& n_input)
{
    Sentence t_sentence;

    std::cout << "Input: " << n_input << std::endl;

    m_parser.parse(t_sentence,n_input);

    if(t_sentence.isInterrogative())
    {
        if(t_sentence.isPolarQuestion())
        {
            processPolarQuestion(t_sentence);
        }
    }
    else if(t_sentence.verb() && t_sentence.verb()->tense == Word::JUSSIVE)
    {
        processCommand(t_sentence);
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
    WordGroup t_object_group = n_sentence.objectGroup();

    if(!n_sentence.verbGroup().isEmpty())
    {
        t_link_node = n_sentence.verb()->link_node;

        if(!t_link_node)
        {
            t_link_node = m_brain.getOrCreateLinkNode(Link(n_sentence.verb()->str_base));
            n_sentence.verb()->link_node = t_link_node;
        }

        if(!n_sentence.subjectGroup().isEmpty())
        {
            t_subject_node = m_brain.getOrCreateNode(n_sentence.subjectGroup());
        }

        if(!t_object_group.isEmpty())
        {
            if(!t_object_group.isDeterminate() && *t_link_node->content() == Link::isLink)
            {
                t_object_group.setGeneral(true);
            }

            t_object_node = m_brain.getOrCreateNode(t_object_group);
        }

        t_subject_node->addOutputEdge(RelationContent(t_link_node),t_object_node);
    }
}

void Jarvo::processPolarQuestion(Sentence& n_sentence)
{
    Node* t_subject_node=0;
    Node* t_object_node=0;
    LinkNode* t_link_node=0;
    bool t_error=false;
    bool t_is_relation_found=false;
    WordGroup t_object_group = n_sentence.objectGroup();

    if(!n_sentence.verbGroup().isEmpty())
    {
        t_link_node = n_sentence.verb()->link_node;

        if(!t_link_node)
        {
            t_link_node = m_brain.getOrCreateLinkNode(Link(n_sentence.verb()->str_base));
            n_sentence.verb()->link_node = t_link_node;
            say("Ne. Mi ne sciis kio estas " + n_sentence.verb()->str_base + ".");
            t_error=true;
        }
    }
    else t_error=true;

    if(!n_sentence.subjectGroup().isEmpty())
    {
        if(!n_sentence.subject()->node)
        {
            say("Ne. Mi ne sciis kio estas " + n_sentence.subject()->str_base + ".");
            t_error=true;
        }
        t_subject_node = m_brain.getOrCreateNode(n_sentence.subjectGroup());
    }
    else t_error=true;

    if(!t_object_group.isEmpty())
    {
        if(!t_object_group.mainWord()->node)
        {
            say("Ne. Mi ne sciis kio estas " + t_object_group.mainWord()->str_base + ".");
            t_error=true;
        }

        if(!t_object_group.isDeterminate() && *t_link_node->content() == Link::isLink)
        {
            t_object_group.setGeneral(true);
        }

        t_object_node = m_brain.getOrCreateNode(t_object_group);
    }

    if(!t_error)
    {
        t_is_relation_found = m_brain.pathExists
        (
            t_subject_node,
            *t_link_node->content(),
            t_object_node
        );

        if(t_is_relation_found)
        {
            say("Je.");
        }
        else
        {
            say("Ne.");
        }
    }
}

void Jarvo::processCommand(Sentence& n_sentence)
{
    Node* t_object_node=0;
    LinkNode* t_link_node=0;
    bool t_error=false;

    /*if(n_sentence.object())
    {
        t_object_node=n_sentence.object()->node;

        if(!t_object_node)
        {
            t_object_node=m_brain.getOrCreateEntity(*n_sentence.object());
            n_sentence.object()->node=t_object_node;
        }
    }*/

    if(n_sentence.verb())
    {
        t_link_node=n_sentence.verb()->link_node;

        if(!t_link_node)
        {
            Link t_link(n_sentence.verb()->str_base);

            t_link_node=m_brain.getLinkNode(t_link);

            if(!t_link_node)
            {
                say("Pardonu. Mi ne scias kiel " + n_sentence.verb()->str_base + ".");
                t_error=true;
            }

            n_sentence.verb()->link_node=t_link_node;
        }
    }

    if(!t_error)
    {
        say("Mi provas " + n_sentence.verb()->str_base + " ĝin...");

        if(t_link_node->content()->tryToHandle(t_object_node))
        {
            say("Mi " + n_sentence.verb()->str_base + "s ĝin !");
        }
        else
        {
            say("Pardonu. Mi ne scias kiel " + n_sentence.verb()->str_base + " ĝin.");
        }
    }
}

void Jarvo::say(const std::string& n_str)
{
    std::cout << "- " << n_str << std::endl;
    Mouth::speak(n_str);
}

void Jarvo::dumpBrain() const
{
    m_brain.dump();
}
