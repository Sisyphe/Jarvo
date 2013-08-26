#include "wordgrouplist.h"

WordGroupList::WordGroupList(const std::vector<Word*>& n_words)
{
    int i = 0;
    std::vector<Word*>::const_iterator t_word = n_words.begin();
    WordGroup t_group;
    bool t_is_determinate = false;
    Word* t_preposition = 0;

    for(; t_word != n_words.end(); ++t_word)
    {
        t_group = WordGroup(*t_word);

        switch((*t_word)->type)
        {
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

            case Word::PRONOUN: t_is_determinate = true;
            case Word::NOUN:
            case Word::VERB:
            {
                t_group.setPreposition(t_preposition);
                t_preposition = 0;
                m_groups.push_back(t_group);
                break;
            }

            case Word::ADVERB:
            case Word::ADJECTIVE:
            {
                m_groups.push_back(t_group);
                break;
            }

            default: break;
        }
    }
}

void WordGroupList::regroupWords()
{
    int t_priority = 0;
    bool t_change_made = true;
    int max_priority = 0;
    std::pair<WordGroup::Grouping,std::list<WordGroup>::iterator> prioritary_group(WordGroup::PRE_GROUPING, m_groups.end());
    std::list<WordGroup>::iterator t_group, t_prev_group;

    while(t_change_made)
    {
        max_priority = 0;
        t_change_made = false;
        t_prev_group = m_groups.begin();
        t_group = ++m_groups.begin();

        for(; t_group != m_groups.end(); t_prev_group = t_group++)
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
            WordGroup completed = *t_group;

            switch(prioritary_group.first)
            {
                case WordGroup::PRE_GROUPING:
                {
                    --t_group;
                    break;
                }

                case WordGroup::POST_GROUPING:
                {
                    ++t_group;
                    break;
                }
            }

            WordGroup complement = *t_group;
            prioritary_group.second->addComplement(*t_group);
            m_groups.erase(t_group);
            t_change_made = true;
        }
    }
}
