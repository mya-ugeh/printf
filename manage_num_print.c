#include "main.h"

void print_integer(int n)
{
	int num = n;
	int len = 0;
	char zero;
	zero = 0;
	if (num == zero)
	{
		write(1, &zero, 1);
	}
	if (num < 0)
	{
			char a ='-';
			write(1, &a, 1);
			num = -num;
			n = -n;
	}
	while (num > 0)
	{
		num =num / 10;
		len++;
	}
	int digit = 0;
	while (len > 0)
	{
		int d = 1;
		int pow = len-1;
		while (pow-- >0 )
			d *= 10;
		digit = n / d;
		digit = digit + 48;	
		write(1, &digit, 1);
		n %= d;
		len--;
	}
}


void print_unsigned_integer(unsigned int n)
{
	unsigned int num = n;
	int len = 0;
	char zero;
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

		int d = 1;
		int pow = len-1;
		while (pow-- >0 )
			d *= 10;
		int digit = n / d;
		digit = digit + 48;
		write(1, &digit, 1);
		n %= d;
		len--;
	}
}

