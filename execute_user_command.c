#include "main.h"

/**
 * execute_user_command - executes command the user provides
 * @command: command to be executed
 *
 * Takes user input, tokenizes it, and executes it with arguments.
 *
 * Return: None
 */

void execute_user_command(const char *command)
{
    char *command_copy = strdup(command);
    char *token = strtok(command_copy, " ");
    int status = 0;

    if (token != NULL)
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

        /*Check if the command includes a path*/
        if (access(cmd, F_OK) == 0) {
            /* If the command with path is found, execute it*/
            status = execute_using_execve(cmd, args);
        } else {
            /*Search for the command in the PATH*/
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
                    /*If the command is found, execute it*/
                    status = execute_using_execve(full_path, args);
                    free(full_path);
                    command_found = 1;
                    break;
                }

                free(full_path);
                path_token = strtok(NULL, ":");
            }

            free(path_copy);

            if (!command_found) {
                printf("Command not found: %s\n", cmd);
            }

            if (status == -1)
            {
                perror("execute_using_execve");
            }
        }
    }

    free(command_copy);
}
