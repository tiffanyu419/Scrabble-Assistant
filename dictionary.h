#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <vector>

/**
 * The interface for a general dictionary data structure.
 */
template<typename K, typename V>
class Dictionary {
public:
    /**
     * Retrieves an element from the dictionary.
     * @param key The key to use to retrieve an element.
     * @return The value mapped from that key.
     * @throws runtime_error If the key does not exist in this dictionary.
     */
    virtual V get(K key) = 0;

    /**
     * Puts an element into this dictionary.  Any previous mapping for this key
     * is replaced.
     * @param key The key to map.
     * @param value The value to which to map the key.
     */
    virtual void put(K key, V value) = 0;

    /**
     * Removes a mapping from this dictionary by its key.  If the key is not
     * mapped in this dictionary, nothing happens.
     */
    virtual void remove(K key) = 0;

    /**
     * Determines the number of mappings stored in this dictionary.
     * @return The number of stored mappings.
     */
    virtual int get_size() = 0;

    /**
     * Determines whether this dictionary is empty.
     * @return true if this dictionary is empty; false if it is not.
     */
    virtual bool is_empty() = 0;

    /**
     * Obtains all of the keys from this dictionary.
     * @return A vector containing all of the keys in this dictionary.
     */
    virtual std::vector<K> get_all_keys() = 0;

    /** Virtual destructor for correct object deletion. */
    virtual ~Dictionary() { }
};

#endif /* DICTIONARY_H */
