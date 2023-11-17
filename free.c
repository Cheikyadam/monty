#include "main.h"

/**
 * free_c - to free t_line
 * @s: the ptr to free
 *
 * Return: Nothing
 */

void free_c(char *s)
{
	if (s != NULL)
	{
		free(s);
		s = NULL;
	}
}


/**
 * free_p - to free an array of array
 * @a: the array
 *
 * Return: Nothing
 */

void free_p(char **a)
{
	int i = 0;

	if (a != NULL)
	{
		while (a[i] != NULL)
		{
			free(a[i]);
			a[i] = NULL;
			i++;
		}
		if (a[i] != NULL)
		{
			free(a[i]);
			a[i] = NULL;
		}
		if (a != NULL)
		{
			free(a);
			a = NULL;
		}
	}
}
