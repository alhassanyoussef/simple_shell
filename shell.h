#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

void Ha_print(const char *text);
void my_prop(void);
void exec_cmd(const char *cmd);
void read_cmd(char *cmd, size_t size);
#endif
