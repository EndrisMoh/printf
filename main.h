#ifndef MAIN_H
#define MAIN_H

/** includes **/
#include <stdarg.h>
#include <stdio.h>

/**
 * struct flags - structure with all the necessary flags
 * @plus: character +
 * @space: character ' '
 * @hash: character '#'
 */

typedef struct flags
{
	int hash;
	int space;
	int plus;
} flags_t;

/**
 * struct handler - struct for selecting right printing function
 * @c: format specifier
 * @f: pointer to the correct printing funciton
 */

typedef struct handler
{
	char c;
	int (*f)(va_list ap, flags_t *f);
} ph;


int _printf(const char *format, ...);

/********* stdout functions *******************/
int _putchar(char c);
int _puts(char *str);


/****** Selecting printing function*************/
int (*select_func(char s))(va_list, flags_t *);

/****** check for flags **********************/
int get_flag(char s, flags_t *f);



#endif
















