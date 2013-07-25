#include "parser.h"
#include <vector>
#include "sentence.h"
#include "adverbgroup.h"
#include "adjectivegroup.h"
#include "verbgroup.h"
#include "noungroup.h"

void Parser::parse(Sentence &n_sentence, const std::string& n_str)
{
    NounGroup t_subject_group;
    VerbGroup t_verb_group;
    std::vector<std::string> t_raw_words;
    std::vector<Word*> t_words;
    std::vector<Word*>::const_iterator t_word, t_active_verb, t_subject;
    std::vector<Word*>::const_iterator t_words_begin, t_words_end;

    m_success = true;

    extractRawWords(n_str, t_raw_words);
    if(m_success) getEntries(t_raw_words, t_words);

    t_words_begin = t_words.begin();
    t_words_end = t_words.end();

    t_active_verb = getActiveVerb(t_words);

    t_subject = getSubject((t_words_begin), t_active_verb);
    if(t_subject == t_active_verb) // Si le sujet n'est pas avant le verbe, il est sans doute après...
    {
        t_subject = getSubject(t_active_verb, t_words_end);
    }

    if(t_subject != t_words.end())
    {
        t_subject_group = getSubjectGroup(t_words_begin, t_words_end, t_subject);
        n_sentence.setSubjectGroup(t_subject_group);
    }
}

NounGroup Parser::getSubjectGroup
(
    std::vector<Word*>::const_iterator n_words_begin,
    std::vector<Word*>::const_iterator n_words_end,
    std::vector<Word*>::const_iterator n_subject
)
{
    bool t_is_plural = (*n_subject)->isPlural;
    NounGroup t_group;
    bool t_article_found = false;
    std::vector<Word*>::const_iterator t_word = n_subject + 1;
    std::vector<AdverbGroup> t_adverbs;
    std::vector<AdjectiveGroup> t_adjectives;
    std::vector<VerbGroup> t_verbs;
    std::vector<NounGroup> t_nouns;
    AdverbGroup t_adverb;
    AdjectiveGroup t_adjective;
    VerbGroup t_verb;
    NounGroup t_noun;
    Word* t_last_word = 0;

    t_group.setMainWord(*n_subject);

    for(; t_word != n_words_end; ++t_word)
    {
        switch((*t_word)->type)
        {
            case Word::ARTICLE:
            {
                t_article_found = true;
                break;
            }

            case Word::ADJECTIVE:
            {
                t_adjective = AdjectiveGroup();
                t_adjective.setMainWord(*t_word);

                if(t_last_word)
                {

                }
                else
                {
                    t_adjectives.push_back(t_adjective);
                }

                t_last_word = *t_word;
            }

            default: break;
        }
    }

    return NounGroup();
}

void getGroups()
{

}

std::vector<Word*>::const_iterator Parser::getActiveVerb(const std::vector<Word*>& n_words) const
{
    bool t_found = false;
    std::vector<Word*>::const_iterator t_word = n_words.begin();

    while(t_word != n_words.end() && !t_found)
    {
        if((*t_word)->tense != Word::INFINITIVE && (*t_word)->tense != Word::NO_TENSE)
        {
            t_found = true;
        }
        else ++t_word;
    }

    return t_word;
}

void Parser::getEntries
(
    const std::vector<std::string>& n_raw_words,
    std::vector<Word*>& n_words
)
{
    Word* t_word = 0;
    std::vector<std::string>::const_iterator t_raw_word = n_raw_words.begin();

    n_words.clear();

    while(t_raw_word != n_raw_words.end() && m_success)
    {
        t_word = m_dict.getEntry(*t_raw_word);

        if(t_word)
        {
            n_words.push_back(t_word);
            ++t_raw_word;
        }
        else m_success = false;
    }
}

std::vector<Word*>::const_iterator Parser::getSubject
(
    std::vector<Word*>::const_iterator& n_words_begin,
    std::vector<Word*>::const_iterator& n_words_end
) const
{
    bool t_found = false;
    bool t_preposition_found = false;
    std::vector<Word*>::const_iterator t_noun = n_words_begin;

    while(t_noun != n_words_end && !t_found)
    {
        switch((*t_noun)->type)
        {
            case Word::PREPOSITION:
            {
                t_preposition_found = true;
                ++t_noun;
                break;
            }

            case Word::PRONOUN:
            case Word::NOUN:
            {
                t_found = !t_preposition_found && (*t_noun)->function == Word::SUBJECT;
                break;
            }

            default: ++t_noun;
        }
    }

    return t_noun;
}

void Parser::extractRawWords
(
    const std::string& n_str,
    std::vector<std::string>& n_raw_words
) const
{
    bool t_is_expecting_quote=false;
    std::string t_raw_word;
    char t_char;

    n_raw_words.clear();

    for(unsigned int i=0; i < n_str.size(); ++i)
    {
        t_char=n_str[i];

        switch(t_char)
        {
            case ' ':
            {
                if(!t_is_expecting_quote)
                {
                    if(!t_raw_word.empty())
                    {
                        n_raw_words.push_back(t_raw_word);
                        t_raw_word.erase();
                    }
                }
                else
                {
                    t_raw_word.push_back(t_char);
                }
                break;
            }

            case '\"':
            {
                if(!t_is_expecting_quote)
                {
                    t_raw_word.push_back(tolower(t_char));
                    t_is_expecting_quote=true;
                }
                else
                {
                    t_raw_word.push_back(t_char);
                    n_raw_words.push_back(t_raw_word);
                    t_raw_word.erase();
                    t_is_expecting_quote=false;
                }
                break;
            }

            case '.':
            case '?':
            case '!':
            {
                if(t_is_expecting_quote)
                {
                    t_raw_word.push_back(t_char);
                }
                else if((i+1)!=n_str.size())
                {
                    t_raw_word.push_back(tolower(t_char));
                }
                break;
            }

            default:
            {
                if(t_is_expecting_quote)
                {
                    t_raw_word.push_back(t_char);
                }
                else
                {
                    t_raw_word.push_back(tolower(t_char));
                }
                break;
            }
        }
    }

    if(!t_raw_word.empty()) n_raw_words.push_back(t_raw_word);
}
