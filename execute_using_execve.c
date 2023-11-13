#include "main.h"
#include <unistd.h>

/**
 * execute_using_execve - executes a command using execve
 * @command: the command to execute
 * @args:an array of strings representing the command an its arguments
 *
 * the function creates a child process using fork
 * uses execve to execute
 * waits for the child process to complete
 *
 * Return: status of child process
 */

int execute_using_execve(const char *command, char *const args[])
{
	/*variable to store process ID, fork creates child process*/
	pid_t child_pid = fork();

	/*check if fork failed*/
	if (child_pid < 0)
	{
		perror("fork");
		return (-1);
	}

	/*if zero child process execute*/
	else if (child_pid == 0)
	{
		execve(command, args, environ);
		
		
		/*if execve fails error msg printed*/
		perror("execve");
		_exit(EXIT_FAILURE);
	}
	else
	{
		/*the status of child process*/
		int status;
		/*parent process waits for child process to complete*/
		waitpid(child_pid, &status, 0);
		/*returns status of the child process*/
		return (status);
	}
}
