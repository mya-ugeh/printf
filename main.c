#include <stdio.h>
#include "main.h"

int main(void)
{
    int len;

 
    len = _printf("Character: %c\n", 'A');
    printf("Length:[%d]\n", len);

    len = _printf("String: %s\n", "Hello, World!");
    printf("Length:[%d]\n", len);

    
    len = _printf("Integer: %d\n", 12345);
    printf("Length:[%d]\n", len);

    len = _printf("Binary: %b\n", 255);
    printf("Length:[%d]\n", len);

    
    len = _printf("Character: %c\n", 'Z');
    printf("Length:[%d]\n", len);

    
    len = _printf("String: %s\n", "printf is fun!");
    printf("Length:[%d]\n", len);

    
    len = _printf("Integer: %d\n", -9876);
    printf("Length:[%d]\n", len);

    
    len = _printf("Binary: %b\n", 42);
    printf("Length:[%d]\n", len);

    return (0);
}
