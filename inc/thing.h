#ifndef THING_H
#define THING_H

#include "nodecontent.h"
#include <string>
#include <iostream>

class Entity;

class Thing : public NodeContent
{
    public:

        Thing(NodeContent::Type n_type = NodeContent::THING);
        Thing(const std::string& n_str, NodeContent::Type n_type = NodeContent::THING);

        std::string str() const;

        friend std::ostream& operator<<(std::ostream& n_out, const Thing& n_thing);

    protected:

        std::string m_str;
};

#endif // THING_H
