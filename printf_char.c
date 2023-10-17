#include "main.h"

/**
 * printf_char - writes the character c to stdout
 * @c: the character to print
 * Return: 1
*/

int printf_char(va_list c)
{
	unsigned char my_char;

	my_char = va_arg(c, int);
	_putchar(my_char);
	return (1);
}

/**
 * print_percentage - writes the % symbol
 * Return: 1
*/
int print_percentage(void)
{
	_putchar('%');
	return (1);
}
