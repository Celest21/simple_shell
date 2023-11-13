#include "main.h"

/**
 * interactive_mode - runs the interactive shell
 * @prompt: personalised prompt displayed to the user
 *
 * displays prompt, reads user input and executes commands
 *
 * Return: none
 */

void interactive_mode(const char *prompt)
{
	char *line = NULL; /*variable for output*/
	size_t len = 0; /*variable to store lenght*/
	ssize_t read; /*variable fo result of reading*/

	while (1) /*loop for interaction to continue*/
	{
		display_prompt(prompt);
		read  = getline(&line, &len, stdin); /*read input*/

		if (read == -1) /*if read successful*/
		{
			if (feof(stdin))
			{
				printf("\n");
				break;
			}
			else
			{
				printf("Error reading input.\n");
				break;
			}
		}

			line[strlen(line) - 1] = '\0'; /*remove new line character*/

			if (strcmp(line, "exit") == 0)
			{
				break;
			}

			execute_user_command(line); /*call function*/
		}

	free(line); /*free memory*/
}

/**
 * non_interactive_mode - runs shell in non interactive mode
 *
 *
 *
 * Return: None
 */

void non_interactive_mode(void)
{
	char *line = NULL;
	size_t len = 0;

	while (getline(&line, &len, stdin) != -1)
	{
		line[strlen(line) - 1] = '\0';
		if (line[0] != '\0')
		{
			execute_user_command(line);
		}
	}

	free(line);
}
