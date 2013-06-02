#include "dictionnary.h"
#include <algorithm>

Dictionnary::Dictionnary()
{
    Word* t_entry=0;

    t_entry=new Word;
    t_entry->str="mi";
    t_entry->str_base="mi";
    t_entry->type=Word::PRONOUN;
    t_entry->function=Word::SUBJECT;
    t_entry->tense=Word::NO_TENSE;
    t_entry->isPlural=false;
    t_entry->node=0;
    t_entry->link_node=0;
    m_known_words.insert(t_entry);

    t_entry=new Word;
    t_entry->str="min";
    t_entry->str_base="mi";
    t_entry->type=Word::PRONOUN;
    t_entry->function=Word::ACCUSATIVE;
    t_entry->tense=Word::NO_TENSE;
    t_entry->isPlural=false;
    t_entry->node=0;
    t_entry->link_node=0;
    m_known_words.insert(t_entry);

    t_entry=new Word;
    t_entry->str="vi";
    t_entry->str_base="vi";
    t_entry->type=Word::PRONOUN;
    t_entry->function=Word::SUBJECT;
    t_entry->tense=Word::NO_TENSE;
    t_entry->isPlural=false;
    t_entry->node=0;
    t_entry->link_node=0;
    m_known_words.insert(t_entry);

    t_entry=new Word;
    t_entry->str="vin";
    t_entry->str_base="vi";
    t_entry->type=Word::PRONOUN;
    t_entry->function=Word::ACCUSATIVE;
    t_entry->tense=Word::NO_TENSE;
    t_entry->isPlural=false;
    t_entry->node=0;
    t_entry->link_node=0;
    m_known_words.insert(t_entry);
}

Dictionnary::~Dictionnary()
{
    std::set<Word*>::iterator t_words_it=m_known_words.begin();
    for(; t_words_it!=m_known_words.end(); ++t_words_it)
        delete *t_words_it;
}

Word* Dictionnary::getEntry(const std::string& n_str)
{
    Word* t_entry;
    std::set<Word*>::iterator t_found;
    t_found=std::find_if(m_known_words.begin(),m_known_words.end(),FindEntry(n_str));

    if(t_found!=m_known_words.end())
    {
        t_entry=*t_found;
    }
    else
    {
        t_entry=createNewEntry(n_str);
    }

    return t_entry;
}

/*
 * This function can only create nouns, adjectives and verbs entries.
 */
Word* Dictionnary::createNewEntry(const std::string& n_str)
{
    Word* t_entry=new Word;
    t_entry->str=n_str;
    t_entry->isPlural=false;
    t_entry->function=Word::SUBJECT;
    t_entry->node=0;
    t_entry->link_node=0;
    std::string t_str(n_str);

    unsigned int char_pos=t_str.size()-1;
    char t_char=t_str[char_pos];

    if(t_char=='n') // Accusative case
    {
        t_entry->function=Word::ACCUSATIVE;
        t_str.erase(char_pos--);
        t_char=t_str[char_pos];
    }

    if(t_char=='j') // Plural
    {
        t_entry->isPlural=true;
        t_str.erase(char_pos--);
        t_char=t_str[char_pos];
    }

    if(t_char=='o') // Noun
    {
        t_entry->type=Word::NOUN;
    }
    else if(t_char=='a') // Adjective
    {
        t_entry->type=Word::ADJECTIVE;
    }
    else // Verb
    {
        t_entry->type=Word::VERB;
        t_entry->function=Word::NO_CASE;

        if(t_char=='i')
        {
            t_entry->tense=Word::INFINITIVE;
        }
        else if(t_char=='u')
        {
            t_entry->tense=Word::JUSSIVE;
        }
        else if(t_char=='s')
        {
            t_str.erase(char_pos--);
            t_char=t_str[char_pos];

            if(t_char=='i')
            {
                t_entry->tense=Word::PAST;
            }
            else if(t_char=='a')
            {
                t_entry->tense=Word::PRESENT;
            }
            else if(t_char=='o')
            {
                t_entry->tense=Word::FUTURE;
            }
        }

        t_str[char_pos]='i';
    }

    t_entry->str_base=t_str;

    std::set<Word*>::iterator t_found;
    t_found=std::find_if(m_known_words.begin(),m_known_words.end(),FindEntry(t_str));

    if(t_found!=m_known_words.end())
    {
        t_entry->node=(*t_found)->node;
    }
    m_known_words.insert(t_entry);

    return t_entry;
}
