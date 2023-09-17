#include <stdarg.h>
#include <unistd.h>

/**
  * _printf - my custom printf
  * @format: fornatted string
  *
  * Return: always 0
  */

int _printf(const char *format, ...)
{
	int i = 0, j = 0;
	char c;
	char *str;
	va_list list;
	va_start(list, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 'c')
			{
				c = va_arg(list, int);
				write(1, &c, 1);
			}
			else if (format[i] == 's')
			{
				str = va_arg(list, char *);
				while (str[j])
				{
					write(1, &str[j], 1);
					j++;
				}
			}
			else if (format[i] == '%')
			{
				write(1, "%", 1);
			}
			else
			{
				break;
			}
		}
		else
		{
			write(1, &format[i], 1);
		}
		i++;
	}
	va_end(list);
	return (0);
}
