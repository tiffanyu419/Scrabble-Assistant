#include "hash_table.h"
#include <stdexcept>
#include "scrabble_assistant.h"

using namespace std;

int main(int argc, char** argv) {
    // The purpose of this small program is to allow you to build HashTables and
    // then invoke their print_stats methods.  You can use the data that you
    // gather to complete the written portion of the assignment.
    //
    // Ideally, you will leave every data structure you create in this program
    // (in the same way that you never delete a test).  That way, you (and we)
    // can reproduce your results.

    //Load factor 0.1
    HashTable<int,string>* dictionary_1 = new HashTable<int,string>(0.1);
    for (int i=0;i<10000;i++) {
        dictionary_1->put(i, to_string(i));
    }
    dictionary_1 -> print_stats();

    //Load factor 0.2
    HashTable<int,string>* dictionary_2 = new HashTable<int,string>(0.2);
    for (int i=0;i<10000;i++) {
        dictionary_2->put(i, to_string(i));
    }
    dictionary_2 -> print_stats();

    //Load factor 0.3
    HashTable<int,string>* dictionary_3 = new HashTable<int,string>(0.3);
    for (int i=0;i<10000;i++) {
        dictionary_3->put(i, to_string(i));
    }
    dictionary_3 -> print_stats();

    //Load factor 0.4
    HashTable<int,string>* dictionary_4 = new HashTable<int,string>(0.4);
    for (int i=0;i<10000;i++) {
        dictionary_4->put(i, to_string(i));
    }
    dictionary_4 -> print_stats();

    //Load factor 0.5
    HashTable<int,string>* dictionary_5 = new HashTable<int,string>(0.5);
    for (int i=0;i<10000;i++) {
        dictionary_5->put(i, to_string(i));
    }
    dictionary_5 -> print_stats();

    //Load factor 0.6
    HashTable<int,string>* dictionary_6 = new HashTable<int,string>(0.6);
    for (int i=0;i<10000;i++) {
        dictionary_6->put(i, to_string(i));
    }
    dictionary_6 -> print_stats();

    //Load factor 0.7
    HashTable<int,string>* dictionary_7 = new HashTable<int,string>(0.7);
    for (int i=0;i<10000;i++) {
        dictionary_7->put(i, to_string(i));
    }
    dictionary_7 -> print_stats();

    //Load factor 0.8
    HashTable<int,string>* dictionary_8 = new HashTable<int,string>(0.8);
    for (int i=0;i<10000;i++) {
        dictionary_8->put(i, to_string(i));
    }
    dictionary_8 -> print_stats();

    return 0;
}
