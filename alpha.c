#include "main.h"
#include <stdarg.h>

/**
 * print_string - prints inputted string
 * @list: va_list from _printf
 * @f: flags point
 * Return: total characters printed
 */

int print_string(va_list list, flags_t *f)
{
	char *str = va_arg(list, char *);

	(void)f;

	if (!str)
		str = "(null";
	return (_puts(str));
}

/**
 * print_char - prints inputted character
 * @list: va_list passed from _printf
 * @f: pointer to flags struct
 * Return: total number of printed characters
 */

int print_char(va_list list, flags_t *f)
{
	(void)f;
	_putchar(va_arg(list, int));
	return (1);
}
