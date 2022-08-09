#include "main.h"

/**
 * main - entry point
 * Return: 0 success
 */

int main(void)
{
	int len, len2;

	len2 = printf("Let's try to print a simple sentence.\n");
	len = _printf("Let's try to printf a simple sentence.\n");
	printf("Length: [%d, %i]\n", len, len2);

	return (0);
}
