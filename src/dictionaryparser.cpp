#include "dictionaryparser.h"
#include <fstream>
#include <stdexcept>
#include <iostream>

std::map<std::string, DictionaryParser::ParsingFunction> DictionaryParser::s_function_map;

void DictionaryParser::parseFile(const std::string& n_file_name, std::vector<Word>& n_words)
{
    m_file_name = n_file_name;
    int t_line_count = 0;
    m_file.open(n_file_name.c_str());
    std::string t_type_str;
    std::string t_line;
    std::deque<std::string> t_split_line;

    if(s_function_map.empty()) fillFunctionMap();

    if(!m_file.is_open()) throw std::runtime_error("Can't open file \"" + m_file_name + "\"");

    while(std::getline(m_file, t_line))
    {
        Word t_word;

        t_split_line = splitLine(t_line);
        if(t_split_line.size() < 3) throw SyntaxError(m_file_name, t_line_count);

        t_word.str = t_split_line[0];
        t_split_line.pop_front();
        t_word.str_base = t_split_line[0];
        t_split_line.pop_front();
        t_type_str = t_split_line[0];
        t_split_line.pop_front();

        FunctionMapIt t_parsing_function_it = s_function_map.find(t_type_str);
        if(t_parsing_function_it == s_function_map.end())
            throw SyntaxError(m_file_name, "Unknown type (" + t_type_str + ")");

        try
        {
            (this->*t_parsing_function_it->second)(t_split_line, t_word);
        }
        catch(const std::out_of_range&)
        {
            throw SyntaxError(m_file_name, "Missing argument", t_line_count);
        }
        catch(const CriticalSyntaxError& e)
        {
            throw SyntaxError(m_file_name, e.error(), t_line_count);
        }
        catch(const SyntaxError& e)
        {
            std::cout << e.what() << std::endl;
        }

        n_words.push_back(t_word);

        ++t_line_count;
    }

    m_file.close();
}

void DictionaryParser::fillFunctionMap()
{
    s_function_map["pronomo"] = &DictionaryParser::parsePronoun;
    s_function_map["interrogativa_pronomo"] = &DictionaryParser::parsePronoun;
    s_function_map["nomo"] = &DictionaryParser::parseNoun;
    s_function_map["verbo"] = &DictionaryParser::parseVerb;
    s_function_map["adjektivo"] = &DictionaryParser::parseAdjective;
    s_function_map["adverbo"] = &DictionaryParser::parseAdverb;
    s_function_map["artikolo"] = &DictionaryParser::parseArticle;
    s_function_map["prepozicio"] = &DictionaryParser::parsePreposition;
}

std::deque<std::string> DictionaryParser::splitLine(const std::string& n_line)
{
    std::deque<std::string> t_strings;
    std::string t_string;
    std::stringstream t_stream(n_line);

    while(std::getline(t_stream, t_string, ' '))
    {
        t_strings.push_back(t_string);
    }

    return t_strings;
}

void DictionaryParser::parseInterrogativePronoun(const std::deque<std::string>& n_line, Word& n_word)
{
    parsePronoun(n_line, n_word);
    n_word.type = Word::PRONOUN;
    n_word.is_special = true;
    n_word.is_interrogative = true;
}

void DictionaryParser::parsePronoun(const std::deque<std::string>& n_line, Word& n_word)
{
    parseNoun(n_line, n_word);
    n_word.type = Word::PRONOUN;
    n_word.is_special = true;
}

void DictionaryParser::parseVerb(const std::deque<std::string>& n_line, Word& n_word)
{
    std::deque<std::string>::const_iterator it = n_line.begin();
    bool t_tense_set = false;
    std::string str;

    n_word.type = Word::VERB;

    str = *it;
    if(str == "infinitiva")
    {
        n_word.tense = Word::INFINITIVE;
    }
    else if(str == "nuna")
    {
        n_word.tense = Word::PRESENT;
    }
    else if(str == "pasinta")
    {
        n_word.tense = Word::PAST;
    }
    else if(str == "futura")
    {
        n_word.tense = Word::FUTURE;
    }
    else if(str == "imperativa")
    {
        n_word.tense = Word::JUSSIVE;
    }

    if(n_line.size() > 1) throw SyntaxError(m_file_name, "Too many arguments");
}

void DictionaryParser::parseNoun(const std::deque<std::string>& n_line, Word& n_word)
{
    std::deque<std::string>::const_iterator it = n_line.begin();
    bool t_plural_set = false;
    bool t_function_set = false;
    std::string str;

    n_word.type = Word::NOUN;

    for(; it != n_line.end(); ++it)
    {
        str = *it;

        if(str == "singurala")
        {
            if(t_plural_set) throw SyntaxError(m_file_name, "Number already set");
            n_word.isPlural = false;
            t_plural_set = true;
        }
        else if(str == "plurala")
        {
            if(t_plural_set) throw SyntaxError(m_file_name, "Number already set");
            n_word.isPlural = true;
            t_plural_set = true;
        }
        else if(str == "subject")
        {
            if(t_function_set) throw SyntaxError(m_file_name, "Function already set");
            n_word.function = Word::SUBJECT;
            t_function_set = true;
        }
        else if(str == "object")
        {
            if(t_function_set) throw SyntaxError(m_file_name, "Function already set");
            n_word.function = Word::OBJECT;
            t_function_set = true;
        }
        else if(str == "special")
        {
            n_word.is_special = true;
        }

        else throw SyntaxError(m_file_name, "Unknown argument");
    }
}

void DictionaryParser::parseAdjective(const std::deque<std::string>& n_line, Word& n_word)
{
    parseNoun(n_line, n_word);
    n_word.type = Word::ADJECTIVE;
}

void DictionaryParser::parseAdverb(const std::deque<std::string>& n_line, Word& n_word)
{
    n_word.type = Word::ADVERB;
    if(n_line.size() > 0) throw SyntaxError(m_file_name, "Too many arguments");
}

void DictionaryParser::parsePreposition(const std::deque<std::string>& n_line, Word& n_word)
{
    n_word.type = Word::PREPOSITION;
    if(n_line.size() > 0) throw SyntaxError(m_file_name, "Too many arguments");
}

void DictionaryParser::parseArticle(const std::deque<std::string>& n_line, Word& n_word)
{
    n_word.type = Word::ARTICLE;
    if(n_line.size() > 0) throw SyntaxError(m_file_name, "Too many arguments");
}
