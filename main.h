#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stddef.h>

int _printf(const char *format, ...);
void print_unsigned_integer(unsigned int n);
void print_integer(int n);
void print_binary(int num);
void print_octal(unsigned int num);
void print_hexa(int unsigned num ,int flag);

#endif
