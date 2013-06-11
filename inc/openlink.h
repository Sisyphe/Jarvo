#ifndef OPENLINK_H
#define OPENLINK_H

#include "commandlink.h"

class OpenLink: public CommandLink
{
    public:

        OpenLink(Brain& n_brain);
        virtual ~OpenLink(){}
};

#endif // OPENLINK_H
