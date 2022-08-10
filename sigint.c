#include "main.h"

/**
 * get_sigint - It handles crtl + c call
 * @sig: Signal handler
 */
void get_sigint(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "\n^-^ ", 5);
}
