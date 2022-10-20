#include <unistd.h>

/**
 * _putchar - writes character to standout
 * @c: character to print
 *
 * Return: 1 on success, otherwise, -1 on error
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
