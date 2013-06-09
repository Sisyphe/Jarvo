#ifndef OPENFILEACTION_H
#define OPENFILEACTION_H

#include <handler.h>

class OpenFileAction: public Handler
{
    public:

        OpenFileAction();
        virtual void handle(Node* n_node);

    protected:

        std::list< std::string> m_handables;

};

#endif // OPENFILEACTION_H
