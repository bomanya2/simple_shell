#include "main.h"
/**
 * read_line -Reads the input string
 *
 * @i_eof: Returns value of getline function
 * Return: Input string
 */
char *read_line(int *i_eof)
{
	char *input = NULL;
	size_t bufsize = 0;

	*i_eof = getline(&input, &bufsize, stdin);

	return (input);
}
