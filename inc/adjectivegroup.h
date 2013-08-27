#ifndef ADJECTIVEGROUP_H
#define ADJECTIVEGROUP_H

#include "wordgroup.h"

class AdjectiveGroup: public WordGroup
{
    public:

        AdjectiveGroup();
        virtual std::string str() const;
};

#endif // ADJECTIVEGROUP_H
