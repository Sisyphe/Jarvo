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
            INFINITIVE_VERB,
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
        bool isEmpty() const;

        WordGroupType type() const;
        virtual std::string str() const;

        Word* preposition() const;
        void setPreposition(Word* n_preposition);

        bool isDeterminate() const;
        void setDeterminate(bool n_on);

        bool isGeneral() const;
        void setGeneral(bool n_on);

        bool isInterrogative() const;
        void setInterrogative(bool n_on);

        int groupingPriority(Grouping n_grouping, WordGroupType n_type) const;

        bool hasComplements() const;
        const std::vector<WordGroup> getComplements(WordGroupType n_type) const;
        void addComplement(WordGroup n_group);

    protected:

        std::string getStr(const std::vector<WordGroup>& n_groups) const;

        static int s_group_count;

        Word* m_main_word;
        Word* m_preposition;
        WordGroupType m_type;
        bool m_is_determinate;
        bool m_is_general;
        bool m_is_interrogative;

        std::vector<WordGroup> m_complements;

        std::vector<std::vector<int> > m_pre_grouping_priority;
        std::vector<std::vector<int> > m_post_grouping_priority;
};

#endif // WORDGROUP_H
