#include "wordgroup.h"

WordGroup::WordGroup(Word* n_main_word):
    m_main_word(0),
    m_preposition(0),
    m_type(WordGroup::NO_GROUP_TYPE)
{
    setMainWord(n_main_word);

    for(int i = 0; i < 4; ++i)
    {
        for(int j = 0; j < 4; ++j)
        {
            m_pre_grouping_priority[i][j] = 0;
            m_post_grouping_priority[i][j] = 0;
        }
    }

    m_pre_grouping_priority[WordGroup::ADJECTIVE][WordGroup::ADVERB] = 2;
    m_post_grouping_priority[WordGroup::ADJECTIVE][WordGroup::ADVERB] = 1;
    m_post_grouping_priority[WordGroup::ADJECTIVE][WordGroup::VERB] = 1;

    m_pre_grouping_priority[WordGroup::ADVERB][WordGroup::ADVERB] = 1;
    m_post_grouping_priority[WordGroup::ADVERB][WordGroup::NOUN] = 1;

    m_pre_grouping_priority[WordGroup::NOUN][WordGroup::ADJECTIVE] = 2;
    m_post_grouping_priority[WordGroup::NOUN][WordGroup::ADJECTIVE] = 1;
    m_post_grouping_priority[WordGroup::NOUN][WordGroup::NOUN] = 1;

    m_post_grouping_priority[WordGroup::VERB][WordGroup::ADVERB] = 1;
    m_post_grouping_priority[WordGroup::VERB][WordGroup::VERB] = 1;
}

WordGroup::~WordGroup(){}

Word* WordGroup::mainWord() const
{
    return m_main_word;
}

void WordGroup::setMainWord(Word* n_main_word)
{
    if(n_main_word)
    {
        switch(n_main_word->type)
        {
            case Word::NOUN:
                m_type = WordGroup::NOUN;
                break;
            case Word::VERB:
                m_type = WordGroup::VERB;
                break;
            case Word::ADVERB:
                m_type = WordGroup::ADVERB;
                break;
            case Word::ADJECTIVE:
                m_type = WordGroup::ADJECTIVE;
                break;
            default: m_type = WordGroup::NO_GROUP_TYPE;
        }

        m_main_word = n_main_word;
    }
}

WordGroup::WordGroupType WordGroup::type() const
{
    return m_type;
}

Word* WordGroup::preposition() const
{
    return m_preposition;
}

void WordGroup::setPreposition(Word* n_preposition)
{
    m_preposition = n_preposition;
}

std::string WordGroup::str() const
{
    return std::string();
}

int WordGroup::groupingPriority(Grouping n_grouping, WordGroupType n_type) const
{
    switch(n_grouping)
    {
        case WordGroup::PRE_GROUPING:
            return m_pre_grouping_priority[m_type][n_type];
            break;

        case WordGroup::POST_GROUPING:
            return m_post_grouping_priority[m_type][n_type];
            break;

        default: return -1;
    }
}

// int WordGroup::groupingPriority(Grouping n_grouping, WordGroupType n_completed_type, WordGroupType n_completement_type)
// {
//     switch(n_grouping)
//     {
//         case WordGroup::PRE_GROUPING:
//             return m_pre_grouping_priority[n_completed_type][n_completement_type];
//             break;
//
//         case WordGroup::POST_GROUPING:
//             return m_post_grouping_priority[n_completed_type][n_completement_type];
//             break;
//
//         default: return -1;
//     }
// }

const std::vector<WordGroup> WordGroup::getComplements(WordGroupType n_type) const
{
    std::vector<WordGroup> t_groups;
    std::vector<WordGroup>::const_iterator t_complement = m_complements.begin();

    for(; t_complement != m_complements.end(); ++t_complement)
    {
        if(t_complement->type() == n_type)
        {
            t_groups.push_back(*t_complement);
        }
    }

    return t_groups;
}

void WordGroup::addComplement(WordGroup n_group)
{
    m_complements.push_back(n_group);
}
