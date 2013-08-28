#ifndef OPENFOLDERACTION_H
#define OPENFOLDERACTION_H

#include <handler.h>

class OpenFolderAction: public Handler
{
    public:

        OpenFolderAction();
        virtual void handle(Node* n_node);
};

#endif // OPENFOLDERACTION_H
