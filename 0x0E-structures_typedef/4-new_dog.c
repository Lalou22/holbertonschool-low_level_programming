/*
 * File: 4-new_dog.h
 * Auth: Lalo Rdz
 */
#include "dog.h"
#include <stdlib.h>
/**
 * new_dog - Initialize a variable of type Struct dog.
 * @name: Pointer to the dog's name.
 * @age: Float Value represent the dog's age.
 * @owner: Pointer to dog's owner.
 *
 * Return: Pointer to the new dog.
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	unsigned int i, j;
	dog_t *new_doggo;

	if (name == NULL || age < 0 || owner == NULL) /*Checks for correct info*/
		return (NULL);
	new_doggo = malloc(sizeof(dog_t)); /*Creates new doggo*/
	if (new_doggo == NULL)
		return (NULL);

	for (j = 0; name[j]; j++) /*Gets name lenght*/
		;
	j++;
	new_doggo->name = malloc(j * sizeof(char)); /*Creates char array*/
	if (new_doggo->name == NULL)
	{
		free(new_doggo); /*Checks for NULL-error on the doggo name*/
		return (NULL);
	}
	for (i = 0; i < j; i++)
		new_doggo->name[i] = name[i];

	if (age < 0)
		return (NULL); /*Checks for Negative-Age error*/
	new_doggo->age = age;

	for (j = 0; owner[j]; j++) /*Gets owner's name lenght*/
		;
	j++;
	new_doggo->owner = malloc(j * sizeof(char)); /*Creates char array*/
	if (new_doggo->owner == NULL)
	{
		free(new_doggo); /*Checks for NULL-error on the doggo name*/
		return (NULL);
	}
	for (i = 0; i < j; i++)
		new_doggo->owner[i] = owner[i];

	return (new_doggo); /*Returns the doggo*/
}
