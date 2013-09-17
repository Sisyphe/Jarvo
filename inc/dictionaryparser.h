#ifndef DICTIONARYPARSER_H
#define DICTIONARYPARSER_H

#include <vector>
#include <string>
#include <list>
#include "word.h"
#include <stdexcept>
#include <sstream>
#include <fstream>

class SyntaxError: public std::runtime_error
{
    public:

        SyntaxError(const std::string& n_file_name, int n_line = -1):
            std::runtime_error(""),
            m_file_name(n_file_name),
            m_error("Unknown error"),
            m_line(n_line){}

        SyntaxError(const std::string& n_file_name, const std::string& n_error, int n_line = -1):
            std::runtime_error(""),
            m_file_name(n_file_name),
            m_error(n_error),
            m_line(n_line){}

        virtual ~SyntaxError() throw(){}

        virtual const char* what() const throw()
        {
            std::stringstream t_stream;

            t_stream << "Syntax error (" << m_file_name;

            if(m_line > 0) t_stream << ":" << m_line;

            t_stream << "): " << m_error;

            return t_stream.str().c_str();
        }

        std::string error() const
        {
            return m_error;
        }

    protected:
        std::string m_file_name;
        std::string m_error;
        int m_line;
};

class CriticalSyntaxError: public SyntaxError{};

class DictionaryParser
{
    typedef void (DictionaryParser::* ParsingFunction)(const std::deque<std::string>&, Word&);
    typedef std::map<std::string, ParsingFunction>::iterator FunctionMapIt;

    public:

        void parseFile(const std::string& n_file_name, std::vector<Word>& n_words);

    protected:

        void fillFunctionMap();
        std::deque<std::string> splitLine(const std::string& n_line);

        void parseInterrogativePronoun(const std::deque<std::string>& n_line, Word& n_word);
        void parsePronoun(const std::deque<std::string>& n_line, Word& n_word);
        void parseNoun(const std::deque<std::string>& n_line, Word& n_word);
        void parseVerb(const std::deque<std::string>& n_line, Word& n_word);
        void parseAdjective(const std::deque<std::string>& n_line, Word& n_word);
        void parseAdverb(const std::deque<std::string>& n_line, Word& n_word);
        void parseArticle(const std::deque<std::string>& n_line, Word& n_word);
        void parsePreposition(const std::deque<std::string>& n_line, Word& n_word);

        std::string m_file_name;
        std::ifstream m_file;
        static std::map<std::string, ParsingFunction> s_function_map;
};

#endif // DICTIONARYPARSER_H
