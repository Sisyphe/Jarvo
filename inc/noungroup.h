#ifndef NOUNGROUP_H
#define NOUNGROUP_H

#include "wordgroup.h"

class NounGroup: public WordGroup
{
    public:

        NounGroup();

        virtual std::string str() const;
        std::vector<std::string> getQualifierStrings() const;

        using WordGroup::preposition;

        using WordGroup::addNounComplement;
        using WordGroup::addAdverbComplement;
        using WordGroup::addAdjectiveComplement;

        using WordGroup::nounComplements;
        using WordGroup::adverbComplements;
        using WordGroup::adjectiveComplements;

    protected:

        bool is_determinate;
};

#endif // NOUNGROUP_H
