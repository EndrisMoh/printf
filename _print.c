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
	va_list list;
	int i;
	int *ptr;

	flag_f flags = {0, 0, 0};
	
	if (!format ||(format[0] == '%' && !format[1]))
		return (-1);

	if (format[0] == '%' && format[1] == ' ')
		return (-1);
	








	va_start(list, format);

	for (i = 0; format; i++)
	{
		if (flag->f1 != '%')
			print;
		else
		{
		_putchar(va_arg(list, format));
		}
	}

	va_end(list);



