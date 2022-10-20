#include "main.h"

/**
 * print_number - Prints numbers.
 * @list: Argument list.
 * Return: Number of arguments printed.
 */
int print_number(va_list list)
{
	int n, div, len;
	unsigned int num;

	n = va_arg(list, int);
	div = 1;
	len = 0;

	if (n < 0)
	{
		len += _putchar('-');
		num = n * -1;
	}
	else
		num = n;

	for (; (num / div) > 9; )
		div *= 10;

	for (; div != 0; )
	{
		len += _putchar('0' + num / div);
		num %= div;
		div /= 10;
	}

	return (len);
}

/**
 * print_char - Prints character.
 * @list: Argument list.
 * Return: Number of characters printed.
 */
int print_char(va_list list)
{
	_putchar(va_arg(list, int));
	return (1);
}

/**
 * print_str - Prints string.
 * @list: Argument list.
 * Return: Number of characters printed.
 */
int print_str(va_list list)
{
	int index;
	char *str;

	str = va_arg(list, char *);
	if (str == NULL)
		str = "(null)";

	for (index = 0; str[index] != '\0'; index++)
		_putchar(str[index]);

	return (index);
}

/**
 * print_percent - Prints percent symbol.
 * @list: Argument list.
 * Return: Number of characters printed.
 */
int print_percent(__attribute__((unused))va_list list)
{
	_putchar('%');
	return (1);
}

/**
 * print_int - Prints integers.
 * @list: Argument list.
 * Return: Number of characters printed.
 */
int print_int(va_list list)
{
	int num = print_number(list);

	return (num);
}
