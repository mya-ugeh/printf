#include "main.h"
int main() {
    _printf("Character:[%c]\n", 'H');
    _printf("String:[%s]\n", "I am a string !");
    _printf("Percent:[%%]\n");
    _printf("My name is Mya\n");
    _printf("My name is %s, my first letter is %c, I have 100%%\n", "Mya", 'M');
    _printf("Wrong char: %s\n", 28);

    _printf("Only %%s %%c %%%%%%\n");
    _printf("Another %s test: [%s]\n", "string", "Hello, World!");
    _printf("Character as %%c: [%c]\n", 'X');

    return (0);
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
}
