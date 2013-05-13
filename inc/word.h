#ifndef WORD_H
#define WORD_H

#include <string>

class Word
{
    public:

        enum Type
        {
            UNKNOWN,
            NOUN,
            VERB,
            ADJECTIVE,
            CONJUNCTION,
            PREPOSITION,
            ADVERB
        };

        enum Function
        {
            NONE,
            SUBJECT,
            ACCUSATIVE
        };

        Word();

        Word(const std::string& n_str);

        void setString(const std::string& n_str);

        Type type() const;

        virtual Word* get();

    protected:

        std::string m_str;
        Type m_type;
};

#endif // WORD_H
