#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

int _printf(const char *format, ...);
int format_string(const char *format, va_list args);
int print_integer(va_list list);
void print_binary(va_list list);
void print_unsigned_integer(va_list list);
void print_octal(va_list list);
void print_hexa(va_list list ,int flag);

#endif
