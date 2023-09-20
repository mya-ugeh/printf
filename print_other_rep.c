#include "main.h"

/**
 * print_binary - prints a binary to std
 * @list: vardiac list
 * 
 * Return: nothing
*/
void print_binary(va_list list)
{
    int b[64];
    int i, num;

    num = va_arg(list, unsigned int);
    i = 0;
    while (num > 0)
    {
        b[i] = (num % 2) + 48;
        num /= 2;
        i++;
        }
    for (int j = i - 1; j >= 0; j--) {
        write(1, &(b[j]), 1);
    }
}


/**
 * print_octal - prints octal representaion of a value to std
 * @list: vardiac list
 * 
 * Return: nothing
*/
void print_octal(va_list list)
{
        int oct[100];
        int i = 0;
        unsigned int num;
        
        num = va_arg(list, unsigned int);
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



/**
 * print_hexa - prints a hex representation to std
 * @list: vardiac list
 * 
 * Return: nothing
*/
void print_hexa(va_list list ,int flag)
{
    char hex[100];
    int unsigned i, remainder, num;

    num = va_arg(list, unsigned int);
    i = 0;
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
