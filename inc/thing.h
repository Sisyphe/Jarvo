#ifndef THING_H
#define THING_H

#include "nodecontent.h"
#include <string>
#include <iostream>

class Entity;

class Thing : public NodeContent
{
    public:

        Thing();

        std::string str() const;

        friend std::ostream& operator<<(std::ostream& n_out, const Thing& n_thing)
        {
            n_out << "Thing: " << n_thing.word();
            return n_out;
        }

    protected:

        enum NodeContent::Type m_type;

        std::string m_str;
};

#endif // THING_H
