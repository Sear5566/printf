#include "main.h"

/**
   * _printf - a function that displays output to stdout
   * @format: a type of character string pointer.
   * Return: the number of characters printed
*/
int _printf(const char *format, ...)
{
	int i, j;
	va_list args;
	int count = 0;

	if (format == NULL)
		return (-1);
	va_start(args, format);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++;

			if (format[i] == 'c')
			{
				char c = va_arg(args, int);

				_putchar(c);
				count++;
			}
			else if (format[i] == 's')
			{
				char *s = va_arg(args, char*);

				for (j = 0; s[j] != '\0'; j++)
				{
					_putchar(s[j]);
					count++;
				}
			}
			else if (format[i] == '%')
			{
				_putchar('%');
				count++;
			}
		}
		else
		{
			_putchar(format[i]);
			count++;
		}
	}
	va_end(args);
	return (count);
}
