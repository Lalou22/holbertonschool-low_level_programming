/*
 * File: 1-init_dog.h
 * Auth: Lalo Rdz
 */
#include "dog.h"
/**
 * init_dog - Initialize a variable of type Struct dog.
 * @d: Pointer to structure Dog.
 * @name: Pointer to the dog's name.
 * @age: Float Value represent the dog's age.
 * @owner: Pointer to dog's owner.
 *
 * Return: void
 */
void init_dog(struct dog *d, char *name, float age, char *owner)
{
	if (d)
	{
		d->name = name;
		d->age = age;
		d->owner = owner;
	}
}
