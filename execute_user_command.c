#include "main.h"

/**
 * execute_user_command - Execute user-specified command.
 *
 * Processes provided `command`, supporting "exit" and "env" built-in commands.
 * Searches system PATH for external commands. Uses execute_using_execve for
 * execution. Displays appropriate messages for command not found or errors.
 *
 * @command: User-provided command to execute.
 */
void execute_user_command(const char *command)
{
	char *command_copy = strdup(command);
	char *token = strtok(command_copy, " ");
	int status = 0;

	if (token != NULL)
	{
		if (strcmp(token, "exit") == 0)
		{
			printf("Exiting shell...\n");
			exit(0);
		}
		else if (strcmp(token, "env") == 0)
		{
			execute_env_command();
		}
		else
		{
			char *cmd = token;
			char *args[100];
			int arg_index = 0;

			args[arg_index++] = cmd;

		while ((token = strtok(NULL, " ")) != NULL)
		{
			args[arg_index++] = token;
		}

		args[arg_index] = NULL;

		if (access(cmd, F_OK) == 0)
		{
			status = execute_using_execve(cmd, args);
		}
		else
		{
			char *path = getenv("PATH");
			char *path_copy = strdup(path);
			char *path_token = strtok(path_copy, ":");

			int command_found = 0;

			while (path_token != NULL)
			{
				char *full_path = malloc(strlen(path_token) + strlen(cmd) + 2);

				sprintf(full_path, "%s/%s", path_token, cmd);

				if (access(full_path, X_OK) == 0)
				{
					status = execute_using_execve(full_path, args);
					free(full_path);
					command_found = 1;
					break;
				}

				free(full_path);
				path_token = strtok(NULL, ":");
			}

			free(path_copy);

			if (!command_found)
		{
			printf("Command not found: %s\n", cmd);
		}

		if (status == -1)
		{
			perror("execute_using_execve");
		}
	}
	}
	}
	free(command_copy);
}
