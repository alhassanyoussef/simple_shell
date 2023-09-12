#include "shell.h"

/**
 * Ha_print - Prints a string to the standard output
 * @text: The string to be printed
 *
 * Return: void
 */
void Ha_print(const char *text)
{
	write(STDOUT_FILENO, text, strlen(text));
}

/**
 * my_prompt - Prints a prompt to the standard output
 *
 * Return: void
 */
void my_prompt(void)
{
	Ha_print("Ha$AH_shell$");
}
