#include "main.h"

/**
 * get_sigint_r -  Handle the crtl + c call in prompt
 * @sig: Signal handler.
 */
void get_sigint_r(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "\n^-^ ", 5);
}
