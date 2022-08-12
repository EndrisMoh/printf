# 0x11. C-Printf


The printf project is a collaboration between Endris Mohammed and Jared Keago, actual students of Software Engineering at ALX School, were a function named "_printf" imitates the actual "printf" command located in the stdio.h library. It contains some of the basic features and functions found in the manual 3 of "printf".

_printf() is a function that performs formatted output conversion and print data. Its prototype is the following:

int _printf(const char *format, ...)

Where format contains the string that is printed. As _printf() is variadic function, it can receives n arguments that replace by n tags written inside the string.

The format tags prototype is the following:

%[flags][length]specifier

If the program runs successfully, the return value is the amount of chars printed.

Specifier	Output

c	Character
d or i	Signed decimal integer
s	String of characters
b	Signed binary
o	Signed octal
u	Unsigned integer
x	Unsigned hexadecimal
X	Unsigned hexadecimal (uppercase)
p	Pointer address
r	Reverse string of characters
R	ROT13 translation of string
S	String with special chars replaced by their ASCII value
%	Character

Flags	Description	Specifiers

+	Prints a plus sign (+) when the argument is a positive number. In other case, prints a minus sign (-).	i, d

(space)		Prints a blank space if the argument is a positive number	i, d

(#) Prints 0, 0x and 0X for o, x and X specifiers, respectively. It doesn't print anything if the argument is zero o, x, X


Length	Description	Specifiers

l	Prints a long int or unsigned long int	i, d, o, u, x and X
h	Prints a short int or unsigned short int	i, d, o, u, x and X

Examples

Printing the string of chars "Hello, ALX":

Use: _printf("Hello  AL%s.", "X");

Output: Hello ALX.

Printing an integer number:

Use: _printf("10 + 10 is equal to %d.", 20);

Output: 10 + 10 is equal to 20.

Printing a binary, octal and hexadecimal:

Use: _printf("10 in binary is [%b], in octal is [%o] and in hexadecimal is [%x]", 5, 5, 5);

Output: 10 in binary is [1010], in octal is [12] and in hexadecimal is [A]

Printing a string codified in ROT13:


Use: _printf("Hello in ROT13 is %R", "Hello");

Output: Hello in ROT13 is Urybb

Using flags and length tags:

Printing the string of chars "Hello, ALX":

Use: _printf("2 * 2 = %+d and 5 * -5 = %+i", 4, -25);

Output: 2 * 2 = +4 and 5 * -5 = -25

Printing a long integer number and short integer number:

Use: _printf("1 million as a long int is %ld, but as a short int is %hd", 1000000, 1000000);

Output: 1 million as a long int is 1000000, but as a short int is 16960

File Functions

_printf.c

Own printf  function that performs formated output conversion and print data.


  main.h

Header file where all prototypes are saved.


  Compilation & Testing


This code will be compiled this way:

$ gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c

You might want to look at the gcc flag -Wno-format when testing with your _printf and the standard printf. Example of test file that you could use:
<
user@ubuntu:~/c/printf$ cat main.c 

#include <limits.h>
#include <stdio.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    int len;
    int len2;
    unsigned int ui;
    void *addr;

    len = _printf("Let's try to printf a simple sentence.\n");
    len2 = printf("Let's try to printf a simple sentence.\n");
    ui = (unsigned int)INT_MAX + 1024;
    addr = (void *)0x7ffe637541f0;
    _printf("Length:[%d, %i]\n", len, len);
    printf("Length:[%d, %i]\n", len2, len2);
    _printf("Negative:[%d]\n", -762534);
    printf("Negative:[%d]\n", -762534);
    _printf("Unsigned:[%u]\n", ui);
    printf("Unsigned:[%u]\n", ui);
    _printf("Unsigned octal:[%o]\n", ui);
    printf("Unsigned octal:[%o]\n", ui);
    _printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    _printf("Character:[%c]\n", 'H');
    printf("Character:[%c]\n", 'H');
    _printf("String:[%s]\n", "I am a string !");
    printf("String:[%s]\n", "I am a string !");
    _printf("Address:[%p]\n", addr);
    printf("Address:[%p]\n", addr);
    len = _printf("Percent:[%%]\n");
    len2 = printf("Percent:[%%]\n");
    _printf("Len:[%d]\n", len);
    printf("Len:[%d]\n", len2);
    _printf("Unknown:[%r]\n");
    printf("Unknown:[%r]\n");
    return (0);
}

