#ifndef COMMANDLINK_H
#define COMMANDLINK_H

#include "link.h"
#include "handler.h"
#include "brain.h"

class CommandLink: public Link
{
    public:

        CommandLink(Brain& n_brain);
        virtual void searchNewHandlers();
        virtual Handler* getHandler(ThingNode* n_node) const;
        virtual bool tryToHandle(ThingNode* n_node);

    protected:

        std::map<ThingNode*,Handler*> m_handable_things;
        std::list<Handler*> m_handlers;
        Brain& m_brain;

};

#endif // COMMANDLINK_H
