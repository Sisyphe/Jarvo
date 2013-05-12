#ifndef WORD_H
#define WORD_H

#include <string>

class Word
{
    public:

        enum Type
        {
            UNKNOWN,
            NAME,
            VERB,
            ADJECTIVE,
            CONJUNCTION,
            PREPOSITION,
            ADVERB
        };

        Word();

        Word(const std::string& n_str);

        void setString(const std::string& n_str);

        Type type() const;

        bool operator==(const std::string& n_str);

    protected:

        std::string m_str;
        Type m_type;
};

#endif // WORD_H
