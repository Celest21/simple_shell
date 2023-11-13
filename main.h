#ifndef MAIN_H
#define MAIN_H

/*libraries*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/types.h>

/*prototypes*/

void display_prompt(const char *prompt);
void interactive_mode(const char *prompt);
void non_interactive_mode(void);
void execute_user_command(const char *command);
int execute_using_execve(const char *command, char *const args[]);
void read_and_execute_script(const char *script_filename);
ssize_t getline(char **lineptr, size_t *n, FILE *stream);
extern char **environ;
char *strtok(char *str, const char *delim);
int _putchar(char c);
#endif

