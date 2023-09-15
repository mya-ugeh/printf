/*
Write a function that produces output according to a format.

Prototype: int _printf(const char *format, ...);
Returns: the number of characters printed (excluding the null byte used to end output to strings)
write output to stdout, the standard output stream
format is a character string. The format string is composed of zero or more directives. See man 3 printf for more detail. You need to handle the following conversion specifiers:
c
s
%
You don’t have to reproduce the buffer handling of the C library printf function
You don’t have to handle the flag characters
You don’t have to handle field width
You don’t have to handle precision
You don’t have to handle the length modifiers
*/


#include <stdarg.h>
#include <unistd.h>

// Function prototype
int _printf(const char *format, ...);

// MAIN
int main() {
    _printf("Character:[%c]\n", 'H');
    _printf("String:[%s]\n", "I am a string !");
    _printf("Percent:[%%]\n");
    return (0);
}

int _printf(const char *format, ...) {
    int i = 0;
    va_list list;
    va_start(list, format);

    if (*format) {
        while (format[i]) {
            if (format[i] == '%') {
                i++;
                switch (format[i]) {
                    case 'c':
                        {
                            char c = va_arg(list, int);
                            write(1, &c, 1);
                        } 
                        break;
                    case 's':
                        {
                            char* str = va_arg(list, char*);
                            int j = 0;
                            while (str[j]){
                                write(1, &str[j], 1);
                                j++;
                            }
                        }
                        break;
                    case '%':
                    {
                        write(1, "%", 1);
                    break;
                    }
                    default:
                        break;
                }
            }
            else {
                write(1, &format[i], 1);
            }
            i++;
        }
    }
    va_end(list);
    return 0;
}
