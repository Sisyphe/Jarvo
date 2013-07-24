#include "parser.h"
#include <vector>
#include "sentence.h"

void Parser::parse(Sentence &n_sentence, const std::string& n_str)
{
    std::vector<Word*> t_waiting_adverbs;
    std::vector<Word*>::iterator t_adverb_it;
    bool t_next_noun_is_defined=false;
    Word* t_entry = 0;
    Word* t_article = 0;
    bool t_error=false;
    std::vector<std::string> t_raw_words;
    std::vector<std::string>::iterator t_raw_word;
    NounGroup* t_subject_group = &n_sentence.subject_group;
    NounGroup* t_object_group = &n_sentence.object_group;
    VerbGroup* t_verb_group = &n_sentence.verb_group;
    NounGroup* t_group = 0;
    std::map<Word::Case, NounGroup*> t_groups;
    t_groups[Word::SUBJECT] = &n_sentence.subject_group;
    t_groups[Word::OBJECT] = &n_sentence.object_group;

    extractRawWords(n_str,t_raw_words);
    t_raw_word=t_raw_words.begin();

    if(*t_raw_word == "cxu")
    {
        n_sentence.is_interrogative=true;
        n_sentence.is_yes_no_question=true;
        ++t_raw_word;
    }
/*
    while(t_raw_word!=t_raw_words.end() && !t_error)
    {
        t_entry=m_dict.getEntry(*t_raw_word);

        switch(t_entry->type)
        {
            case Word::ADJECTIVE:
            {
                t_group = t_groups[t_entry->function];
                if(t_subject_group->noun)
                {
                    t_group = t_object_group;
                }
                if(!t_waiting_adverbs.empty())
                {
                    t_group->addWord(t_waiting_adverbs.back());
                    t_waiting_adverbs.clear();
                }
                t_group->addWord(t_entry);
                break;
            }

            case Word::UNKNOWN_TYPE:
            {
                if(!t_verb_group->verb)
                {
                    t_entry->function=Word::SUBJECT;
                }
                else
                {
                    t_entry->function=Word::OBJECT;
                }

                t_entry->is_special=true;
            }
            case Word::PRONOUN:
            case Word::NOUN:
            {
                t_group = t_groups[t_entry->function];
                if(t_subject_group->noun)
                {
                    t_group = t_object_group;
                }

                if(t_group && !t_group->noun) //FIXME compléments d'objets, etc...
                {
                    if(t_next_noun_is_defined)
                    {
                        t_group->addWord(t_article);
                        t_next_noun_is_defined=false;
                    }
                    t_group->addWord(t_entry);
                }
                else t_error = true;

                break;
            }

            case Word::VERB:
            {
                if(t_next_noun_is_defined)
                {
                    t_error=true;
                    break;
                }

                t_adverb_it = t_waiting_adverbs.begin();
                for(; t_adverb_it != t_waiting_adverbs.end(); ++t_adverb_it)
                {
                    t_verb_group->addWord(*t_adverb_it);
                }

                t_verb_group->addWord(t_entry);

                break;
            }

            case Word::ARTICLE:
            {
                t_article = t_entry;
                t_next_noun_is_defined=true;
                break;
            }

            case Word::ADVERB: //FIXME adverbes après le verbe associés à l'objet
            {
                t_waiting_adverbs.push_back(t_entry);
            }

            default: t_error=true; // Work in progress...
        }

        ++t_raw_word;
    }*/
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
