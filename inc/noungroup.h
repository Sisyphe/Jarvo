#ifndef NOUNGROUP_H
#define NOUNGROUP_H

#include "wordgroup.h"

class NounGroup: public WordGroup
{
    public:

        NounGroup();
        virtual std::string str() const;
};

#endif // NOUNGROUP_H
