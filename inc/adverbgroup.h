#ifndef ADVERBGROUP_H
#define ADVERBGROUP_H

#include "wordgroup.h"

class AdverbGroup: public WordGroup
{
    public:

        AdverbGroup();
        virtual std::string str() const;
};

#endif // ADVERBGROUP_H
