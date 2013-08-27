#include "wordgroup.h"

WordGroup::WordGroup(Word* n_main_word):
    m_main_word(0),
    m_preposition(0),
    m_type(WordGroup::NO_GROUP_TYPE),
    m_is_determinate(false)
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

bool WordGroup::isEmpty() const
{
    return m_main_word == 0;
}

bool WordGroup::hasComplements() const
{
    return !m_complements.empty();
}

Word* WordGroup::preposition() const
{
    return m_preposition;
}

void WordGroup::setPreposition(Word* n_preposition)
{
    m_preposition = n_preposition;
}

bool WordGroup::isDeterminate() const
{
    return m_is_determinate;
}

void WordGroup::setDeterminate(bool n_on)
{
    m_is_determinate = n_on;
}

std::string WordGroup::str() const
{
    std::string t_str;
    std::vector<WordGroup> t_adjectives, t_adverbs, t_nouns, t_verbs;
    std::vector<WordGroup>::const_iterator t_group = m_complements.begin();

    if(m_main_word)
    {
        for(; t_group != m_complements.end(); ++t_group)
        {
            switch(t_group->type())
            {
                case WordGroup::ADJECTIVE:
                    t_adjectives.push_back(*t_group);
                    break;
                case WordGroup::NOUN:
                    t_nouns.push_back(*t_group);
                    break;
                case WordGroup::ADVERB:
                    t_adverbs.push_back(*t_group);
                    break;
                case WordGroup::VERB:
                    t_verbs.push_back(*t_group);
                    break;
                default: break;
            }
        }

        if(m_preposition) t_str += m_preposition->str_base + " ";
        t_str += getStr(t_verbs);
        t_str += getStr(t_adverbs);
        t_str += getStr(t_adjectives);
        t_str += m_main_word->str_base + " ";
        t_str += getStr(t_nouns);
        t_str.erase(t_str.end()-1);
    }

    return t_str;
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
