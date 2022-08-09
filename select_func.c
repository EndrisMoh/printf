#include "main.h"

/**
 * select_func - picks the right function for printing
 * based on the specifier
 * @s: conversion specifier
 * Return: a pointer to the matched function
 */

int (*select_func(char s))(va_list, flags_t *)
{
	ph func_arr[] = {
		{'s', print_string},
		{'c', print_char},
	};
	int flags = 14;

	register int i;

	for (i = 0; i < flags; i++)
		if (func_arr[i].c == s)
			return (func_arr[i].f);
	return (NULL);
}
