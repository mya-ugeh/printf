#include "main.h"

/**
  * print_chars - print a chararcter
  * @args: A va_list containing character to print
  * Return: number of chars to print
  */
int print_chars(va_list args)
{
	char c = va_arg(args, int);

	return (write(1, &c, 1));
}

/**
 * print_str - Print a string to stdout.
 * @args: A va_list containing the string to print.
 *
 * This function takes a va_list argument and prints the corresponding string
 * to the standard output (stdout).
 *
 * Return: The number of characters printed.
 */
int print_str(va_list args)
{
	char *str = va_arg(args, char*);
	int len = strlen(str);

	int print_char = write(1, str, len);

	return (print_char);
}

/**
 * format_string - Parse and print a format string.
 * @format: The format string to parse.
 * @args: A va_list containing the arguments for format specifiers.
 *
 * Return: The number of characters printed.
 */
int format_string(const char *format, va_list args)
{
	int print_char = 0;

	while (*format)
	{
		if (format == NULL)
			return (-1);
		if (*format == '%')
		{
			format++;
			if (*format == '\0')
				break;
			if (*format == 'c')
			{
				print_char += print_chars(args);
			}
			else if (*format == 's')
			{
				print_char += print_str(args);
			}
			else if (*format == '%')
				print_char += write(1, "%", 1);
			else if (*format == 'i' || *format == 'd')
				print_integer(args);
			else if (*format == 'b')
				print_binary(args);
			else if (*format == 'u')
				print_unsigned_integer(args);
			else if (*format == 'o')
				print_octal(args);
			else if (*format == 'x')
				print_hexa(args, 0);
			else if (*format == 'X') 
				print_hexa(args, 1);
			else
				break;
		}
		else
			print_char += write(1, format, 1);
		format++;
	}
	return (print_char);
}
