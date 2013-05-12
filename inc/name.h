#ifndef NAME_H
#define NAME_H

#include "word.h"
#include <node.h>

class Name : public Word
{
    public:

        Name(Node* n_thing=0);

        Name(const std::string& n_str, Node* n_thing=0);

        void setThingNode(Node* n_thing);

        Node* thingNode() const;

    protected:

        Word::Type m_type;
};

#endif // NAME_H
