#include "main.h"
/**
 * printf_hex - function that prints an unsigned int in hexadecimal
 * @n: unsigned to be printed
 * @c: case of printing (0 = lower, 1 = upper)
 * Return: size the output
*/
int printf_hex(unsigned int n, unsigned int c)
{
	unsigned int len, powten, j, digit, num;
	int count = 0;
	char diff;

	if (n != 0)
	{
		num = n;
		len = 0;
		if (c)
			diff = 'A' - ':';
		else
			diff = 'a' - ':';
		while (num != 0)
		{
			num /= 16;
			len++;
		}
		powten = 1;
		for (j = 1; j <= len - 1; j++)
			powten *= 16;
		for (j = 1; j <= len; j++)
		{
			digit = n / powten;
			if (digit < 10)
				_putchar(digit + '0');
			else
				_putchar(digit + '0' + diff);
			count++;
			n -= digit * powten;
			powten /= 16;
		}
	}
	else
	{
		_putchar('0');
		return (1);
	}
	return (count);
}
/**
 * printf_x - takes an unsigned int an prints it in lowercase hex
 * @x: unsigned int to print
 * Return: size of the output
*/
int printf_x(va_list x)
{
	return (printf_hex(va_arg(x, unsigned int), 0));
}
/**
 * printf_X - takes an unsigned int an prints it in uppercase hex
 * @X: unsigned int to print
 * Return: size of the output
*/
int printf_X(va_list X)
{
	return (printf_hex(va_arg(X, unsigned int), 1));
}
