#include "main.h"
#include <stdio.h>

/**
 * execute_env_command - Print the environment variables.
 *
 * This function prints the environment variables to the standard output.
 * It iterates through the `environ` array and prints each variable until
 * it encounters a NULL pointer, indicating the end of the array.
 */
void execute_env_command(void)
{
	char **environ;
	int i = 0;

	while (environ[i] != NULL)
	{
		printf("%s\n", environ[i]);
		i++;
	}
}
