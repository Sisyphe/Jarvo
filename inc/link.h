#ifndef LINK_H
#define LINK_H

#include "nodecontent.h"
#include "node.h"

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
        virtual ~Link(){}

        std::string verb() const;
        void setVerb(const std::string& n_verb);

        static Link isEquivalentLink;

        friend std::ostream& operator<<(std::ostream& n_out, const Link& n_link)
        {
            n_out << n_link.verb();
            return n_out;
        }

        bool operator==(const Link& n_link) const
        {
            return m_verb == n_link.verb();
        }

        virtual bool tryToHandle(ThingNode* n_node) {return false;}

    protected:

        std::string m_verb;
        static Link isEntityOf;
        enum NodeContent::Type m_type;
};

#endif // LINK_H
