#include "verbgroup.h"

VerbGroup::VerbGroup():
    verb(0)
{

}

bool VerbGroup::addWord(Word* n_word)
{
    if(!WordGroup::addWord(n_word)) return false;

    if(n_word->type == Word::VERB)
    {
        verb = n_word;
    }
    else if(n_word->type == Word::ADVERB)
    {
        adverbs.push_back(n_word);
    }
    else if(n_word->type == Word::ADJECTIVE)
    {
        adjectives.push_back(n_word);
    }
    else
    {
        m_word_list.pop_back();
        return false;
    }

    return true;
}

std::vector<std::string> VerbGroup::getAdjectiveStrings() const
{
    std::vector<std::string> t_strings;
    std::vector<Word*>::const_iterator it = adjectives.begin();

    for(; it != adjectives.end(); ++it)
    {
        t_strings.push_back((*it)->str_base);
    }

    return t_strings;
}

std::vector<std::string> VerbGroup::getAdverbStrings() const
{
    std::vector<std::string> t_strings;
    std::vector<Word*>::const_iterator it = adverbs.begin();

    for(; it != adverbs.end(); ++it)
    {
        t_strings.push_back((*it)->str_base);
    }

    return t_strings;
}

