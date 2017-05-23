
#include <string>
#include "hashes.h"

int hash(int value) {
    // This seems ridiculous, but it's actually quite important: the HashTable
    // class is going to call *some* hash function.  If the key is an int, it
    // needs to call this one.
    return value;
}

int hash(std::string value) {
    int hash_value = 0;
    for (int i=0;i<value.length();i++) {
        hash_value *= 31; // prime number helps to avoid hash collisions
        hash_value += value[i]; // remember: characters can be treated as ints
    }
    return hash_value;
}

int positive_modulus(int dividend, int divisor) {
    int answer = dividend % divisor;
    if (answer < 0) {
        answer += divisor;
    }
    return answer;
}
