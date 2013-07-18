#include "noungroup.h"

NounGroup::NounGroup():
    noun(0),
    is_defined(false),
    is_entity(false)
{

}

bool NounGroup::addWord(Word* n_word)
{
    if(!WordGroup::addWord(n_word)) return false;

    if(n_word->type == Word::ARTICLE)
    {
        is_defined = true;
        is_entity = (noun && noun->isPlural && is_defined);
    }
    else if(n_word->type == Word::NOUN
         || n_word->type == Word::PRONOUN
         || n_word->type == Word::UNKNOWN_TYPE)
    {
        noun = n_word;
        is_entity = (noun && noun->isPlural && is_defined);
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
