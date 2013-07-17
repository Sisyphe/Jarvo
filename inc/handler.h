#ifndef HANDLER_H
#define HANDLER_H

#include "node.h"
#include <list>
#include <string>

class Handler
{
    public:

        virtual ~Handler(){}
        virtual void handle(ThingNode* n_node)=0;
        virtual const std::list<std::string>& handable() const;

    protected:

        std::list<std::string> m_handables;
};

#endif // HANDLER_H
