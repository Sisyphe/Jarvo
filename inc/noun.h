#ifndef NAME_H
#define NAME_H

#include "word.h"
#include <node.h>

class Noun : public Word
{
    public:

        Noun(Node* n_thing=0);
        Noun(const std::string& n_str, Node* n_thing=0);

        void setThingNode(Node* n_thing);
        Node* thingNode() const;

        virtual Noun* get();

    protected:

        Node* m_thing;
        Word::Type m_type;
};

#endif // NAME_H
