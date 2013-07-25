#include "wordgrouplist.h"

WordGroupList::WordGroupList(const std::vector<Word*>& n_words)
{
    int i = 0;
    std::vector<Word*>::const_iterator t_word = n_words.begin();
    NounGroup t_noun;
    AdjectiveGroup t_adjective;
    AdverbGroup t_adverb;
    VerbGroup t_verb;
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
                t_noun = NounGroup();
                t_noun.setMainWord(*t_word);
                t_noun.setDeterminate(t_is_determinate);
                t_is_determinate = false;
                t_noun.setPreposition(t_preposition);
                t_preposition = 0;
                m_nouns.push_back(std::pair<int, NounGroup>(i++, t_noun));
                m_groups.push_back(WordGroupList::NOUN);
                break;
            }

            case Word::ADJECTIVE:
            {
                t_adjective = AdjectiveGroup();
                t_adjective.setMainWord(*t_word);
                m_adjectives.push_back(std::pair<int, AdjectiveGroup>(i++, t_adjective));
                m_groups.push_back(WordGroupList::ADJECTIVE);
                break;
            }

            case Word::ADVERB:
            {
                t_adverb = AdverbGroup();
                t_adverb.setMainWord(*t_word);
                m_adverbs.push_back(std::pair<int, AdverbGroup>(i++, t_adverb));
                m_groups.push_back(WordGroupList::ADVERB);
                break;
            }

            case Word::VERB:
            {
                t_verb = VerbGroup();
                t_verb.setMainWord(*t_word);
                t_verb.setPreposition(t_preposition);
                t_preposition = 0;
                m_verbs.push_back(std::pair<int, VerbGroup>(i++, t_verb));
                m_groups.push_back(WordGroupList::VERB);
                break;
            }

            default: break;
        }
    }
}

void WordGroupList::regroupWords()
{
    bool t_change_made = true;

    std::list<WordGroupType>::iterator t_group_type;

    while(t_change_made)
    {
        t_group_type = m_groups.begin();

        for(; t_group_type != m_groups.end(); ++t_group_type)
        {
            switch(*t_group_type)
            {
                case WordGroupList::NOUN:
                {

                    break;
                }
            }
        }
    }
}
