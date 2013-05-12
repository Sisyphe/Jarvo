#include "parser.h"

void Parser::Parse(const std::string& n_str)
{
    std::vector<std::string> t_raw_words;
    std::vector<Name*> t_names;
    std::vector<Adjective*> t_adjectives;

    extractRawWords(n_str,t_raw_words);

    std::vector<std::string>::iterator it=t_raw_words.begin();

    for(; it!=t_words; ++it)
    {
        m_dict.getName(*it);
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
    int t_found_pos=0;

    while(n_found_pos < n_str.size())
    {
        t_found_pos=n_str.find(' ', t_find_start);
        t_raw_word=n_str.substr(t_find_start,t_found_pos-t_find_start);
        n_raw_words.push_back(t_raw_word);
        t_find_start=t_found_pos+1;
    }

    return t_raw_words;
}
