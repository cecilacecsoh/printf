#include <stdio.h>
#include "main.h"

void prints_buffer(char buffer[], int *buff_ind);

/**
 * _printf - Printf function
 *
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
	int j, printed = 0, printed_chars = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (j = 0; format && format[j] != '\0'; j++)
	{
		if (format[j] != '%')
		{
			buffer[buff_ind++] = format[j];
			if (buff_ind == BUFF_SIZE)
				prints_buffer(buffer, &buff_ind);
			/* write(1, &format[j], 1);*/
			printed_chars++;
		}
		else
		{
			prints_buffer(buffer, &buff_ind);
			flags = gets_flags(format, &j);
			width = gets_width(format, &j, list);
			precision = gets_precision(format, &j, list);
			size = gets_size(format, &j);
			++j;
			printed = handles_print(format, &j, list, buffer,
				flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}
	prints_buffer(buffer, &buff_ind);
	va_end(list);
	
	return (printed_chars);
}

/**
 * prints_buffer - Prints any buffer content taht exists.
 *
 * @buffer:the Array of chars
 * @buff_ind: Index to add next char for its length.
 */
void prints_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}
