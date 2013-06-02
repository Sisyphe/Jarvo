#include "parser.h"
#include <vector>
#include "sentence.h"

void Parser::parse(Sentence &n_sentence, const std::string& n_str)
{
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

            case Word::NOUN:
            case Word::PRONOUN:
            {
                switch(t_entry->function)
                {
                    case Word::SUBJECT:
                        if(!n_sentence.subject)
                        {
                            n_sentence.subject=t_entry;
                            break;
                        }

                    case Word::ACCUSATIVE:
                        if(!n_sentence.object)
                        {
                            n_sentence.object=t_entry;
                            break;
                        }

                    default: t_error=true;
                }

                break;
            }

            case Word::VERB:
            {
                n_sentence.verb=t_entry;
                break;
            }

            default: /* Work in progress... */;
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
    std::string t_raw_word;

    for(int i=0; i < n_str.size(); ++i)
    {
        switch(n_str[i])
        {
            case '.':
            case '?':
            case '!':
                break;

            case ' ':
                n_raw_words.push_back(t_raw_word);
                t_raw_word.erase();
                break;

            default:
                t_raw_word.push_back(tolower(n_str[i]));
                break;
        }
    }

    if(!t_raw_word.empty()) n_raw_words.push_back(t_raw_word);
}
