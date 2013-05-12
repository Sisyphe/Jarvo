#ifndef ADJECTIVE_H
#define ADJECTIVE_H

#include "word.h"
#include <node.h>

class Adjective : public Word
{
    public:

        Adjective(Node* n_property=0);

        Adjective(const std::string& n_str, Node* n_property=0);

        void setPropertyNode(Node* n_property);

        Node* propertyNode() const;

    protected:

        Node* m_property;
        Word::Type m_type;
};

#endif // ADJECTIVE_H
