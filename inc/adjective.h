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

        void setPropertyNode(Node* n_property);
        Node* propertyNode() const;

        Noun* object() const;
        void setObject(Noun* n_object);

        virtual Adjective* get();

    protected:

        Node* m_property;
        Word::Type m_type;
        Noun* m_object;
};

#endif // ADJECTIVE_H
