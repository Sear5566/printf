#include "main.h"

/**
  * function_match - function that matches formats for _printf
  * & calls the corresponding function
  * @format: whatever format argument is in
  * Return: function matched or NULL
*/
int (*function_match(const char *format))(va_list)
{
	unsigned int i = 0;
	code_f find_f[] = {
		{"c", printf_char},
		{"s", printf_string},
		{"i", printf_int},
		{"d", printf_dec},
		{"b", printf_bin},
		/**
		{"r", printf_rev},
		{"u", printf_unsig},
		{"o", printf_octal},
		{"x", printf_x},
		{"X", printf_X},
		{"R", printf_rot13},*/
		{NULL, NULL}
	};

	while (find_f[i].sc)
	{
		if (find_f[i].sc[0] == (*format))
			return (find_f[i].f);
		i++;
	}
	return (NULL);
}

/**
   * _printf - a function that displays output to stdout
   * @format: a type of character string pointer
   * Return: the number of characters printed
*/
int _printf(const char *format, ...)
{
	va_list ap;
	int (*f)(va_list);
	unsigned int i = 0, count = 0;

	if (format == NULL)
		return (-1);
	va_start(ap, format);
	while (format[i])
	{
		while (format[i] != '%' && format[i])
		{
			_putchar(format[i]);
			count++;
			i++;
		}
		if (format[i] == '\0')
			return (count);
		f = function_match(&format[i + 1]);
		if (f != NULL)
		{
			count += f(ap);
			i += 2;
			continue;
		}
		if (!format[i + 1])
			return (-1);
		_putchar(format[i]);
		count++;
		if (format[i + 1] == '%')
			i += 2;
		else
			i++;
	}
	va_end(ap);
	return (count);
}
