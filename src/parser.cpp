#include "parser.h"
#include <list>

void Parser::parse(const std::string& n_str)
{
    std::vector<std::string> t_raw_words;
    Noun *t_subject=0, *t_object=0;
    std::vector<Adjective*> t_object_adjs, t_subject_adjs;

    extractRawWords(n_str,t_raw_words);

    bool t_error=false;
    std::vector<std::string>::iterator t_raw_word=t_raw_words.begin();

    while(t_raw_word!=t_raw_words.end() && !t_error)
    {
        DictEntry* t_entry=m_dict.getEntry(*t_raw_word);

        switch(t_entry->type)
        {
            case Word::ADJECTIVE:
            {
                Adjective* t_adjective=m_dict.getAdjective(t_entry);

                switch(t_entry->function)
                {
                    case Word::SUBJECT:
                        t_subject_adjs.push_back(t_adjective);
                        if(t_subject)
                        {
                            t_adjective->setObject(t_subject);
                        }
                        break;

                    case Word::ACCUSATIVE:
                        t_object_adjs.push_back(t_adjective);
                        if(t_object)
                        {
                            t_adjective->setObject(t_object);
                        }
                        break;

                    default: t_error=true;
                }

                break;
            }

            case Word::NOUN:
            {
                Noun* t_noun=m_dict.getNoun(t_entry);

                switch(t_entry->function)
                {
                    case Word::SUBJECT:
                        if(!t_subject)
                        {
                            t_subject=t_noun;
                            for(unsigned int i=0; i<t_subject_adjs.size(); ++i)
                            {
                                t_subject_adjs[i]->setObject(t_subject);
                            }
                            break;
                        }

                    case Word::ACCUSATIVE:
                        if(!t_object)
                        {
                            t_object=t_noun;
                            for(unsigned int i=0; i<t_object_adjs.size(); ++i)
                            {
                                t_object_adjs[i]->setObject(t_object);
                            }
                            break;
                        }

                    default: t_error=true;
                }

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
