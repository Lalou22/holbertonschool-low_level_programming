/*
 * File: dog.h
 * Auth: Lalo Rdz
 */
#ifndef _DOG_H_
#define _DOG_H_

/**
 * struct dog - Structure that represents a dog
 * @name: Char array (String) used for the dog's name.
 * @age: Float value used to store the dog's age.
 * @owner: Char array (String) used for the dog's owner.
 */
struct dog
{
	char *name;
	float age;
	char *owner;
};

/**
 * dog_t - New type dog_t as a new name for the type struct dog.
 */
typedef struct dog dog_t;

void init_dog(struct dog *d, char *name, float age, char *owner);
void print_dog(struct dog *d);
dog_t *new_dog(char *name, float age, char *owner);
void free_dog(dog_t *d);

#endif /* _DOG_H_ */
