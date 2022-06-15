#include "hash_tables.h"

/**
 * key_index - Function that gives you the index of a key.
 * @key: key to get index for
 * @size: size of the hash table
 *
 * Description: Function that gives you the index of a key.
 * This function should use the hash_djb2 function.
 * Return: index at which the key/value pair should be stored.
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	return (hash_djb2(key) % size);
}
