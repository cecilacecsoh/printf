#include <stdio.h>
#include "main.h"

/**
 * handles_write_char - prints a string of char
 *
 * @c: character type
 * @buffer: Buffer array to  handle prints.
 * @flags: gets active flags.
 * @width: gets the width
 * @precision: the precision specifier
 * @size: the size specifier
 *
 * Return: print char
 */
int handles_write_char(char c, char buffer[],
	int flags, int width, int precision, int size)
{ /* the char is stored at left,paddind at buffer's right */
	int i = 0;
	char padd = ' ';

	UNUSED(precision);
	UNUSED(size);

	if (flags & F_ZERO)
		padd = '0';

	buffer[i++] = c;
	buffer[i] = '\0';

	if (width > 1)
	{
		buffer[BUFF_SIZE - 1] = '\0';
		for (i = 0; i < width - 1; i++)
			buffer[BUFF_SIZE - i - 2] = padd;

		if (flags & F_MINUS)
			return (write(1, &buffer[0], 1) +
				write(1, &buffer[BUFF_SIZE - i - 1], width - 1));
		else
			return (write(1, &buffer[BUFF_SIZE - i - 1], width - 1) +
				write(1, &buffer[0], 1));
	}
	return (write(1, &buffer[0], 1));
}




/**
 * writes_number - the function prints string.
 *
 * @is_negative: the list of arguments
 * @ind: char types
 * @buffer: Array to handle print
 * @flags:  gets the active flags
 * @width: the get width
 * @precision: the precision specifier
 * @size: the size specifier
 *
 * Return: the number of chars printed.
 */
int writes_number(int is_negative, int ind, char buffer[],
	int flags, int width, int precision, int size)
{
	int length = BUFF_SIZE - ind - 1;
	char padd = ' ', extra_ch = 0;

	UNUSED(size);

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
		if (is_negative)
		extra_ch = '-';

		else if (flags & F_PLUS)
		extra_ch = '+';

		else if (flags & F_SPACE)
		extra_ch = ' ';

	return (writes_num(ind, buffer, flags, width, precision,
		length, padd, extra_ch));
}










/**
 * writes_unsgnd - function writes an unsigned number
 *
 * @is_negative: takes if the num is negative
 * @ind: Index at which number starts in the buffer
 * @buffer: an Array of chars
 * @flags: Flag specifiers
 * @width: Widths specifier.
 * @precision: the Precision specifier
 * @size: the size specifier
 *
 * Return: Nos of written chars.
 */
int writes_unsgnd(int is_negative, int ind,
	char buffer[],
	int flags, int width, int precision, int size)
{
	/* Number is stored at the bufer's right and starts at position i */
	int length = BUFF_SIZE - ind - 1, i = 0;
	char padd = ' ';

	UNUSED(is_negative);
	UNUSED(size);

	if (precision == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
		return (0); /* printf(".0d", 0)  no char is printed */

	if (precision > 0 && precision < length)
		padd = ' ';

	while (precision > length)
	{
		buffer[--ind] = '0';
		length++;
	}
	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';

	if (width > length)
	{
		for (i = 0; i < width - length; i++)
			buffer[i] = padd;

		buffer[i] = '\0';
		if (flags & F_MINUS) /* to asign an extra char to left of buffer [buffer>padd]*/
		{
			return (write(1, &buffer[ind], length) + write(1, &buffer[0], i));
		}
		else /* To asign an extra char to left of padding [padd>buffer]*/
		{
			return (write(1, &buffer[0], i) + write(1, &buffer[ind], length));
		}
	}
	return (write(1, &buffer[ind], length));
}




/**
 * writes_pointer - Write a memory address
 *
 * @buffer: An Arrays of chars
 * @ind: Index at  which the number starts in the buffer
 * @length: the  length of number
 * @width: the Width specifier
 * @flags: Flag specifier
 * @padd: Char representing the padding
 * @extra_c: Char representing extra char
 * @padd_start: Index at which padding should start
 *
 * Return: Written chars.
 */
int writes_pointer(char buffer[], int ind, int length,
	int width, int flags, char padd, char extra_c, int padd_start)
{
	int i;

	if (width > length)
	{
		for (i = 3; i < width - length + 3; i++)
			buffer[i] = padd;
		buffer[i] = '\0';
		if (flags & F_MINUS && padd == ' ')/* Asigns extra char to left of buffer */
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[ind], length) + write(1, &buffer[3], i - 3));
		}
		else if (!(flags & F_MINUS) && padd == ' ')/* asigns an extra char to left of buffer */
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (extra_c)
				buffer[--ind] = extra_c;

			return (write(1, &buffer[3], i - 3) + write(1, &buffer[ind], length));
		}
		else if (!(flags & F_MINUS) && padd == '0')/* extra char to left of padd */
		{
			if (extra_c)
				buffer[--padd_start] = extra_c;
			buffer[1] = '0';
			buffer[2] = 'x';
			return (write(1, &buffer[padd_start], i - padd_start) +
				write(1, &buffer[ind], length - (1 - padd_start) - 2));
		}
	}
		buffer[--ind] = 'x';
		buffer[--ind] = '0';
	if (extra_c)
		buffer[--ind] = extra_c;

	return (write(1, &buffer[ind], BUFF_SIZE - ind - 1));
}

