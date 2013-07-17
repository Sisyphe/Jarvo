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
