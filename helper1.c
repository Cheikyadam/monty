#include "monty.h"

/**
 * letters_f - number of bytes of a file
 * @file: the file
 *
 * Return: the number of bytes
 */

size_t letters_f(const char *file)
{
	size_t i = 0;
	struct stat st;

	if (stat(file, &st) == 0)
		i = st.st_size;
	else
		i = -1;
	return (i);
}

/**
 * _strlen - lenght
 * @s: lenght of s
 *
 * Return: an int
 */

int _strlen(char *s)
{
	int i = 0;

	if (s != NULL)
		for (i = 0; s[i] != '\0'; i++)
			;
	return (i);
}
/**
 * _strcmp - comparison
 * @s1: first string
 * @s2: 2nd string
 *
 * Return: an integer
 */

int _strcmp(char *s1, char *s2)
{
	if (s1 == NULL && s2 == NULL)
		return (0);
	if (s1 == NULL || s2 == NULL)
		return (-1);

	while ((*s1) == (*s2) && (*s1) != '\0')
	{
		s1++;
		s2++;
	}
	if (((*s1) == '\0') && ((*s2) != '\0'))
		return (-1);
	if (((*s2) == '\0') && ((*s1) != '\0'))
		return (-1);
	if ((*s1) == '\0')
		s1--;
	if ((*s2) == '\0')
		s2--;
	return ((*s1) - (*s2));
}

/**
 * delete_letter - delete letter that is not useful
 * @s: in this string
 * @d: the letter to delete
 *
 * Return: Nothing
 */

void delete_letter(char *s, const char d[])
{
	int l = 0, i = 0, j = 0;

	if (s != NULL)
	{
		if (s[0] != '\0')
		{
			l = _strlen(s);
			for (i = 0; i < l - 1; i++)
			{
				if (s[i] == d[0] && s[i + 1] == d[0])
				{
					for (j = i + 1; j < l; j++)
						s[j] = s[j + 1];
					i--;
				}
			}

			l = _strlen(s);
			if (s[l - 1] == d[0])
				s[l - 1] = '\0';

			l = _strlen(s);
			if (s[0] == d[0])
			{
				for (i = 0; i < l - 1; i++)
					s[i] = s[i + 1];
				s[l - 1] = '\0';
			}
		}
	}
}


/**
 * _strcpy - copying
 * @src: source
 * @dest: destination
 *
 * Return: char *
 */

char *_strcpy(char *dest, char *src)
{
	int i;

	if (dest == NULL || src == NULL)
		return (NULL);
	for (i = 0; src[i] != '\0'; i++)
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}
