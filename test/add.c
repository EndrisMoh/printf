#include <stdio.h>
#include "test.h"

/**
 * add - test the makefile by adding two numbers
 * @a: the first number
 * @b: the second number
 * Return: results
 */

int add(int a, int b)
{
	int res;
	res = a + b;

	printf("result = %d\n", res);

	return res;
}
