#include "main.h"
#include <stdio.h>

/**
 * prints_octal - prints an unsigned number in octal notation
 *
 * @types: Lists of arguments
 * @buffer: Array handles prints
 * @flags: Calculates the active flags
 * @width: Width check
 * @precision: Precision specifications
 * @size: Size specifiers
 *
 * Return: characters
 */
int prints_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);
	num = converts_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	while (num > 0)
	{
		buffer[i--] = (num % 8) + '0';
		num /= 8;
	}
	if (flags & F_HASH && init_num != 0)
		buffer[i--] = '0';

	i++;
	return (writes_unsgnd(0, i, buffer, flags, width, precision, size));
}




/**
 * prints_hexadecimal - prints unsigned number in hexadecimal notation.
 *
 * @types: Lists of arguments
 * @buffer: Array handles prints
 * @flags: Calculates the active flags
 * @width: Width check
 * @precision: Precision specifications
 * @size: Size specifiers
 *
 * Return: characters
 */
int prints_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}


/**
 * prints_hexa_upper - prints unsigned number in hexadecimal notation.
 *
 * @types: Lists of arguments
 * @buffer: Array handles prints
 * @flags: Calculates the active flags
 * @width: Width check
 * @precision: Precision specifications
 * @size: Size specifiers
 *
 * Return: characters
 */
int prints_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}




/**
 * prints_hexa - prints hexadecimal number in lower or upper
 *
 * @types: Lists of arguments
 * @flag_ch: Calculates active flags
 * @buffer: Array handles prints
 * @map_to: Array of values to map the number to.
 * @flags: Calculates the active flags
 * @width: Width check
 * @precision: Precision specifications
 * @size: Size specifiers
 *
 * Return: characters
 */
int prints_hexa(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);
	num = converts_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}
	i++;
	return (writes_unsgnd(0, i, buffer, flags, width, precision, size));
}

