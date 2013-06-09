#include "openlink.h"
#include <algorithm>
#include "findconnection.h"
#include "findthing.h"

OpenLink::OpenLink(Brain& n_brain)
    :m_verb("aperti"),
     m_brain(n_brain)
{
    Node* t_node=0;
    std::list<Handler*>::iterator it=m_handlers.begin();

    for(; it != m_handlers.end(); ++it)
    {
        std::list<std::string>::const_iterator str_it=(*it)->handable().begin();

        for(; str_it != (*it)->handable().end(); ++str_it)
        {
            t_node=m_brain.createEntityFromString(*str_it);
            m_handable_things.insert(std::pair<Node*,Handler*>(t_node,*it));
        }
    }
}

Handler* OpenLink::getHandler(Node* n_node) const
{
    bool t_found=false;
    std::map<Node*,Handler*>::const_iterator it=m_handable_things.begin();

    while(it != m_handable_things.end() && !t_found)
    {
        t_found=m_brain.findRelation(n_node,Link::isEquivalentLink,(*it).first);
        ++it;
    }

    return (t_found)? (*(it--)).second : 0;
}

bool OpenLink::tryToHandle(const Relation& n_relation)
{
    bool t_is_handled=false;
    Handler* t_handler=0;

    if(n_relation.outputVertice()->content().str() == "vi")
    {
        t_handler=getHandler(n_relation.inputVertice());

        if(t_handler)
        {
            t_handler->handle(n_relation.inputVertice());
            t_is_handled=true;
        }
    }

    return t_is_handled;
}
