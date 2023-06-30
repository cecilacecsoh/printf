#include "main.h"
#include <stdio.h>

/**
 * print_int - Function prints integers
 *
 * @types: Lists of arguments
 * @buffer: Array handles prints
 * @flags: Calculates the active flags
 * @width: Width check
 * @precision: Precision specifications
 * @size: Size specifiers
 *
 * Return: Integer numbers
 */
int print_int(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	int is_negative = 0;
	long int n = va_arg(types, long int);
	unsigned long int num;

	n = convert_size_number(n, size);

	if (n == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)n;

	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		is_negative = 1;
	}

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}
	i++;
	return (write_number(is_negative, i, buffer, flags, width, precision, size));
}




/**
 * print_binary - Function prints an unsigned number
 *
 * @types: Lists of arguments
 * @buffer: Array handles prints
 * @flags: Calculates the active flags
 * @width: Width check
 * @precision: Precision specifications
 * @size: Size specifiers
 *
 * Return: an unsigned number
 */
int print_binary(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	unsigned int n, m, o, sum;
	unsigned int a[32];
	int count;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	n = va_arg(types, unsigned int);
	m = 2147483648; /* (2 ^ 31) */
	a[0] = n / m;
	for (o = 1; o < 32; o++)
	{
		m /= 2;
		a[o] = (n / m) % 2;
	}

	for (o = 0, sum = 0, count = 0; o < 32; o++)
	{
		sum += a[o];
		if (sum || o == 31)
		{
			char z = '0' + a[o];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}



/**
 * print_unsigned - Function prints an unsigned number
 *
 * @types: Lists of arguments
 * @buffer: Array handles prints
 * @flags: Calculates the active flags
 * @width: Width check
 * @precision: Precision specifications
 * @size: Size specifiers
 *
 * Return: an unsigned number
 */
int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_size_unsgnd(num, size);
	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}
	i++;
	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

