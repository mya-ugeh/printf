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
	char *str;
	char c;
	va_list list;

	va_start(list, format);
	if (format)
	{
		while (format[i])
		{
			if (format[i] == '%')
			{
				switch (format[i])
				{
					case 'c':
						c = va_arg(list, int);
						write(1, &c, 1);
						break;
					case 's':
						*str = va_arg(list, char*);
						while (str[j])
						{
							write(1, &str[j], 1);
							j++;
						}
						break;
					case '%':
						write(1, "%", 1);
					default:
						break;
				}
			}
			else
				write(1, &format[i], i);
			i++;
		}
	}
	va_end(list);
	return (0);
}
