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

#endif
