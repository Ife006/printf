#include "main.h"

/**
 * parser - reads through the format string
 * @format: string to print
 * @f_list: list of options
 * @ap: list of arguments
 *
 * Return: number of characters read
 */
int parser(const char *format, op_t f_list[], va_list ap)
{
	int i, j, r_val, printed_chars = 0;

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			for (j = 0; f_list[j].sym != NULL; j++)
			{
				if (format[i + 1] == f_list[j].sym[0])
				{
					r_val = f_list[j].fp(ap);
					if (r_val == -1)
						return (-1);
					printed_chars += r_val;
						break;
				}
			}
			if (f_list[j].sym == NULL && format[i + 1] != ' ')
			{
				if (format[i + 1] != '\0')
				{
					_putchar(format[i]);
					_putchar(format[i + 1]);
					printed_chars += 2;
				}
				else
					return (-1);
			}
			i = i + 1;
		}
		else
		{
			_putchar(format[i]);
			printed_chars++;
		}
	}
	return (printed_chars);
}

/**
 * _printf - a function that produces output according to a format.
 * writes output to stdout, the standard output stream
 * @format: character string with zero or more directives
 *
 * Return: the number of characters printed
 * (excluding the null byte used to end output to strings)
 */
int _printf(const char *format, ...)
{
	int printed_chars;
	op_t f_list[] = {
		{"c", print_char},
		{"s", print_str},
		{"%", print_percent},
		{"i", print_int},
		{"d", print_int},
		{NULL, NULL}
	};

	va_list ap;

	if (format == NULL)
		return (-1);

	va_start(ap, format);
	printed_chars = parser(format, f_list, ap);
	va_end(ap);

	return (printed_chars);
}
