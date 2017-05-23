#include <fstream>
#include <stdexcept>
#include "scrabble_assistant_main.h"
#include <iostream>

using namespace std;

string read_word(istream& file) {
	string word = "";
	int input = file.peek();
	if (input == EOF) {
		// This will happen if we reach the end of the file on our first read
		// or if we encounter an I/O error (e.g. bad hard disk).
		throw runtime_error("Error while reading word from file.");
	}
	file >> word;
	return word;
}

ScrabbleAssistant* create_assistant(string dictionary_filename) {
    ScrabbleAssistant* scrabble = new ScrabbleAssistant();
    string word;

    ifstream dictionary(dictionary_filename.c_str());
    if (dictionary.fail()){
        throw runtime_error("Failed to read dictionary");
    }
    while (!dictionary.eof()) {
        dictionary >> word;
        scrabble -> add_word(word);
   }
   return scrabble;
}


void answer_scrabble_assistant_questions(ScrabbleAssistant* assistant,
    istream& input_stream, ostream& output_stream) {
        string word;
		string command = read_word(input_stream);
        while (!input_stream.eof()) {
            if (command == "spellcheck") {
                //spellchecking the word; returns yes if in dictionary; else returns no
                word = read_word(input_stream);
                if (assistant->spellcheck(word)) {
                    output_stream << "yes";
                } else {
                    output_stream << "no";
                }
				output_stream << endl;
            } else if (command == "anagrams") {
                //finds anagrams of a word; returns list of anagrams if valid; else returns none
                word = read_word(input_stream);
                vector<string> anagrams = assistant->anagrams_of(word);
                if (anagrams.size() > 0) {
                    for (int i=0; i < anagrams.size(); i++) {
                        output_stream << anagrams.at(i) << " ";
                    }
                    output_stream << endl;
                } else {
                    output_stream << "*none*" << endl;
                }
            } else if (command == "plays") {
                //finds all possible words that can be played and returns them as a list; else returns none
                word = read_word(input_stream);
                vector<string> plays = assistant->find_words(word);
                if (plays.size() > 0) {
                    for (int i=0; i < plays.size(); i++) {
                        output_stream << plays.at(i) << " ";
                    }
                    output_stream << endl;
                } else {
                    output_stream << "*none*" << endl;
                }
            } else {
                cout << "Incorrect command"<<endl;
            }
			command = read_word(input_stream);
        }
}

int scrabble_assistant_main(int argc, char** argv) {
    if (argc == 2) {
        //run interactive mode
		string dictionary = argv[1];
        ScrabbleAssistant* scrabble = create_assistant(dictionary);
        answer_scrabble_assistant_questions(scrabble, cin, cout);
		delete scrabble;
    }
    else if (argc == 4) {
        //run batch mode
		string dictionary = argv[1];
        ScrabbleAssistant* scrabble = create_assistant(dictionary);
        ifstream text(argv[2]);
        if (text.fail()) {
            throw runtime_error("Failure while opening file.");
        }
        string out_path = argv[3];
        ofstream out_file(out_path.c_str());
        answer_scrabble_assistant_questions(scrabble, text, out_file);
		delete scrabble;
    }
    else {
        throw runtime_error("Invalid number of arguments");
    }
    return 0;
}
