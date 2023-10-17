#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stddef.h>


int _putchar(char c);
int _printf(const char *format, ...);
int printf_char(va_list c);
int printf_string(va_list s);
int printf_int(va_list i);
int printf_dec(va_list d);
/**
int printf_rev(va_list r);
int printf_bin(va_list b);
int printf_unsig(va_list u);
int printf_octal(va_list o);
int printf_x(va_list x);
int printf_X(va_list X);
int printf_rot13(va_list R);*/
/**
 * struct code_format - structure format
 *
 * @sc: the format specifiers
 * @f: function match
*/
typedef struct code_format
{
	char *sc;
	int (*f)(va_list);
} code_f;


#endif
