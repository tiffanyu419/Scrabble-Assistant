#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <vector>
#include <utility> // for the "pair" STL class
#include "dictionary.h"

template <typename K, typename V>
class HashTable : public Dictionary<K,V> {
public:
    /**
     * Creates a new HashTable with a load factor of 0.75.
     */
    HashTable();

    /**
     * Creates a new HashTable.
     * @param max_load_factor The maximum load factor which will be admitted
     *                        before this hash table changes its capacity.
     */
    HashTable(float max_load_factor);
    /**
     * Cleans up this HashTable.
     */
    ~HashTable();

    V get(K key);
    void put(K key, V value);
    void remove(K key);
    int get_size();
    bool is_empty();
    std::vector<K> get_all_keys();

    /**
     * This method writes to cout some information about the internal state of
     * this HashTable.
     */
    void print_stats();
    bool contains(K key);

private:

    /* TODO: put your fields and methods here */
    float size;
    int capacity;
    float max_load_factor;
    std::vector< std::pair<K,V> >* hashtable;
    void ensure_capacity();
};

#include "hash_table__definitions.h"

#endif /* HASH_TABLE_H */
