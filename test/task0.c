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
#include <stdio.h>
/* Function prototype */
int _printf(const char *format, ...);
void print_integer(int n);


/* MAIN */
int main() {
    _printf("Character:[%c]\n", 'H');
    _printf("String:[%s]\n", "I am a string !");
    _printf("Percent:[%%]\n");

    _printf("Integer value [%i] \n", 59);    
    _printf("Integer value with d [%d] \n", -5);
    _printf("Integer value negative [%i] \n", -9655);
    _printf("Integer value zero [%d] \n", 0);
    return (0);
}

int _printf(const char *format, ...) {
    int i = 0;
    int int_val;
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
		    case 'd':
		    	
		    	int_val = va_arg(list, int);
			print_integer(int_val);
			break;
		    case 'i':
			int_val = va_arg(list, int);
			print_integer(int_val);
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


void print_integer(int n)
{
	int num = n;
	int len = 0;
	int flag =0;
	char zero;

	zero = 48;
	if (num == 0)
		write(1, &zero, 1);
	if (num < 0)
	{
		char a ='-';
		write(1, &a, 1);
		num = -num;
		n = -n;
	}
	
	while (num > 0) 
	{
		num =num / 10;
		len++;
	}

	while (len > 0) 
	{	

		int d = 1;
		int pow = len-1;
		while (pow-- >0 )
			d *= 10;
		int digit = n / d;
	  	digit = digit + 48;
	  	write(1, &digit, 1);
	  	n %= d;
	   	len--;
	}
}
