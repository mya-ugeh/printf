#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <limits.h>

/**
 * print_integer - prints integers to output
 * @list: varidaic list to be assesed
 * 
 * Return: returns nothing
*/


void print_integer(va_list list)
{
	int num,int_val;
	int len, digit, pow, d;
	char zero;
	
	zero = 0;
	len = 0;

	int_val = va_arg(list, int);
	num = int_val;
	if (num == zero)
	{
		write(1, &zero, 1);
	}
	if (num < 0)
	{
		char a = '-';
		write(1, &a, 1);
		num = -num;
		int_val = -int_val;
	
	}
	while (num > 0)
	{
		num = num / 10;
		len++;
	}
	digit = 0;
	while (len > 0)
	{
		d = 1;
		pow = len - 1;
		while (pow-- > 0 )
			    d *= 10;
		digit = int_val / d;
		digit = digit + 48;
		write(1, &digit, 1);
		int_val %= d;
		len--;
	}
}

/**
 * print_unsigned_int - prints postive integers
 * @list: list in variadic function
 * 
 * Returns : nothing
*/

void print_unsigned_integer(va_list list)
{
	unsigned int num, n, digit;
	int len, d, pow ;
	char zero;
	
	len = 0;
	n = va_arg(list, unsigned int);
	num = n;
	zero = 48;
	if (num == 0)
		write(1, &zero, 1);
	while (num > 0)
	{
		num =num / 10;
		len++;

	}

	while (len > 0)
	{
		d = 1;
		pow = len - 1;
		while (pow-- > 0 )
			d *= 10;
		digit = n / d;
		digit = digit + 48;
		write(1, &digit, 1);
		n %= d;
		len--;
	}
}
