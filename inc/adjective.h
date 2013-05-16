#ifndef ADJECTIVE_H
#define ADJECTIVE_H

#include "word.h"
#include <node.h>
#include "noun.h"

class Adjective : public Word
{
    public:

        Adjective(Node* n_property=0);
        Adjective(const std::string& n_str, Node* n_property=0);
        virtual ~Adjective(){}

        void setPropertyNode(Node* n_property);
        Node* propertyNode() const;

    protected:

        Node* m_property;
};

#endif // ADJECTIVE_H
