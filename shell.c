#include "shell.h"
/**
 * main - main function of the simple shell
 * Return: void
 */
int main(void)
{
	char cmd[150];

	while (1)
	{
		my_prop();
		read_cmd(cmd, sizeof(cmd));
		exec_cmd(cmd);
	}
	return (0);
}
