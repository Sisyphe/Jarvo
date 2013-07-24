#include "wordgroup.h"

WordGroup::WordGroup()
{

}

WordGroup::~WordGroup()
{

}

bool WordGroup::isEmpty() const
{
    return m_word_list.empty();
}

std::string WordGroup::str() const
{
    std::vector<Word*>::const_iterator it = m_word_list.begin();
    std::string str;

    for(; it != m_word_list.end(); ++it)
    {
        str += (*it)->str_base + " ";
    }

    return str;
}

bool WordGroup::operator==(const WordGroup& other)
{
    bool is_equal = true;
    std::vector<Word*>::iterator it1 = m_word_list.begin();
    std::vector<Word*>::const_iterator it2 = other.m_word_list.begin();

    while(it1 != m_word_list.end() && it2 != other.m_word_list.end() && is_equal)
    {
        is_equal = (**it1 == **it2);
    }

    return is_equal;
}
