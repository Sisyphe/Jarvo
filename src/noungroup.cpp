#include "noungroup.h"

NounGroup::NounGroup():
    noun(0),
    is_determinate(false)
{

}

bool NounGroup::addWord(Word* n_word)
{
    if(!WordGroup::addWord(n_word)) return false;

    if(n_word->type == Word::ARTICLE)
    {
        is_determinate = true;
    }
    else if(n_word->type == Word::NOUN
         || n_word->type == Word::PRONOUN
         || n_word->type == Word::UNKNOWN_TYPE)
    {
        noun = n_word;
    }
    else if(n_word->type == Word::ADJECTIVE)
    {
        if(qualifiers.empty() || qualifiers.back().adjective)
        {
            qualifiers.push_back(Qualifier(n_word));
        }
        else
        {
            qualifiers.back().adjective = n_word;
        }
    }
    else
    {
        m_word_list.pop_back();
        return false;
    }

    return true;
}

std::string NounGroup::str() const
{

    std::string t_string;
    std::vector<std::string> t_strings = getQualifierStrings();
    std::vector<std::string>::const_iterator it = t_strings.begin();

    for(; it != t_strings.end(); ++it)
    {
        t_string += (*it) + " ";
    }

    t_string += noun->str_base;

    return t_string;
}

std::vector<std::string> NounGroup::getQualifierStrings() const
{
    std::string t_string;
    std::vector<std::string> t_strings;
    std::vector<Qualifier>::const_iterator it = qualifiers.begin();

    for(; it != qualifiers.end(); ++it)
    {
        if((*it).adverb) t_string = (*it).adverb->str_base + " ";
        else t_string.clear();

        if((*it).adjective) t_string += (*it).adjective->str_base;

        t_strings.push_back(t_string);
    }

    return t_strings;
}
