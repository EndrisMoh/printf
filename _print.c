#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * _printf - prints to std output according to
 * format.
 * @format: the format specifier
 * Return: number of characters printed
 */

int _printf(const char *format, ...)
{
	va_list vaList;
	const char *ptr;
	int (*pfunc)(va_list, flags_t *);
	flags_t flags = {0, 0, 0};

	register int count = 0;

	va_start(vaList, format);


	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (ptr = format; *ptr; ptr++)
	{
		if (*ptr == '%')
		{
			ptr++;
			if (*ptr == '%')
			{
				count += _putchar('%');
				continue;
			}
			while (get_flag(*ptr, &flags))
				ptr++;
			pfunc = select_func(*ptr);
			count += (pfunc)
				? pfunc(vaList, &flags)
				: _printf("%%%c", *ptr);
		}
		else
			count += _putchar(*ptr);
	}
	_putchar(-1);
	va_end(vaList);
	return (count);
}
