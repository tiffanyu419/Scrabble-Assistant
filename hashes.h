#ifndef HASHES_H
#define HASHES_H

#include <string>

// NOTE:
// This file declares a number of different functions all called "hash".  C++
// will determine which function you mean to call based upon the type of the
// argument you give; that is, if you call hash and pass it an int, you'll get
// the int version of hash.  This behavior is called "overloading".

/**
 * Generates a hash code for an integer.
 * @param value The integer to hash.
 * @return The hash of the provided integer.
 */
int hash(int value);

/**
 * Generates a hash code for a string.
 * @param value The string to hash.
 * @return The hash of the provided string.
 */
int hash(std::string value);

// NOTE:
// You could add as many hash functions as you wanted here.  If you wanted to
// be able to hash objects of some class, for instance, you could add such a
// hash function here.  You *must* have a hash function *somewhere* for each
// type of key your HashTable will have, though.

/**
 * A helper function to restrict hash values to a particular range.  This
 * function is like modulus from Python: it guarantees a positive result.  This
 * is helpful for turning a hash value into an array index.
 * @param dividend The number subject to modulus.
 * @param divisor The modulus base.
 * @return A number in the range 0..divisor-1 (inclusive).
 */
int positive_modulus(int dividend, int divisor);

#endif /* HASHES_H */
