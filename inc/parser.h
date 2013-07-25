#ifndef PARSER_H
#define PARSER_H

#include "dictionnary.h"
#include "sentence.h"

class Parser
{
    public:

        void parse(Sentence& n_sentence, const std::string& n_str);

    protected:

        void getEntries
        (
            const std::vector<std::string>& n_raw_words,
            std::vector<Word*>& n_words
        );

        void getSubject
        (
            const std::vector< Word* >& n_words,
            NounGroup& n_subject_group
        ) const;

        void extractRawWords
        (
            const std::string& n_str,
            std::vector< std::string >& n_raw_words
        ) const;

        std::vector<Word*>::const_iterator getActiveVerb
        (
            const std::vector<Word*>& n_words
        ) const;

        std::vector<Word*>::const_iterator getSubject
        (
            std::vector<Word*>::const_iterator& n_words_begin,
            std::vector<Word*>::const_iterator& n_words_end
        ) const;

        NounGroup getSubjectGroup
        (
            std::vector<Word*>::const_iterator n_words_begin,
            std::vector<Word*>::const_iterator n_words_end,
            std::vector<Word*>::const_iterator n_subject
        );


        Dictionnary m_dict;
        bool m_success;
};

#endif // PARSER_H
