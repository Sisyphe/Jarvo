#include "parser.h"
#include <vector>
#include "sentence.h"

void Parser::parse(Sentence &n_sentence, const std::string& n_str)
{
    bool t_next_noun_is_defined=false;
    std::vector<std::string> t_raw_words;

    extractRawWords(n_str,t_raw_words);

    bool t_error=false;
    std::vector<std::string>::iterator t_raw_word=t_raw_words.begin();

    if(*t_raw_word == "cxu")
    {
        n_sentence.is_interrogative=true;
        n_sentence.is_yes_no_question=true;
        ++t_raw_word;
    }

    while(t_raw_word!=t_raw_words.end() && !t_error)
    {
        Word* t_entry=m_dict.getEntry(*t_raw_word);

        switch(t_entry->type)
        {
            case Word::ADJECTIVE:
            {
                switch(t_entry->function)
                {
                    case Word::SUBJECT:
                        if(!n_sentence.object && !n_sentence.verb)
                        {
                            n_sentence.subject_adjs.push_back(t_entry);
                            break;
                        }

                    case Word::ACCUSATIVE:
                        n_sentence.object_adjs.push_back(t_entry);
                        break;

                    default: t_error=true;
                }

                break;
            }

            case Word::UNKNOWN_TYPE:
            {
                if(!n_sentence.verb)
                {
                    t_entry->function=Word::SUBJECT;
                }
                else
                {
                    t_entry->function=Word::ACCUSATIVE;
                }

                t_entry->is_unique=true;
            }
            case Word::PRONOUN:
            case Word::NOUN:
            {
                switch(t_entry->function)
                {
                    case Word::SUBJECT:
                    {
                        if(!n_sentence.subject)
                        {
                            n_sentence.subject=t_entry;
                            if((t_next_noun_is_defined && t_entry->isPlural) || t_entry->is_unique)
                            {
                                n_sentence.subject_is_entity=true;
                            }
                            t_next_noun_is_defined=false;
                            break;
                        }
                    }
                    case Word::ACCUSATIVE:
                    {
                        if(!n_sentence.object)
                        {
                            n_sentence.object=t_entry;
                            if((t_next_noun_is_defined && t_entry->isPlural) || t_entry->is_unique)
                            {
                                n_sentence.object_is_entity=true;
                            }
                            t_next_noun_is_defined=false;
                            break;
                        }
                    }
                    default: t_error=true;
                }

                break;
            }

            case Word::VERB:
            {
                if(t_next_noun_is_defined)
                {
                    t_error=true;
                }
                else
                {
                    n_sentence.verb=t_entry;
                }
                break;
            }

            case Word::ARTICLE:
            {
                t_next_noun_is_defined=true;
                break;
            }

            default: t_error=true /* Work in progress... */;
        }

        ++t_raw_word;
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
