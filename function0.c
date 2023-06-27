#include <stdio.h>
#include "main.h"

/**
 * print_chrStrPct - writes the character c to stdout
 *
 * @format: is a character string
 * @args: input arguments
 * @*s: string pointer
 * @c: specifyer
 * @count: return value
 *
 * Returns: the number of characters printed
 * (excluding the null byte used to end output to strings)
 *
 */
int print_chrStrPct(const char *format, ...)
{
	int count = 0;
	va_list args;
	va_start(args, format);

	char *s = va_arg(args, char *);
	char c = va_arg(args, int);

	while (*format)
	{
	if (*format == '%')
	{
		format++;
		if (*format == '%')
		{
			putchar('%');
			count++;
		}
		else if (*format == 'c')
		{
			putchar(c);
			count++;
		}
		else if (*format == 's')
		{
			while (*s)
			{
				putchar(*s);
				s++;
				count++;
			}
		}
	}
	else
	{
		putchar(*format);
		count++;
	}
		format++;
	}

	va_end(args);
	return (count);
}
