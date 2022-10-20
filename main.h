#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>

/**
 * struct op - operator structure
 * @c: specifier
 * @fp: function pointer
 */
typedef struct op
{
	char *sym;
	int (*fp)(va_list);
} op_t;

int _printf(const char *format, ...);
int _putchar(char c);
int print_char(va_list list);
int print_str(va_list list);
int print_percent(__attribute__((unused))va_list list);
int print_int(va_list list);

#endif
