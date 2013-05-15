#ifndef NAME_H
#define NAME_H

#include "word.h"
#include <node.h>

class Noun : public Word
{
    public:

        Noun(Node* n_thing=0);
        Noun(const std::string& n_str, Node* n_thing=0);
        virtual ~Noun(){}

        void setThingNode(Node* n_thing);
        Node* thingNode() const;

    protected:

        Node* m_thing;
};

#endif // NAME_H
