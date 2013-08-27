#ifndef VERBGROUP_H
#define VERBGROUP_H

#include "wordgroup.h"
#include <vector>

class VerbGroup: public WordGroup
{
    public:

        VerbGroup();
        virtual std::string str() const;
};

#endif // VERBGROUP_H
