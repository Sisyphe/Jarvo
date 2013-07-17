#ifndef OPENFILEACTION_H
#define OPENFILEACTION_H

#include "handler.h"

class OpenFileAction: public Handler
{
    public:

        OpenFileAction();
        virtual void handle(ThingNode* n_node);
};

#endif // OPENFILEACTION_H
