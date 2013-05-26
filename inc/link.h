#ifndef LINK_H
#define LINK_H

#include "nodecontent.h"

class Link : public NodeContent
{
    public:

        struct Comp
        {
            bool operator() (const Link& lhs, const Link& rhs) const
            {
                return lhs.verb() < rhs.verb();
            }
        };

        Link(const std::string& n_verb=std::string());

        std::string verb() const;
        void setVerb(const std::string& n_verb);

    protected:

        std::string m_verb;
        static Link isEntityOf;
        enum NodeContent::Type m_type;
};

#endif // LINK_H
