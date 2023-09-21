
#include "main.h"
#include <stdarg.h>
#include <stdio.h>
/**
 * _print_custom_string - prints only printable chars
 * list - vardiac list
 *
 * Return : lenght of the string
 */
int print_custom_string(va_list list)
{
	char *str = va_arg(list, char*);
	int len;

	len = 0;
	if (str == NULL)
		len += write(1, "(null)", 6);
	else
	{
		while (*str != '\0')
		{
			if (*str < 32 || *str >= 127)
				len += write(1, "0A", 2);
			else
				len += write(1, str, 1);
			str++;
		}
	}
	return (len);
}
