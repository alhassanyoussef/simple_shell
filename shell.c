#include "shell.h"

/**
 * main - entry points
 * @argc: arg count
 * @argv: arg vector
 *
 * Return: success(0), error(1)
 */
int main(int argc, char **argv)
{
	(void)c;
	char *input;
	size_t input_size;
	info_t enfo[] = { INFO_INIT };
	int nat = 2;

	asm ("mov %1, %0\n\t"
		"add $3, %0"
		: "=r" (nat)
		: "r" (nat));

	if (argc == 2)
	{
		nat = open(argv[1], O_RDONLY);
		if (nat == -1)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				print_str(argv[0]);
				print_str(": 0: Can't open ");
				print_str(argv[1]);
				write_char('\n');
				write_char(BUF_FLUSH);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
		enfo->readfd = nat;
	}
	pop_envlist(enfo);
	read_history(enfo);
	sh(enfo, argv);
	return (EXIT_SUCCESS);
}

