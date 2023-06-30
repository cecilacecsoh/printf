#include <stdio.h>
#include "main.h"



/**
 * is_printable - evaluates  if a char is printable
 *
 * @c: Char to be evaluated.
 *
 * Return: if printable 1 or  0 otherwise
 */
int is_printable(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}





/**
 * append_hexa_code - append an ascci in hexadecimal code to buffer
 *
 * @buffer: An array of chars.
 * @i: Index at  which to start appending.
 * @ascii_code: ASSCI CODE.
 * Return: Success 3
 */
int append_hexa_code(char ascii_code, char buffer[], int i)
{
	char map_to[] = "0123456789ABCDEF";

	/* hexa format code is 2 digits long */
	if (ascii_code < 0)
		ascii_code *= -1;

	buffer[i++] = '\\';
	buffer[i++] = 'x';

	buffer[i++] = map_to[ascii_code / 16];
	buffer[i] = map_to[ascii_code % 16];

	return (3);
}




/**
 * is_digit - confirms if a char is a digit
 *
 * @c: Char to be evaluated
 *
 * Return: if digit 1 or 0 otherwise
 */
int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}




/**
 * convert_size_number - Casts a number to the specified size
 *
 * @num: the number to be casted.
 * @size: Number indicating the type to be casted.
 *
 * Return: Casted value of num
 */
long int convert_size_number(long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((short)num);

	return ((int)num);
}




/**
 * convert_size_unsgnd - this Casts a number to the specified size
 *
 * @num: the number to be casted
 * @size: Number indicating the type to be casted
 *
 * Return: Casted value of num
 */
long int convert_size_unsgnd(unsigned long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((unsigned short)num);

	return ((unsigned int)num);
}

