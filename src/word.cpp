#include "word.h"
#include <algorithm>

Word::Word(){}

Word::Word(const std::string& n_str)
{
    setString(n_str);
}

void Word::setString(const std::string& n_str)
{
    m_str=n_str;
}

Word::Type Word::type() const
{
    return m_type;
}

bool Word::operator==(const std::string& n_str)
{
    return m_str==n_str;
}
