#ifndef LINK_H
#define LINK_H

#include "nodecontent.h"
#include "node.h"

class Link : public NodeContent
{
    public:

        /*struct Comp
        {
            bool operator() (const Link& lhs, const Link& rhs) const
            {
                return lhs.verb() < rhs.verb();
            }
        };*/

        Link(const std::string& n_verb=std::string());
        virtual ~Link(){}

        std::string verb() const;
        void setVerb(const std::string& n_verb);

        static Link isEquivalentLink;

        friend std::ostream& operator<<(std::ostream& n_out, const Link& n_link)
        {
            std::vector<std::string>::const_iterator it;

            n_out << n_link.verb();

            for(it = n_link.m_adverbs.begin(); it != n_link.m_adverbs.end(); ++it)
            {
                n_out << " " << (*it);
            }

            for(it = n_link.m_qualifiers.begin(); it != n_link.m_qualifiers.end(); ++it)
            {
                n_out << " " << (*it);
            }

            return n_out;
        }

        bool operator== (const Link& n_link) const
        {
            bool t_is_verb_equal;
            bool t_is_found = true;
            std::vector<std::string>::const_iterator it, jt;

            t_is_verb_equal = (m_verb == n_link.verb());

            if(t_is_verb_equal)
            {
                it = m_qualifiers.begin();
                if(m_qualifiers.empty() && !n_link.m_qualifiers.empty())
                {
                    t_is_found = false;
                }
                while(t_is_found && it != m_qualifiers.end())
                {
                    t_is_found = false;
                    jt = n_link.m_qualifiers.begin();
                    while(!t_is_found && jt != n_link.m_qualifiers.end())
                    {
                        t_is_found = ((*it) == (*jt));
                        ++jt;
                    }
                    ++it;
                }

                if(t_is_found)
                {
                    it = m_adverbs.begin();
                    if(m_adverbs.empty() && !n_link.m_adverbs.empty())
                    {
                        t_is_found = false;
                    }
                    while(t_is_found && it != m_adverbs.end())
                    {
                        t_is_found = false;
                        jt = n_link.m_adverbs.begin();
                        while(!t_is_found && jt != n_link.m_adverbs.end())
                        {
                            t_is_found = ((*it) == (*jt));
                            ++jt;
                        }
                        ++it;
                    }
                }
            }

            return t_is_verb_equal && t_is_found;
        }

        void addQualifier(const std::string& n_qualifier);
        void addAdverb(const std::string& n_adverb);

        virtual bool tryToHandle(Node* n_node) {return false;}

    protected:

        std::string m_verb;
        std::vector<std::string> m_qualifiers;
        std::vector<std::string> m_adverbs;
        static Link isEntityOf;
        enum NodeContent::Type m_type;
};

#endif // LINK_H
