#ifndef SCRABBLE_ASSISTANT_MAIN_H
#define SCRABBLE_ASSISTANT_MAIN_H

#include <iostream>
#include "scrabble_assistant.h"
#include <string>
#include <fstream>

/**
 * Loads the provided dictionary, creating and returning a new ScrabbleAssistant
 * object.
 * @param dictionary_filename The name of the dictionary file to load.  This
 *                            file contains one word per line.
 * @return The new assistant object.
 */
ScrabbleAssistant* create_assistant(std::string dictionary_filename);

/**
 * Reads word from file. Only reads alphabetical words.
 * @param file ifstream in which the words are being read
 * @return a string that contains the next word in the file
 */
std::string read_word(std::istream& file);
/**
 * Answers a series of Scrabble Assistant questions.  Each question is given on
 * a single line in the provided input stream and has of one of the following
 * forms:
 *
 *   "spellcheck WORD"
 *   "anagrams WORD"
 *   "plays WORD"
 *
 * For each question, a response line is written to the output stream as
 * follows:
 *
 *   spellcheck: Just the word "yes" (if the word is in the dictionary) or
 *               or "no" (if it is not).
 *   anagrams: A space-separated list of the legal anagrams of the given word.
 *             If no legal anagrams exist, the line "*none*" is given.
 *   plays: A space-separated list of the legal plays from the given letters.
 *          If no legal plays exist, the line "*none*" is given.
 *
 * @param assistant The object to be used to answer the questions.
 * @param input_stream The stream from which to read questions.
 * @param output_stream The stream to which to write answers.
 */
void answer_scrabble_assistant_questions(
            ScrabbleAssistant* assistant,
            std::istream& input_stream,
            std::ostream& output_stream);

/**
 * The main Scrabble Assistant program.
 * @param argc The number of command-line arguments provided.
 * @param argv The command-line arguments.
 */
int scrabble_assistant_main(int argc, char** argv);

#endif /* SCRABBLE_ASSISTANT_MAIN_H */
