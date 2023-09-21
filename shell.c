#include "shell.h"
/**
 * main - main function of the simple shell
 * Return: void
 */
int main(void)
{
	char *input;
	size_t input_size;

	input = NULL;
	input_size = 0;
	while (1)
	{
		my_prop();
		read_cmd(&input, &input_size);
		if (strcmp(input, "exit") == 0)
		{
			free(input);
			break;
		}
		exec_cmd(input);
	}
	return (0);
}
