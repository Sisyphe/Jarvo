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

        enum WordGroupType
        {
            NO_GROUP_TYPE,
            NOUN,
            VERB,
            ADVERB,
            ADJECTIVE
        };

        Word* mainWord() const;
        void setMainWord(Word* n_main_word);
        WordGroupType type() const;

        virtual Word* preposition() const;
        virtual void setPreposition(Word* n_preposition);

        virtual std::string str() const = 0;
        virtual int preGroupingPriority(VerbGroup* n_verb_group) const;
        virtual int preGroupingPriority(AdjectiveGroup* n_adj_group) const;
        virtual int preGroupingPriority(AdverbGroup* n_adv_group) const;
        virtual int preGroupingPriority(NounGroup* n_noun_group) const;
        virtual int postGroupingPriority(VerbGroup* n_verb_group) const;
        virtual int postGroupingPriority(AdjectiveGroup* n_adj_group) const;
        virtual int postGroupingPriority(AdverbGroup* n_adv_group) const;
        virtual int postGroupingPriority(NounGroup* n_noun_group) const;

        virtual const std::vector<VerbGroup*>& verbComplements() const;
        virtual const std::vector<AdjectiveGroup*>& adjectiveComplements() const;
        virtual const std::vector<AdverbGroup*>& adverbComplements() const;
        virtual const std::vector<NounGroup*>& nounComplements() const;

        virtual void addAsComplementTo(WordGroup& n_group) = 0;
        virtual void addVerbComplement(const VerbGroup& n_verb_group);
        virtual void addAdjectiveComplement(const AdjectiveGroup& n_adj_group);
        virtual void addAdverbComplement(const AdverbGroup& n_adv_group);
        virtual void addNounComplement(const NounGroup& n_noun_group);

    protected:

        WordGroup();
        virtual ~WordGroup();

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
