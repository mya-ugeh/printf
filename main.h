#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

int _printf(const char *format, ...);
int format_string(const char *format, va_list args);
int print_chars(va_list args);
int print_str(va_list args);
int print_int(va_list args);
int print_binary(va_list args);
int print_unsigned(va_list args);
int print_octal(va_list args);
int print_lower_hex(va_list args);
int print_upper_hex(va_list args);
int print_custom_string(va_list args);
int print_flags(va_list list);
int check_flags(va_list list);
#endif
