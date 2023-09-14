#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/wait.h>

void Ha_print(const char *text);
void my_prop(void);
void exec_cmd(const char *cmd);
void read_cmd(char *cmd, size_t size);

#endif
