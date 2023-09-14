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
void my_prop(void)
{
	Ha_print("HA$AH_shell$ ");
}
/**
 * exec_cmd - excute the promit
 * @cmd: char input pointer
 * Return: void
 */
 void exec_cmd(const char *cmd)
 {
	 pid_t new_child_pid;
	 char *argus[128];
	 int argus_count;
	 char *token;

	token = strtok((char *)cmd, " ");
	 argus_count = 0;
	 new_child_pid = fork();
	 if (new_child_pid == -1)
	 {
		 perror("Error not found");
		 exit(EXIT_FAILURE);
	 }
	 else if (new_child_pid == 0)
	 {
		 while (token != NULL)
		 {
			 argus[argus_count++] = token;
			 token = strtok(NULL, " ");
		 }
		 argus[argus_count] = NULL;
		 execvp(argus[0], argus);
		 perror("AH$HA ERROR");
		 exit(EXIT_FAILURE);
	 }
	 else
	 {
		 wait(NULL);
	 }
 }
/**
 * read_cmd - read the inputs from user
 * @cmd: the input command
 * @size: the size
 * Return: the input command
 */
 void read_cmd(char *cmd, size_t size)
 {
	 if (fgets(cmd, size, stdin) == NULL)
	 {
		 if (feof(stdin))
		 {
			 Ha_print("\n");
			 exit(EXIT_SUCCESS);
		 } else {
			 Ha_print("error during input \n");
			 exit(EXIT_FAILURE);
		 }
	 }
	 cmd[strcspn(cmd, "\n")] = '\0';
 }
