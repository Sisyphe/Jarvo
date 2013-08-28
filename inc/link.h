#ifndef LINK_H
#define LINK_H

#include "nodecontent.h"
#include "node.h"

class Link: public NodeContent
{
    public:

        Link(const std::string& n_verb = std::string());
        virtual ~Link() {}

        std::string verb() const;
        void setVerb(const std::string& n_verb);

        static Link isLink;

        friend std::ostream& operator<<(std::ostream& n_out, const Link& n_link);
        bool operator==(const Link& n_link) const;

        void addQualifier(const std::string& n_qualifier);
        void addAdverb(const std::string& n_adverb);

        virtual bool tryToHandle(Node* n_node);

    protected:

        std::string m_verb;
        std::vector<std::string> m_qualifiers;
        std::vector<std::string> m_adverbs;
        static Link isEntityOf;
        enum NodeContent::Type m_type;
};

#endif // LINK_H
