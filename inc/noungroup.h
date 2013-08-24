#ifndef NOUNGROUP_H
#define NOUNGROUP_H

#include "wordgroup.h"

class NounGroup: public WordGroup
{
    public:

        NounGroup();

        virtual std::string str() const;
        bool isDeterminate() const;
        void setDeterminate(bool n_is_determinate);

        using WordGroup::preposition;
        using WordGroup::setPreposition;

        virtual void addAsComplementTo(WordGroup& n_group);
        using WordGroup::addNounComplement;
        using WordGroup::addAdverbComplement;
        using WordGroup::addAdjectiveComplement;

        using WordGroup::nounComplements;
        using WordGroup::adverbComplements;
        using WordGroup::adjectiveComplements;

    protected:

        bool m_is_determinate;
};

#endif // NOUNGROUP_H
