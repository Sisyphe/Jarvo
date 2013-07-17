#include "word.h"
#include <algorithm>


Word::Word():
    type(UNKNOWN_TYPE),
    function(NO_CASE),
    tense(NO_TENSE),
    isPlural(false),
    node(0)
{}

bool Word::operator==(const Word& other)
{
    return (str == other.str);
}
