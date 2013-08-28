#ifndef OPENLINK_H
#define OPENLINK_H

#include "commandlink.h"

class OpenLink: public CommandLink
{
    public:
        OpenLink(Brain& n_brain);
};

#endif // OPENLINK_H
