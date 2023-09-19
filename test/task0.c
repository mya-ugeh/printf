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
#include <limits.h>
/* Function prototype */
int _printf(const char *format, ...);
void print_integer(int n);
void print_binary(int num);
void print_octal(unsigned int num);
void print_hexa(unsigned int num, int flag);
void print_unsigned_integer(unsigned int);
/* MAIN */
int main() {
    unsigned int opp = (unsigned int)INT_MAX + 1024;
    _printf("Character:[%c]\n", 'H');
    _printf("String:[%s]\n", "I am a string !");
    _printf("Percent:[%%]\n");

    _printf("Integer value 59 == [%i] \n", 59);    
    _printf("Integer value with d -5== [%d] \n", -5);
    _printf("Integer value negative -9655 ==[%i] \n", -9655);
    _printf("Integer value zero == [%u] \n", 0);
    _printf("Binary value [%b] \n", 98);
    _printf("Octal  value of INT_MAX is [%o] \n", opp);
    _printf("Hex value of INT_MAX is [%X] \n", opp);
    _printf("Hex value of INT_MAX is [%x] \n", opp);

    return (0);
}

int _printf(const char *format, ...) {
    int i = 0;
    int int_val;
    unsigned unsigned_int_val;
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
                        
                        		break;
				}
                    	case 's':
				{ 
                        	    char* str = va_arg(list, char*);
                	            int j = 0;
        	                    while (str[j]){
	                                write(1, &str[j], 1);
                                	j++;
                            	}
			
				break;
				}
			case '%':
                    
                        	write(1, "%", 1);
                    		break;
			case 'd':
		    	
			case 'i':
				int_val = va_arg(list, int);
				print_integer(int_val);
				break;
			case 'b':
				int_val = va_arg(list, int);
				print_binary(int_val);
				break;
			case 'u':
				unsigned_int_val = va_arg(list, unsigned int);
				print_unsigned_integer(unsigned_int_val);
				break;
			case 'o':
				unsigned_int_val = va_arg(list,int);
				print_octal(unsigned_int_val);
				break;
			case 'x':
				unsigned_int_val = va_arg(list, int);
				print_hexa(unsigned_int_val, 0);
				break;
			case 'X':
				unsigned_int_val = va_arg(list,int);
				print_hexa(unsigned_int_val, 1);
				break;
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
	char zero;
	zero = 0;
	if (num == zero)
	{
		write(1, &zero, 1);
	}
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
	int digit = 0;
	while (len > 0) 
	{	
		int d = 1;
		int pow = len-1;
		while (pow-- >0 )
			d *= 10;
		digit = n / d;
		digit = digit + 48;
		write(1, &digit, 1);
		n %= d;
	   	len--;
	}
}

void print_binary(int num)
{
    int b[64];
    int i = 0;
    while (num > 0) {
        b[i] = (num % 2) + 48;
        num /= 2;
        i++;
    }
    for (int j = i - 1; j >= 0; j--) {
        write(1, &(b[j]), 1);
    }
}

void print_unsigned_integer(unsigned int n)
{
        unsigned int num = n;
        int len = 0;
        char zero;

        zero = 48;
        if (num == 0)
                write(1, &zero, 1);

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
void print_octal(unsigned int num)
{
	int oct[100];
	int i =0;

	while (num != 0)
	{
		oct[i]=(num % 8) + 48;
		num = num / 8;
		i++;
	}
	for (int x = i - 1; x >= 0; x--)
	{
	       write (1,&oct[x],1);
	}
}
void print_hexa(int unsigned num ,int flag)
{
    char hex[100];
    int unsigned i, remainder;

    i =0;
    while (num != 0) {
        remainder = num % 16;
        if (remainder < 10) 
            hex[i] = remainder + 48;
         
	else {
		if (flag)
            		hex[i] = remainder + 55;
		else
			hex[i] = remainder + 87;
        }
        i++;
        num /= 16;
    }
    for (int j = i - 1; j >= 0; j--) {
        write(1, &hex[j], 1);
    }
}



