#ifndef SAY_LINK_H
#define SAY_LINK_H

#include "commandlink.h"
#include "handler.h"
#include "mouth.h"

class SayThingHandler: public Handler
{
    public:

        SayThingHandler()
        {
            m_handables.push_back("io");
        }

        virtual void handle(Node* n_node)
        {
            Mouth::speak(n_node->content().str());
        }
};

class SayLink: public CommandLink
{
    public:

        SayLink(Brain& n_brain):
            CommandLink(n_brain)
        {
            m_verb = "diri";
            m_handlers.push_back(new SayThingHandler());
            searchNewHandlers();
        }
};

#endif
