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
            SPECIAL_THING,
            LINK
        };

        NodeContent(){}

        enum Type type() const;

    protected:

        enum Type m_type;
};

#endif // NODECONTENT_H
