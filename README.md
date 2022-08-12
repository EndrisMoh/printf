# 0x11. C-Printf
''''''''''''''''

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
(space)	Prints a blank space if the argument is a positive number	i, d
#	Prints 0, 0x and 0X for o, x and X specifiers, respectively. It doesn't print anything if the argument is zero	o, x, X

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
Length:[39, 39]
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
