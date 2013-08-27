#include "parser.h"
#include <vector>
#include "sentence.h"
#include "wordgroup.h"
#include "wordgrouplist.h"

void Parser::parse(Sentence &n_sentence, const std::string& n_str)
{
    WordGroup t_subject_group;
    WordGroup t_verb_group;
    std::vector<std::string> t_raw_words;
    std::vector<Word*> t_words;
    std::list<WordGroup> t_groups;
    std::list<WordGroup>::iterator t_group;
    bool done = false;
    Word* t_word = 0;
    bool subject_set = false;

    extractRawWords(n_str, t_raw_words);
    getEntries(t_raw_words, t_words);

    WordGroupList t_group_list(t_words);
    t_group_list.regroupWords();
    t_groups = t_group_list.groups();

    t_group = t_groups.begin();

    for(; t_group != t_groups.end(); ++t_group)
    {
        t_word = t_group->mainWord();

        if(t_word->type == Word::NOUN)
        {
            if(t_word->function == Word::SUBJECT && !subject_set)
            {
                n_sentence.setSubjectGroup(*t_group);
                subject_set = true;
            }
            else n_sentence.setObjectGroup(*t_group);
        }
        else if(t_word->type == Word::VERB)
        {
            n_sentence.setVerbGroup(*t_group);
        }
    }
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
