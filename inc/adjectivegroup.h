#ifndef ADJECTIVEGROUP_H
#define ADJECTIVEGROUP_H

#include "wordgroup.h"

class AdjectiveGroup: public WordGroup
{
    public:

        AdjectiveGroup();

        virtual std::string str() const;

        using WordGroup::addVerbComplement;
        using WordGroup::addAdverbComplement;
        using WordGroup::addNounComplement;

        virtual void addAsComplementTo(WordGroup& n_group);
        using WordGroup::verbComplements;
        using WordGroup::adverbComplements;
        using WordGroup::nounComplements;
};

#endif // ADJECTIVEGROUP_H
