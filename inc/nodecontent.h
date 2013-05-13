#ifndef NODECONTENT_H
#define NODECONTENT_H

#include <string>

class NodeContent
{
    public:

        enum Type
        {
            ENTITY,
            THING,
            PROPERTY,
            ACTION
        };

        NodeContent(){}

        enum Type type() const;

    protected:

        enum Type m_type;
};

#endif // NODECONTENT_H