user@ubuntu:~/c/printf$ gcc -Wall -Wextra -Werror -pedantic -std=gnu89 -Wno-format *.c
user@ubuntu:~/c/printf$ ./printf
Let's try to printf a simple sentence.
Let's try to printf a simple sentence.
ength:[39, 39]
Length:[39, 39]
Negative:[-762534]
Negative:[-762534]
Unsigned:[2147484671]
Unsigned:[2147484671]
Unsigned octal:[20000001777]
Unsigned octal:[20000001777]
Unsigned hexadecimal:[800003ff, 800003FF]
Unsigned hexadecimal:[800003ff, 800003FF]
Character:[H]
Character:[H]
String:[I am a string !]
String:[I am a string !]
Address:[0x7ffe637541f0]
Address:[0x7ffe637541f0]
Percent:[%]
Percent:[%]
Len:[12]
Len:[12]
Unknown:[%r]
Unknown:[%r]
user@ubuntu:~/c/printf$
>

The format specifier can also contain sub-specifiers: flags, width, .precision and modifiers (in that order), which are optional and follow these specifications:



flags	description

-	Left-justify within the given field width; Right justification is the default (see width sub-specifier).

+	Forces to preceed the result with a plus or minus sign (+ or -) even for positive numbers. By default, only negative numbers are preceded with a - sign.

(space)	If no sign is going to be written, a blank space is inserted before the value.

#	Used with o, x or X specifiers the value is preceeded with 0, 0x or 0X respectively for values different than zero.

Used with a, A, e, E, f, F, g or G it forces the written output to contain a decimal point even if no more digits follow. By default, if no digits follow, no decimal point is written.

0	Left-pads the number with zeroes (0) instead of spaces when padding is specified (see width sub-specifier).



width	description

(number)	Minimum number of characters to be printed. If the value to be printed is shorter than this number, the result is padded with blank spaces. The value is not truncated even if the result is larger.

*	The width is not specified in the format string, but as an additional integer value argument preceding the argument that has to be formatted.



.precision	description

.number	For integer specifiers (d, i, o, u, x, X): precision specifies the minimum number of digits to be written. If the value to be written is shorter than this number, the result is padded with leading zeros. The value is not truncated even if the result is longer. A precision of 0 means that no character is written for the value 0.

For a, A, e, E, f and F specifiers: this is the number of digits to be printed after the decimal point (by default, this is 6).

For g and G specifiers: This is the maximum number of significant digits to be printed.

For s: this is the maximum number of characters to be printed. By default all characters are printed until the ending null character is encountered.

If the period is specified without an explicit value for precision, 0 is assumed.

.*	The precision is not specified in the format string, but as an additional integer value argument preceding the argument that has to be formatted.



The length sub-specifier modifies the length of the data type. This is a chart showing the types used to interpret the corresponding arguments with and without length specifier (if a different type is used, the proper type promotion or conversion is performed, if allowed):

specifiers

length	d i	u o x X	f F e E g G a A	c	s	p	n

(none)	int	unsigned int	double	int	char*	void*	int*

hh	signed char	unsigned char					signed char*

h	short int	unsigned short int					short int*

l	long int	unsigned long int		wint_t	wchar_t*		long int*

ll	long long int	unsigned long long int					long long int*

j	intmax_t	uintmax_t					intmax_t*

z	size_t	size_t					size_t*

t	ptrdiff_t	ptrdiff_t					ptrdiff_t*

L			long double				

Note regarding the c specifier: it takes an int (or wint_t) as argument, but performs the proper conversion to a char value (or a wchar_t) before formatting it for output.

Authors

Endris Mohammed @EndrisMoh
and
Jared Keago @jaredatandi
//
