#ifndef ADVERBGROUP_H
#define ADVERBGROUP_H

#include "wordgroup.h"

class AdverbGroup: public WordGroup
{
    public:

        AdverbGroup();

        virtual std::string str() const;

        using WordGroup::addVerbComplement;
        using WordGroup::addAdverbComplement;

        virtual void addAsComplementTo(WordGroup& n_group);
        using WordGroup::adverbComplements;
        using WordGroup::nounComplements;
};

#endif // ADVERBGROUP_H
