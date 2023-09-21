#include "main.h"

/**
  * print_chars - print a chararcter
  * @args:  character to print
  * Return: chars to print
  */
int print_chars(va_list args)
{
	char c = va_arg(args, int);

	return (write(1, &c, 1));
}

/**
 * print_str - Print a string to stdout.
 * @args: string to print.
 *
 * This function takes a va_list argument and prints the  string
 * to the standard output
 *
 * Return: characters printed.
 */
int print_str(va_list args)
{
	char *str = va_arg(args, char*);
	int len = 0;

	if (str == NULL)
	{
		len += write(1, "(null)", 6);
	}
	else
		len += write(1, str, strlen(str));
	return (len);
}

/**
  * print_int - prints an integer
  * @args: integers to be printed
  * Return: The numbers
  */
int print_int(va_list args)
{
	int num = va_arg(args, int);
	char buffer[12];
	int print_char = 0;

	snprintf(buffer, sizeof(buffer), "%d", num);
	print_char = write(1, buffer, strlen(buffer));
	return (print_char);
}

/**
 * print_binary - Print an unsigned integer in a binary format.
 * @args: unsigned integer to be  printed
 *
 * Return: characters printed.
 */
int print_binary(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	int print_char = 0;

	if (num == 0)
	{
		print_char += write(1, "0", 1);
	}
	else
	{
		int bit = 0;
		unsigned int j = 1;

		while (j < num)
		{
			j <<= 1;
			bit++;
		}
		while (bit >= 0)
		{
			char bits = ((num >> bit) & 1) + '0';
			print_char += write(1, &bits, 1);
			bit--;
		}
	}
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
		if (*format == '%')
		{
			format++;
			if (*format == '\0')
				break;
			if (*format == 'c')
				print_char += print_chars(args);
			else if (*format == 's')
				print_char += print_str(args);
			else if (*format == '%')
				print_char += write(1, "%", 1);
			else if (*format == 'd' || *format == 'i')
				print_char += print_int(args);
			else if (*format == 'b')
				print_char += print_binary(args);
			else if (*format == 'u')
				print_char += print_unsigned(args);
			else if (*format == 'o')
				print_char += print_octal(args);
			else if (*format == 'x')
				print_char += print_hex(args);
			else if (*format == 'X')
				print_char += print_hex_upper(args);
			else
			{
				print_char += write(1, "%", 1);
				print_char += write(1, format, 1);
			}
		}
		else
			print_char += write(1, format, 1);
		format++;
	}
	return (print_char);
}
