#ifndef MAIN_H
#define MAIN_H

#include <sys/types.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

void display_prompt(const char *prompt);
void interactive_mode(const char *prompt);
void non_interactive_mode(void);
void execute_user_command(const char *command);
int execute_using_execve(const char *command, char *const args[]);
ssize_t get_line(char **lineptr, size_t *n, FILE *stream);
char *str_tok(char *str, const char *delim);
void execute_env_command(void);

extern char **environ;

#endif

