#include "main.h"
#include <unistd.h>

/**
 * _putchar - prints a character to stdout
 * @c: the character
 * Return: 1 success
 *
 * Description: _putchar will use a buffer of size 1024 to call write function
 */

int _putchar(char c)
{
	static char buf[1024];
	static int i;

	if (c == -1 || i >= 1024)
	{
		write(1, &buf, i);
		i = 0;
	}

	if (c != -1)
	{
		buf[i] = c;
		i++;
	}

	return (1);
}

/**
 * _puts - prints a string
 * @str: pointer to the string
 * Return: number of character written
 */

int _puts(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
		_putchar(str[i]);
	return (i);
}
