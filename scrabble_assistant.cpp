#include <algorithm>
#include <stdexcept>
#include "scrabble_assistant.h"
#include <string>
#include <iostream>

using namespace std;

ScrabbleAssistant::ScrabbleAssistant() {
    scrabble_assistant = new HashTable<string,vector<string> >();
    dictionary = new HashTable<string,bool>();
}

ScrabbleAssistant::~ScrabbleAssistant() {
    delete scrabble_assistant;
    delete dictionary;
}

void ScrabbleAssistant::add_word(string word) {
    if (dictionary -> contains(word)){
        return;
    }
    else {
        dictionary -> put(word,true);
        vector<string> anagrams = anagrams_of(word);
        if (anagrams.size() > 0){ //if this word already has anagrams
            anagrams.push_back(word);
            scrabble_assistant -> put(sort_word(word),anagrams);
        } else { //this word doesn't contain anagrams and sets itself as one of its anagrams
            vector<string> new_value;
            new_value.push_back(word);
            scrabble_assistant -> put(sort_word(word),new_value);
        }
    }
}

bool ScrabbleAssistant::spellcheck(std::string word) {
    return dictionary -> contains(word);
}

vector<string> ScrabbleAssistant::anagrams_of(std::string letters) {
    string sorted_word = sort_word(letters);
    vector<string> anagrams;
    if (scrabble_assistant->contains(sorted_word)){
        anagrams = scrabble_assistant->get(sorted_word);
    }
    return anagrams;
}

vector<string> ScrabbleAssistant::find_words(string letters) {
    vector<string> combinations = find_combinations(letters);
    vector<string> words;
    for (int i=0;i<combinations.size();i++){
        vector<string> anagrams = anagrams_of(combinations[i]);
        for (int j=0;j<anagrams.size();j++){
            words.push_back(anagrams.at(j));
        }
    }
    sort(words.begin(), words.end());
    return words;
}

vector<string> ScrabbleAssistant::find_combinations(string word) {
    vector<string> combinations;
    if (word.length() == 1){
        combinations.push_back("");
        combinations.push_back(word);
        return combinations;
    } else {
        combinations = find_combinations(word.substr(1,(word.length()-1)));
        int size = combinations.size();
        for (int i=0;i<size;i++){
            string element = word[0]+combinations[i];
            combinations.push_back(element);
        }
        return combinations;
    }
}
string ScrabbleAssistant::sort_word(string word){
    sort(word.begin(), word.end());
    return word;
}
