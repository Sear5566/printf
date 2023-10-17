#include "main.h"
/**
 * printf_int - a function that prints an integer
 * @i: integer to print
 * Return: size of the output text
*/
int printf_int(va_list i)
{
	int len, powten, j, digit, n, count = 0, num;

	n = va_arg(i, int);
	if (n != 0)
	{
		if (n < 0)
		{
			_putchar('-');
			count++;
		}
		num = n;
		len = 0;
		while (num != 0)
		{
			num /= 10;
			len++;
		}
		powten = 1;
		for (j = 1; j <= len - 1; j++)
			powten *= 10;
		for (j = 1; j <= len; j++)
		{
			digit = n / powten;
			if (n < 0)
				_putchar((digit * -1) + 48);
			else
				_putchar(digit + '0');
			count++;
			n -= digit * powten;
			powten /= 10;
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
#include "holberton.h"
#include <stdlib.h>
#include <stdio.h>


 * main_int - prints integer

{
                putchar('-');
                num = -num;
                p = -p;
                last = -last;
                j++;
        }
        if (num > 0)
        {
                while (num / 10 != 0)
                {
                        exp = exp * 10;
                        num = num / 10;
                }
                num = p;
                while (exp > 0)
                {
                        digit = num / exp;
                        putchar(digit + '0');
                        num = num - (digit * exp);
                        exp = exp / 10;
                        j++;
                }
        }
        putchar(last + '0');
        return (j);
}*/
