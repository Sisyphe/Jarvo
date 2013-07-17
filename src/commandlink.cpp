#include "commandlink.h"
#include "findpath.h"
#include "findthing.h"

CommandLink::CommandLink(Brain& n_brain)
    :m_brain(n_brain){}

void CommandLink::searchNewHandlers()
{
    ThingNode* t_node=0;
    std::list<Handler*>::iterator it=m_handlers.begin();

    for(; it != m_handlers.end(); ++it)
    {
        std::list<std::string>::const_iterator str_it=(*it)->handable().begin();

        for(; str_it != (*it)->handable().end(); ++str_it)
        {
            t_node=m_brain.getOrCreateEntity(*str_it);
            m_handable_things.insert(std::pair<ThingNode*,Handler*>(t_node,*it));
        }
    }
}

Handler* CommandLink::getHandler(ThingNode* n_node) const
{
    bool t_found=false;
    std::map<ThingNode*,Handler*>::const_iterator it=m_handable_things.begin();

    while(it != m_handable_things.end() && !t_found)
    {
        FindPath t_finder((*it).first,Link::isEquivalentLink);
        m_brain.traverseNetwork(&t_finder,n_node);
        t_found=t_finder.isPathFound();
        if(!t_found) ++it;
    }

    return (t_found)? (*it).second : 0;
}

bool CommandLink::tryToHandle(ThingNode *n_node)
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

