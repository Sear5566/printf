
#include "main.h"
/**
 * printf_unsig - a function that prints unsigned number
 * @u: unsigned number
 * Return: size the output
*/
int printf_unsig(va_list u)
{
	unsigned int len, powten, i, digit, n, num;
	int read = 0;

	n = va_arg(u, unsigned int);
	if (n != 0)
	{
		num = n;
		len = 0;
		while (num != 0)
		{
			num /= 10;
			len++;
		}
		powten = 1;
		for (i = 1; i <= len - 1; i++)
			powten *= 10;
		for (i = 1; i <= len; i++)
		{
			digit = n / powten;
			_putchar(digit + '0');
			read++;
			n -= digit * powten;
			powten /= 10;
		}
	}
	else
	{
		_putchar('0');
		return (1);
	}
	return (read);
}
