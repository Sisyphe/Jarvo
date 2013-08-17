#ifndef WORDGROUP_H
#define WORDGROUP_H

#include "word.h"
#include <vector>
#include <string>

class VerbGroup;
class NounGroup;
class AdjectiveGroup;
class AdverbGroup;

class WordGroup
{
    public:

        Word* mainWord() const;
        void setMainWord(Word* n_main_word);
        virtual std::string str() const = 0;
        virtual int preGroupingPriority(const VerbGroup& n_verb_group) const;
        virtual int preGroupingPriority(const AdjectiveGroup& n_adj_group) const;
        virtual int preGroupingPriority(const AdverbGroup& n_adv_group) const;
        virtual int preGroupingPriority(const NounGroup& n_noun_group) const;
        virtual int postGroupingPriority(const VerbGroup& n_verb_group) const;
        virtual int postGroupingPriority(const AdjectiveGroup& n_adj_group) const;
        virtual int postGroupingPriority(const AdverbGroup& n_adv_group) const;
        virtual int postGroupingPriority(const NounGroup& n_noun_group) const;

    protected:

        WordGroup();
        virtual ~WordGroup();

        Word* preposition() const;
        void setPreposition(Word* n_preposition);

        const std::vector<VerbGroup*>& verbComplements() const;
        const std::vector<AdjectiveGroup*>& adjectiveComplements() const;
        const std::vector<AdverbGroup*>& adverbComplements() const;
        const std::vector<NounGroup*>& nounComplements() const;

        void addVerbComplement(const VerbGroup& n_verb_group);
        void addAdjectiveComplement(const AdjectiveGroup& n_adj_group);
        void addAdverbComplement(const AdverbGroup& n_adv_group);
        void addNounComplement(const NounGroup& n_noun_group);

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
        std::vector<VerbGroup*> m_verbs;
        std::vector<NounGroup*> m_nouns;
        std::vector<AdjectiveGroup*> m_adjectives;
        std::vector<AdverbGroup*> m_adverbs;

        int m_adverb_pre_grouping_priority;
        int m_verb_pre_grouping_priority;
        int m_noun_pre_grouping_priority;
        int m_adjective_pre_grouping_priority;

        int m_adverb_post_grouping_priority;
        int m_verb_post_grouping_priority;
        int m_noun_post_grouping_priority;
        int m_adjective_post_grouping_priority;


};

#endif // WORDGROUP_H
