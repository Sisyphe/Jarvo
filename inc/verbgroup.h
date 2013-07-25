#ifndef VERBGROUP_H
#define VERBGROUP_H

#include "wordgroup.h"
#include <vector>

class VerbGroup: public WordGroup
{
    public:

        VerbGroup();

        virtual std::string str() const;

        using WordGroup::preposition;
        using WordGroup::setPreposition;

        using WordGroup::addVerbComplement;
        using WordGroup::addAdverbComplement;
        using WordGroup::addNounComplement;

        using WordGroup::verbComplements;
        using WordGroup::adverbComplements;
        using WordGroup::nounComplements;
};

#endif // VERBGROUP_H
