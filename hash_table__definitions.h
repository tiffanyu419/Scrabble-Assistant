#include <iostream>
#include <stdexcept>
#include "hashes.h"
#include <vector>

template <typename K, typename V>
HashTable<K,V>::HashTable() {
    size = 0;
    max_load_factor = 0.75;
    hashtable = new std::vector< std::pair<K,V> > [10];
    capacity = 10;
    }

template <typename K, typename V>
HashTable<K,V>::HashTable(float max_load_factor) {
    size = 0;
    this->max_load_factor = max_load_factor;
    hashtable = new std::vector< std::pair<K,V> > [10];
    capacity = 10;
    }


template <typename K, typename V>
HashTable<K,V>::~HashTable() {
    /*for (int i=0; i < capcacity; i++) {
        delete hashtable[i];
    }*/ //need to use this if hashtable contains array of DYNAMICALLY allocated vectors
    delete[] hashtable;
}

template <typename K, typename V>
V HashTable<K,V>::get(K key) {
    if (size == 0) {
        throw std::runtime_error("Invalid access. There's nothing in this hashtable.");
    }
    int index = hash(key);
    index = positive_modulus(index, capacity);
    for (int i=0; i < hashtable[index].size(); i++) {
        if (hashtable[index].at(i).first == key) {
            return hashtable[index].at(i).second;
        }
    }
    throw std::runtime_error("Item not found.");
}

template <typename K, typename V>
void HashTable<K,V>::put(K key, V value) {
    ensure_capacity();
    int index = hash(key);
    index = positive_modulus(index, capacity);
    std::pair<K,V> new_pair(key, value);
    if (hashtable[index].size() == 0){ //Checks if this vector is empty
        hashtable[index].push_back(new_pair);
        size += 1;
    } else{ //If vector has something in it, finds next available spot
        bool contains = false;
        for (int i=0;i<hashtable[index].size();i++){
            if (key == hashtable[index].at(i).first){
                hashtable[index].at(i) = new_pair;
                contains = true;
            }
        }
        if (contains == false){
            hashtable[index].push_back(new_pair);
        }
    }
}

template <typename K, typename V>
void HashTable<K,V>::remove(K key) {
    int index = hash(key);
    index = positive_modulus(index, capacity);
    std::vector<std::pair<K,V> > chain = hashtable[index];
    chain.erase(chain.begin() + 0, chain.begin() + (chain.size()-1));
    size -= 1;
}

template <typename K, typename V>
int HashTable<K,V>::get_size() {
    return size;
}

template <typename K, typename V>
bool HashTable<K,V>::is_empty() {
    if (size == 0){
        return true;
    } else {
        return false;
    }
}

template <typename K, typename V>
std::vector<K> HashTable<K,V>::get_all_keys() {
    std::vector<K> key_vector;
    for (int i=0;i<size;i++){
        std::vector<std::pair<K,V> > chain = hashtable[i];
        for (int j=0;j<chain.size();j++){
            key_vector.push_back(chain.at(j).first);
        }
    }
    return key_vector;
}

template <typename K, typename V>
void HashTable<K,V>::ensure_capacity() {
    if ((size / capacity) > max_load_factor) {
        std::vector< std::pair<K,V> >* new_hashtable = new std::vector< std::pair<K,V> > [capacity*2];
        for (int i=0;i<size;i++){
            new_hashtable[i]= hashtable[i];
        }
        capacity = capacity*2;
        delete[] hashtable;
        hashtable = new_hashtable;
    }
}

template<typename K, typename V>
bool HashTable<K,V>::contains(K key) {
    if (size == 0) {
        return false;
    }
    int index = hash(key);
    index = positive_modulus(index, capacity);
    for (int i=0; i < hashtable[index].size(); i++) {
        if (hashtable[index].at(i).first == key) {
            return true;
        }
    }
    return false;
}
template <typename K, typename V>
void HashTable<K,V>::print_stats() {
    float empty_percentage = ((capacity - size)/capacity)*100;
    float avg_size;
    float accumulator;
    int largest_bucket = 0;
    for (int i=0;i<capacity;i++){
        accumulator += hashtable[i].size();
        if (hashtable[i].size() > largest_bucket){
            largest_bucket = hashtable[i].size();
        }
    }
    avg_size = accumulator/size;
    std::cout<<"Empty Percentage: " << empty_percentage<< std::endl;

}
