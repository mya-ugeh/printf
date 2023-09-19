#include "main.h"
/**
  * _printf - my custom printf
  * @format: formatted string
  *
  * Return: always 0
  */

int _printf(const char *format, ...);

int _printf(const char *format, ...)
{
	int print_char = 0;
	char *str;
	char c;
	int index = 0;

	va_list args;

	if (format == NULL)
	{
		return (-1);
	}
	va_start(args, format);
	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			print_char++;
		}
		else
		{
			format++;
			if (*format == '\0')
				break;

			if (*format == '%')
			{
				write(1, format, 1);
				print_char++;
			}
			else if (*format == 'c')
			{
				c = va_arg(args, int);
				write(1, &c, 1);
				print_char++;
			}
			else if (*format == 's')
			{
				str = va_arg(args, char*);
				while (str[index] != '\0')
					index++;
				write(1, str, index);
				print_char += index;
			}
		}
		format++;
	}
	va_end(args);
	return (print_char);
}
