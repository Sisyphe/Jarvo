#include "wordgrouplist.h"

void WordGroupList::makeGroups(const std::vector<Word*>& n_words, std::list<WordGroup>& n_groups)
{
    std::vector<Word*>::const_iterator t_word = n_words.begin();
    WordGroup t_group;
    bool t_is_determinate = false;
    bool t_is_general = false;
    Word* t_preposition = 0;

    n_groups.clear();

    for(; t_word != n_words.end(); ++t_word)
    {
        t_group = WordGroup(*t_word);

        if((*t_word)->str_base == "cxiu")
        {
            t_is_general = true;
            continue;
        }

        switch((*t_word)->type)
        {
            t_group.setInterrogative(*t_word->is_interrogative);

            case Word::ARTICLE:
            {
                t_is_determinate = true;
                break;
            }

            case Word::PREPOSITION:
            {
                t_preposition = *t_word;
                break;
            }

            case Word::PRONOUN:
                t_is_determinate = true;

            case Word::NOUN:
                t_group.setDeterminate(t_is_determinate);
                t_group.setGeneral(t_is_general);
                t_is_determinate = false;
                t_is_general = false;

            case Word::VERB:
            {
                t_group.setPreposition(t_preposition);
                t_preposition = 0;
                n_groups.push_back(t_group);
                break;
            }

            case Word::ADVERB:
            case Word::ADJECTIVE:
            {
                n_groups.push_back(t_group);
                break;
            }

            default:
                break;
        }
    }
}

void WordGroupList::regroupWords(const std::vector<Word*>& n_words, std::list<WordGroup>& n_groups)
{
    int t_priority = 0;
    bool t_change_made = true;
    int max_priority = 0;
    std::pair<WordGroup::Grouping, std::list<WordGroup>::iterator> prioritary_group(WordGroup::PRE_GROUPING, n_groups.end());
    std::list<WordGroup>::iterator t_group, t_prev_group;

    makeGroups(n_words, n_groups);

    while(t_change_made)
    {
        max_priority = 0;
        t_change_made = false;
        t_prev_group = n_groups.begin();
        t_group = ++n_groups.begin();

        for(; t_group != n_groups.end(); t_prev_group = t_group++)
        {
            t_priority = t_group->groupingPriority(WordGroup::PRE_GROUPING, t_prev_group->type());

            if(max_priority < t_priority)
            {
                prioritary_group.first = WordGroup::PRE_GROUPING;
                prioritary_group.second = t_group;
                max_priority = t_priority;
            }

            t_priority = t_prev_group->groupingPriority(WordGroup::POST_GROUPING, t_group->type());

            if(max_priority < t_priority)
            {
                prioritary_group.first = WordGroup::POST_GROUPING;
                prioritary_group.second = t_prev_group;
                max_priority = t_priority;
            }
        }

        if(max_priority > 0)
        {
            t_group = prioritary_group.second;

            if(prioritary_group.first == WordGroup::PRE_GROUPING)
                --t_group;
            else if(prioritary_group.first == WordGroup::POST_GROUPING)
                ++t_group;

            prioritary_group.second->addComplement(*t_group);
            n_groups.erase(t_group);
            t_change_made = true;
        }
    }
}
