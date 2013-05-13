#include "parser.h"
#include <list>

void Parser::Parse(const std::string& n_str)
{
    std::vector<std::string> t_raw_words;
    std::list<DictEntry> t_words;
    Noun t_subject, t_accusative;
    std::vector<Adjective> t_adjectives;

    extractRawWords(n_str,t_raw_words);

    std::vector<std::string>::iterator t_raw_word=t_raw_words.begin();

    for(; t_raw_word!=t_raw_words.end(); ++t_raw_word)
    {
        t_words.push_back(m_dict.getEntry(*t_raw_word));
    }

    Adjective t_adjective;
    Noun* t_noun;
    int t_adj_counter=0;
    std::list<DictEntry>::iterator t_entries=t_words.begin();
    for(; t_entries!=t_words.begin(); ++t_entries)
    {
        DictEntry t_entry=*t_entries;

        if((t_entry).type==Word::NOUN)
        {
            if(t_entry.function==Word::SUBJECT)
            {
                t_subject=m_dict.getNoun(t_entry);
                t_noun=&t_subject;
            }
            else if(t_entry.function==Word::ACCUSATIVE)
            {
                t_accusative=m_dict.getNoun(t_entry);
                t_noun=&t_accusative;
            }

            ++entries;
            int t_last_adj=t_adj_counter;

            for(; t_entries!=t_words.begin(); ++t_entries)
            {
                if(
                   (*t_entries).type==Word::ADJECTIVE &&
                   (*t_entries).isPlural==t_entry.isPlural &&
                   (*t_entries).function==t_entry.function
                )
                {
                    t_adjective=m_dict.getAdjective(*t_entries);
                    t_adjective.setObject(&t_noun);
                    t_adjectives.push_back(t_adjective);
                    ++adj_counter;
                }
                else break;
            }

            for(int i=t_last_adj; i<=t_adj_counter; ++i)
            {
                t_adjectives.at(i).setObject(t_noun);
            }

        }
        else if((t_entry).type==Word::ADJECTIVE)
        {
            m_dict.getAdjective(*t_entries);

            for(; t_entries!=t_words.begin(); ++t_entries)
            {
                if();
            }

        }
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
