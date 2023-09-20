#include "main.h"
/**
  * _printf - custom printf function
  * @format: formatted string
  * Return: char
  */
int _printf(const char *format, ...)
{
	int print_char = 0;
	va_list args;

	va_start(args, format);
	print_char = format_string(format, args);
	va_end(args);

	return (print_char);
}
