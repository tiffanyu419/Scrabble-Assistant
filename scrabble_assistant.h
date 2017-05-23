#ifndef SCRABBLE_ASSISTANT_H
#define SCRABBLE_ASSISTANT_H

#include <string>
#include <vector>
#include "hash_table.h"
#include "hashes.h"

class ScrabbleAssistant {
public:
    ScrabbleAssistant();
    ~ScrabbleAssistant();

    /**
     * This method adds a new word to this object.  This object will then add
     * to its internal data structures all of the information it needs in order
     * to associate this word with the letters that could be used to spell it.
     * @param word The word for this assistant to remember.
     */
    void add_word(std::string word);

    /**
     * Checks to determine if the provided word is spelled correctly.  This
     * operation should be performed in CONSTANT time.
     * @param word The word in question.
     * @return true if this is a valid word; false if it is not.
     */
    bool spellcheck(std::string word);

    /**
     * Finds all anagrams of the provided letters.  This function finds all
     * permutations of the provided letters which form valid words.
     * @param letters The letters to check.  These letters are not necessarily
     *                in any particular order.
     * @return The words which can be spelled by permuting those letters.
     */
    std::vector<std::string> anagrams_of(std::string letters);

    /**
     * This method produces a vector of the words that could be spelled given
     * the provided series of letters.
     * @param letters The sequence of letters for which we want to find a word.
     *                These letters are not necessarily in any particular order.
     * @return A vector of the words that the player could spell with these
     *         letters.
     */
    std::vector<std::string> find_words(std::string letters);

private:
    HashTable<std::string, std::vector<std::string> >* scrabble_assistant;
    HashTable<std::string, bool>* dictionary;
    /**
     * sorts the string of words in alphabetical order.
     * @param string to be sorted_word
     * @return sorted string of word
     */
    std::string sort_word(std::string word);
    std::vector<std::string> find_combinations(std::string word);
};

#endif /* SCRABBLE_ASSISTANT_H */
