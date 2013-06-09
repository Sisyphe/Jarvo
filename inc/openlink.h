#ifndef OPENLINK_H
#define OPENLINK_H

#include "link.h"
#include "handler.h"
#include "brain.h"

class OpenLink: public Link
{
    public:

        OpenLink(Brain& n_brain);
        virtual ~OpenLink(){}

        Handler* getHandler(Node* n_node) const;
        virtual bool tryToHandle(const Relation& n_relation);

    protected:

        std::string m_verb;
        Brain& m_brain;
        std::map<Node*,Handler*> m_handable_things;
        std::list<Handler*> m_handlers;
};

#endif // OPENLINK_H
