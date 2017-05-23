# Scrabble Assistant Using Hashtables
by Tiffany Yu and Jacky Ye

An implimentation of a hash table dictionary structure is used to create a tool that helps
find solutions to word games such as Scrabble. Code written in C++

1. Defining the Hash Table
#### hash_table.h/hash_table__definitions.h
Using the given dictionary.h (the dictionary interface) and hashes.h/hashes.cpp (hash implementations)
we created a hash table class that implements a functional hash table dictionary structure

2. Scrabble Assistant
#### scrabble_assistant.h/scrabble_assistant.cpp
Class that implements the specific functions wanted in the tool such as identifying anagrams
#### scrabble_assistant_main.h/scrabble_assistant_main.cpp
Programs that brings all the tools together and responds to user input. 
#### program.cpp
Calls the main function from scrabble_assistant_main.

3. Determining Performance
#### stat_collection.cpp
Shows the internal statistics of the hashtable. Includes percentage of buckets empty, average size of
non-empty buckets, size of largest bucket


