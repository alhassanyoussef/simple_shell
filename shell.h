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
int _myhis(info_t *info);
int unset_ali(info_t *info, char *st);
int set_ali(info_t *info, char *st);
int print_alias(list_t *node);
int _myalias(info_t *info);


#endif
