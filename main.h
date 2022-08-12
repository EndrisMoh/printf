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

/******** print numbers *********************/
int print_int(va_list list, flags_t *f);
void print_number(int num);
int print_unsigned(va_list list, flags_t *f);
int count_digit(int i);

/************ print percent *****************/
int print_percent(va_list list, flags_t *f);

/*********** print bases ******************/
int print_hex(va_list list, flags_t *f);
int print_octal(va_list list, flags_t *f);
int print_hex_big(va_list list, flags_t *f);
int print_binary(va_list list, flags_t *f);

/********** print custom *******************/
int print_bigS(va_list list, flags_t *f);
int print_rev(va_list list, flags_t *f);
int print_rot13(va_list list, flags_t *f);

/*********** print address *******************/
int print_address(va_list list, flags_t *f);

/*********** print alpha ***************/
int print_string(va_list list, flags_t *f);
int print_char(va_list list, flags_t *f);

/*********** convert *********************/
char *convert(unsigned long int num, int base, int lowercase);

/************* length modifiers ************/
int print_long_num(va_list list, flags_t *f);

#endif
