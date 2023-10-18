#include "main.h"

/**
 * printf_octal - prints an unsigned int argument converted to unsigned octal
 * @o: unsigned to be converted
 * Return: size of the output
*/
int printf_octal(va_list o)
{
	unsigned int len, powten, i, digit, n, num;
	int read = 0;

	n = va_arg(o, unsigned int);
	if (n != 0)
	{
		num = n;
		len = 0;
		while (num != 0)
		{
			num /= 8;
			len++;
		}
		powten = 1;
	for (i = 1; i <= len - 1; i++)
		powten *= 8;
	for (i = 1; i <= len; i++)
	{
		digit = n / powten;
		_putchar(digit + '0');
		read++;
		n -= digit * powten;
		powten /= 8;
	}
	}
	else
	{
		_putchar('0');
		return (1);
	}
	return (read);
}
