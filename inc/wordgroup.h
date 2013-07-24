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
        virtual std::string str() const = 0;

    protected:

        WordGroup();
        virtual ~WordGroup();
        Word* preposition() const;

        std::vector<VerbGroup*> verbComplements() const;
        std::vector<AdjectiveGroup*> adjectiveComplements() const;
        std::vector<AdverbGroup*> adverbComplements() const;
        std::vector<NounGroup*> nounComplements() const;

        void addVerbComplement(VerbGroup* n_verb_group);
        void addAdjectiveComplement(AdjectiveGroup* n_adj_group);
        void addAdverbComplement(AdverbGroup* n_adv_group);
        void addNounComplement(NounGroup* n_noun_group);

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


};

#endif // WORDGROUP_H
