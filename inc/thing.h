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
        Thing(const std::string& n_str,bool n_is_entity=true);

        std::string str() const;
        bool isEntity() const;

        friend std::ostream& operator<<(std::ostream& n_out, const Thing& n_thing)
        {
            n_out << "Thing";
            if(n_thing.isEntity()) n_out << "*";
            n_out << ": " << n_thing.str();
            return n_out;
        }

    protected:

        enum NodeContent::Type m_type;
        std::string m_str;
        bool m_is_entity;
};

#endif // THING_H
