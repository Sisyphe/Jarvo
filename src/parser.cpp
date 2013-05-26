#include "parser.h"
#include <vector>
#include "sentence.h"

void Parser::parse(Sentence &n_sentence, const std::string& n_str)
{
    std::vector<std::string> t_raw_words;

    extractRawWords(n_str,t_raw_words);

    bool t_error=false;
    std::vector<std::string>::iterator t_raw_word=t_raw_words.begin();

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
    int t_find_start=0;
    unsigned int t_found_pos=0;

    while(t_found_pos < n_str.size())
    {
        t_found_pos=n_str.find(' ', t_find_start);
        t_raw_word=n_str.substr(t_find_start,t_found_pos-t_find_start);
        n_raw_words.push_back(t_raw_word);
        t_find_start=t_found_pos+1;
    }
}
