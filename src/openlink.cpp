#include "openlink.h"
#include <algorithm>
#include "findconnection.h"
#include "findthing.h"
#include "openfileaction.h"

OpenLink::OpenLink(Brain& n_brain)
    :m_brain(n_brain)
{
    m_verb="aperti";
    m_handlers.push_back(new OpenFileAction());

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
        FindConnection t_finder((*it).first,Link::isEquivalentLink);
        m_brain.traverseNetwork(&t_finder,n_node);
        t_found=t_finder.isConnectionFound();
        if(!t_found) ++it;
    }

    return (t_found)? (*it).second : 0;
}

bool OpenLink::tryToHandle(Node *n_node)
{
    bool t_is_handled=false;
    Handler* t_handler=0;

    t_handler=getHandler(n_node);

    if(t_handler)
    {
        t_handler->handle(n_node);
        t_is_handled=true;
    }

    return t_is_handled;
}
