#ifndef OPEN_PROGRAM_ACTION_H
#define OPEN_PROGRAM_ACTION_H

#include "handler.h"
#include <stdlib.h>

class OpenProgramAction: public Handler
{
public:

    OpenProgramAction()
    {
        m_handables.push_back("programo");
    }

    virtual void handle(Node* n_node)
    {
        system(n_node->content().str().c_str());
    }
};

#endif
