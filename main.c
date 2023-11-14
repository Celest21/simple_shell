#include "main.h"


/**
 * main - entry point of shell
 * @argc: void
 * @argv: void
 *
 * it is the entry point of the program
 * checks if shell is running in interactive or non-interactive mode
 *
 * Return: 0 execution successful
 */

int main(int argc, char **argv)
{
	/*declares and initialise variable prompt*/
	char *prompt = "(ICShell)$";

	(void) argc;
	(void) argv;

	/*checks if in interactive or non interactive mode*/
	if (isatty(STDIN_FILENO))
	{
		/*if interactive shows prompt*/
		interactive_mode(prompt);
	}
	else
	{
		non_interactive_mode();
	}

	/*indicates a successful execution of the program*/
	return (0);
}
