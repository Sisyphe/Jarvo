#include "wordgrouplist.h"

WordGroupList::WordGroupList(const std::vector<Word*>& n_words)
{
    int i = 0;
    std::vector<Word*>::const_iterator t_word = n_words.begin();
    NounGroup* t_noun = 0;
    AdjectiveGroup* t_adjective = 0;
    AdverbGroup* t_adverb = 0;
    VerbGroup* t_verb  = 0;
    bool t_is_determinate = false;
    Word* t_preposition = 0;

    for(; t_word != n_words.end(); ++t_word)
    {
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
            {
                t_noun = new NounGroup();
                t_noun->setMainWord(*t_word);
                t_noun->setDeterminate(t_is_determinate);
                t_is_determinate = false;
                t_noun->setPreposition(t_preposition);
                t_preposition = 0;
                m_groups.push_back(t_noun);
                break;
            }

            case Word::ADJECTIVE:
            {
                t_adjective = new AdjectiveGroup();
                t_adjective->setMainWord(*t_word);
                m_groups.push_back(t_adjective);
                break;
            }

            case Word::ADVERB:
            {
                t_adverb = new AdverbGroup();
                t_adverb->setMainWord(*t_word);
                m_groups.push_back(t_adverb);
                break;
            }

            case Word::VERB:
            {
                t_verb = new VerbGroup();
                t_verb->setMainWord(*t_word);
                t_verb->setPreposition(t_preposition);
                t_preposition = 0;
                m_groups.push_back(t_verb);
                break;
            }

            default: break;
        }
    }
}

void WordGroupList::regroupWords()
{
    bool t_change_made = true;
    int max_priority = -1;
    std::pair<Grouping,std::list<WordGroup*>::iterator> prioritary_group(NO_GROUPING, m_groups.end());
    std::list<WordGroup*>::iterator t_group, t_prev_group;

    while(t_change_made)
    {
        t_prev_group = m_groups.begin();
        t_group = ++m_groups.begin();

        for(; t_group != m_groups.end(); t_prev_group = t_group++)
        {
            if(max_priority < (*t_group)->preGroupingPriority(*t_prev_group))
            {
                prioritary_group.first = PRE_GROUPING;
                prioritary_group.second = t_group;
                max_priority = (*t_group)->preGroupingPriority(*t_prev_group);
            }

            if(max_priority < (*t_prev_group)->postGroupingPriority(*t_group))
            {
                prioritary_group.first = POST_GROUPING;
                prioritary_group.second = t_group;
                max_priority = (*t_prev_group)->postGroupingPriority(*t_group);
            }
        }

        switch(prioritary_group.first)
        {
            case PRE_GROUPING:
            {
                break;
            }

            case POST_GROUPING:
            {
                break;
            }
        }
    }
}
