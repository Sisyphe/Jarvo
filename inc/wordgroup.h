#ifndef WORDGROUP_H
#define WORDGROUP_H

#include "word.h"
#include <vector>
#include <string>

class WordGroup
{
    public:

        enum WordGroupType
        {
            NOUN,
            VERB,
            ADVERB,
            ADJECTIVE,
            NO_GROUP_TYPE
        };

        enum Grouping
        {
            PRE_GROUPING,
            POST_GROUPING
        };


        WordGroup(Word* n_main_word = 0);
        ~WordGroup();
        Word* mainWord() const;
        void setMainWord(Word* n_main_word);
        WordGroupType type() const;
        std::string str() const;

        Word* preposition() const;
        void setPreposition(Word* n_preposition);

        int groupingPriority(Grouping n_grouping, WordGroupType n_type) const;
        //static int groupingPriority(WordGroup::Grouping n_grouping, WordGroup::WordGroupType n_completed_type, WordGroup::WordGroupType n_completement_type);

        const std::vector<WordGroup> getComplements(WordGroupType n_type) const;

        void addComplement(WordGroup n_group);

    protected:

        template<class T>
        std::string getStr(const std::vector<T*>& n_groups) const
        {
            std::string str;
            typename std::vector<T*>::const_iterator it = n_groups.begin();

            for(; it != n_groups.end(); ++it)
            {
                str += (*it)->str() + " ";
            }

            return str;
        }

    protected:

        Word* m_main_word;
        Word* m_preposition;
        WordGroupType m_type;

        std::vector<WordGroup> m_complements;

        int m_pre_grouping_priority[4][4];
        int m_post_grouping_priority[4][4];
};

#endif // WORDGROUP_H
