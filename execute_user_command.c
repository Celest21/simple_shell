#include "main.h"

/**
 *execute_user_command - executes command the user provide
 *@command: command to be executed
 *
 *takes user input, tokenizes it and executes with arguments
 *
 *
 * Return:None
 */

void execute_user_command(const char *command)
{
	char *command_copy = strdup(command);
	char *token = strtok(command_copy, " ");
	int status = 0;

	if (token != NULL)
	{
		char *cmd = token;

		/*array to hold cmmand and its argument*/

		char *args[100];
		int arg_index = 0;

		args[arg_index++] = cmd;

		while ((token = strtok(NULL, " ")) != NULL)
		{
			args[arg_index++] = token;
		}

		args[arg_index] = NULL;

		/*check for built in commands and execute*/
		if (strcmp(cmd, "cp") == 0)
		{
			if (arg_index == 3)
			{
				const char *source_path = args[1];
				const char *destination_path = args[2];
				int source_fd = open(source_path, O_RDONLY);
				int destination_fd = open(destination_path, O_WRONLY | O_CREAT, 0664);

				if (source_fd != -1 && destination_fd != -1)
				{
					char buffer[4096];
					ssize_t bytes_read;
					ssize_t bytes_written = 0;

					while ((bytes_read = read(source_fd, buffer, sizeof(buffer))) > 0)
					{
						bytes_written = write(destination_fd, buffer, bytes_read);
						if (bytes_written == -1)
						{
						perror("write");
						break;
						}
					}
					close(source_fd);
					close(destination_fd);
				}
				else
				{
					perror("open");
				}
			}
			else
			{
				printf("usage: cp source_file destination_file\n");
			}
		}
		/*other built in*/
		else
		{
			status = execute_using_execve(cmd, args);
		}
	}

	if (status == -1)
	{
		perror("execute_using_execve");
	}
	free(command_copy);
}
