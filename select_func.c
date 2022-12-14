#include "main.h"
#include <stdarg.h>

/**
 * select_func - picks the right function for printing
 * based on the specifier
 * @s: conversion specifier
 * Return: a pointer to the matched function
 */
int (*select_func(char s))(va_list, flags_t *)
{
	ph func_arr[] = {
		{'i', print_int},
		{'s', print_string},
		{'c', print_char},
		{'d', print_int},
		{'u', print_unsigned},
		{'x', print_hex},
		{'X', print_hex_big},
		{'b', print_binary},
		{'o', print_octal},
		{'R', print_rot13},
		{'R', print_rev},
		{'S', print_bigS},
		{'p', print_address},
		{'%', print_percent}
		/*{'l', print_long_num}*/
		};
	int flags = 14;

	register int i;

	for (i = 0; i < flags; i++)
		if (func_arr[i].c == s)
			return (func_arr[i].f);
	return (NULL);
}
