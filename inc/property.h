#ifndef PROPERTY_H
#define PROPERTY_H

#include "nodecontent.h"
#include <iostream>

class Property : public NodeContent
{
    public:

        Property();

        std::string str() const;

        friend std::ostream& operator<<(std::ostream& n_out, const Property& n_property)
        {
            n_out << "Property: " << n_property.word();
            return n_out;
        }

    protected:

        enum NodeContent::Type m_type;

        std::string m_str;
};

#endif // PROPERTY_H
