#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>


/** FLAGS **/
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/** SIZES **/
#define S_LONG 2
#define S_SHORT 1


#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/**
 * struct fmt - Struct op
 *
 * @fmt: The format
 * @fn: The function
 */
struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};

/**
 * typedef struct fmt fmt_t -  Struct op
 *
 * @fmt: The format
 * @fm_t: The function
 */
typedef struct fmt fmt_t;

int _printf(const char *format, ...);
int handle_print(const char *fmt, int *i,
va_list list, char buffer[], int flags, int width, int precision, int size);

/* The Functions */

int prints_char(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int prints_string(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int prints_percent(va_list types, char buffer[],
	int flags, int width, int precision, int size);


int prints_int(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int prints_binary(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int prints_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size);


int prints_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int prints_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int prints_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int prints_hexa(va_list types, char map_to[],
	char buffer[], int flags, char flag_ch,
	int width, int precision, int size);



/* Prints non printable chars */
int prints_non_printable(va_list types, char buffer[],
	int flags, int width, int precision, int size);


/* Prints the memory address */
int prints_pointer(va_list types, char buffer[],
	int flags, int width, int precision, int size);


/* Handles different specifiers */
int gets_flags(const char *format, int *i);
int gets_width(const char *format, int *i, va_list list);
int gets_precision(const char *format, int *i, va_list list);
int gets_size(const char *format, int *i);


/* Prints a string in reverse*/
int prints_reverse(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* Prints a string in rot 13*/
int prints_rot13string(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* Write width handlers */
int handle_write_char(char c, char buffer[],
	int flags, int width, int precision, int size);
int writes_number(int is_positive, int ind, char buffer[],
	int flags, int width, int precision, int size);
int writes_num(int ind, char bff[], int flags, int width, int precision,
	int length, char padd, char extra_c);
int writes_pointer(char buffer[], int ind, int length,
	int width, int flags, char padd, char extra_c, int padd_start);
int writes_unsgnd(int is_negative, int ind,
	char buffer[],int flags, int width, int precision, int size);



/** UTILS **/
int is_printable(char);
int appends_hexa_code(char, char[], int);
int is_digit(char);

long int converts_size_number(long int num, int size);
long int converts_size_unsgnd(unsigned long int num, int size);

void prints_buffer(char buffer[], int *buff_ind);
int _putchar(char c);

#endif

