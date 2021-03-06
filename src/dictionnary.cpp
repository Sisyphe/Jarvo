#include "dictionnary.h"
#include <algorithm>
#include "dictionaryparser.h"

Dictionnary::Dictionnary()
{
    std::vector<Word> t_entries;
    std::vector<Word>::iterator t_entry;

    DictionaryParser t_dict_parser;
    t_dict_parser.parseFile("dictionary", t_entries);

    for(t_entry = t_entries.begin(); t_entry != t_entries.end(); ++t_entry)
    {
        Word t_word = *t_entry;
        m_known_words.insert(new Word(t_word));
    }
}

Dictionnary::~Dictionnary()
{
    std::set<Word*>::iterator t_words_it = m_known_words.begin();

    for(; t_words_it != m_known_words.end(); ++t_words_it)
    {
        delete *t_words_it;
    }
}

Word* Dictionnary::getEntry(const std::string& n_str)
{
    Word* t_entry;
    std::set<Word*>::iterator t_found;
    t_found = std::find_if(m_known_words.begin(), m_known_words.end(), FindEntry(n_str));

    if(t_found != m_known_words.end())
    {
        t_entry = *t_found;
    }
    else
    {
        t_entry = createNewEntry(n_str);
    }

    return t_entry;
}

/*
 * This function can only create nouns, adjectives and verbs entries.
 */
Word* Dictionnary::createNewEntry(const std::string& n_str)
{
    Word* t_entry = new Word;
    t_entry->type = Word::UNKNOWN_TYPE;
    t_entry->str = n_str;
    t_entry->isPlural = false;
    t_entry->function = Word::NO_CASE;
    t_entry->node = 0;
    t_entry->link_node = 0;

    bool t_is_unknown = false;
    std::string t_str(n_str);

    unsigned int char_pos = t_str.size() - 1;
    char t_char = t_str[char_pos];

    if(t_char == 'n') // Accusative case
    {
        t_entry->function = Word::OBJECT;
        t_str.erase(char_pos--);
        t_char = t_str[char_pos];
    }

    if(t_char == 'j') // Plural
    {
        t_entry->isPlural = true;
        t_str.erase(char_pos--);
        t_char = t_str[char_pos];
    }


    switch(t_char)
    {
        case 'o': // Noun
        {
            t_entry->type = Word::NOUN;

            if(t_entry->function == Word::NO_CASE)
            {
                t_entry->function = Word::SUBJECT;
            }

            break;
        }

        case 'a': // Adjective
        {
            t_entry->type = Word::ADJECTIVE;

            if(t_entry->function == Word::NO_CASE)
            {
                t_entry->function = Word::SUBJECT;
            }

            break;
        }

        case 'e': // Adverb
        {
            t_entry->type = Word::ADVERB;
            t_entry->function = Word::NO_CASE;
            break;
        }

        case 'i': // Infinitive verb
        {
            t_entry->type = Word::VERB;
            t_entry->function = Word::NO_CASE;
            t_entry->tense = Word::INFINITIVE;
            break;
        }

        case 'u': // Jussive verb
        {
            t_entry->type = Word::VERB;
            t_entry->function = Word::NO_CASE;
            t_entry->tense = Word::JUSSIVE;
            t_str[char_pos] = 'i';
            break;
        }

        case 's': // Active verb
        {
            t_entry->type = Word::VERB;
            t_entry->function = Word::NO_CASE;
            t_str.erase(char_pos--);
            t_char = t_str[char_pos];
            t_str[char_pos] = 'i';

            switch(t_char)
            {
                case 'i': // Past tense
                {
                    t_entry->tense = Word::PAST;
                    break;
                }

                case 'a': // Present tense
                {
                    t_entry->tense = Word::PRESENT;
                    break;
                }

                case 'o': // Future tense
                {
                    t_entry->tense = Word::FUTURE;
                    break;
                }

                default: t_is_unknown = true;
            }

            break;
        }

        default: t_is_unknown = true;
    }

    t_entry->str_base = t_str;

    std::set<Word*>::iterator t_found;
    t_found = std::find_if(m_known_words.begin(), m_known_words.end(), FindEntry(t_str, true));

    if(t_found != m_known_words.end())
    {
        t_entry->node = (*t_found)->node;

        if(t_is_unknown)
        {
            t_entry->type = (*t_found)->type;
            t_is_unknown = false;
        }
    }

    if(t_is_unknown) // Unknown => Special noun
    {
        if(t_str[0] == '\"')
        {
            t_str.erase(0, 1);
            t_str.erase(t_str.size() - 1, 1);
        }
        else t_str = n_str;

        t_entry->type = Word::NOUN;
        t_entry->str = n_str;
        t_entry->str_base = t_str;
        t_entry->isPlural = false;
        t_entry->function = Word::BOTH_CASE;
        t_entry->tense = Word::NO_TENSE;
        t_entry->is_special = true;
    }

    m_known_words.insert(t_entry);

    return t_entry;
}
