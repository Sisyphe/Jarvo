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
        virtual bool tryToHandle(Node* n_node);

    protected:

        virtual Handler* getHandler(Node* n_node) const;

        std::map<Node*,Handler*> m_handable_things;
        std::list<Handler*> m_handlers;
        Brain& m_brain;

};

#endif // COMMANDLINK_H
