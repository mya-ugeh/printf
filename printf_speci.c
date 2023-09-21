#include "main.h"

/**
 * print_unsigned - Print an unsigned integer.
 * @args: unsigned integer to be printed
 *
 * Return: The number of characters printed.
 */
int print_unsigned(va_list args)
{
    unsigned int num = va_arg(args, unsigned int);
    char buffer[12];
    int print_char = 0;

    snprintf(buffer, sizeof(buffer), "%u", num);
    print_char = write(1, buffer, strlen(buffer));
    return (print_char);
}

/**
 * print_octal - Print an unsigned integer in octal format.
 * @args: unsigned integer to printed "o"
 *
 * Return: The number of characters printed.
 */
int print_octal(va_list args)
{
    unsigned int num = va_arg(args, unsigned int);
    char buffer[12];
    int print_char = 0;

    snprintf(buffer, sizeof(buffer), "%o", num);
    print_char = write(1, buffer, strlen(buffer));
    return (print_char);
}

/**
 * print_lower_hex - Print an unsigned integer in lowercase hexadecimal format.
 * @args: unsigned integer to printed "x"
 *
 * Return: The number of characters printed.
 */
int print_lower_hex(va_list args)
{
    unsigned int num = va_arg(args, unsigned int);
    char buffer[12];
    int (print_char) = 0;

    snprintf(buffer, sizeof(buffer), "%x", num);
    print_char = write(1, buffer, strlen(buffer));
    return (print_char);
}

/**
 * print_upper_hex - Print an unsigned integer in uppercase hexadecimal format.
 * @args: unsigned integer to print.
 *
 * Return: The number of characters printed.
 */
int print_upper_hex(va_list args)
{
    unsigned int num = va_arg(args, unsigned int);
    char buffer[12];
    int (print_char) = 0;

    snprintf(buffer, sizeof(buffer), "%X", num);
    print_char = write(1, buffer, strlen(buffer));
    return (print_char);
}
