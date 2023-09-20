#include "main.h"

/**
 * print_unsigned - Print an unsigned integer.
 * @args: A va_list containing the unsigned integer to print.
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
 * @args: A va_list containing the unsigned integer to print.
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
 * print_hex - Print an unsigned integer in lowercase hexadecimal format.
 * @args: A va_list containing the unsigned integer to print.
 *
 * Return: The number of characters printed.
 */
int print_hex(va_list args)
{
    unsigned int num = va_arg(args, unsigned int);
    char buffer[12];
    int (print_char) = 0;

    snprintf(buffer, sizeof(buffer), "%x", num);
    print_char = write(1, buffer, strlen(buffer));
    return (print_char);
}

/**
 * print_hex_upper - Print an unsigned integer in uppercase hexadecimal format.
 * @args: A va_list containing the unsigned integer to print.
 *
 * Return: The number of characters printed.
 */
int print_hex_upper(va_list args)
{
    unsigned int num = va_arg(args, unsigned int);
    char buffer[12];
    int (print_char) = 0;

    snprintf(buffer, sizeof(buffer), "%X", num);
    print_char = write(1, buffer, strlen(buffer));
    return (print_char);
}
