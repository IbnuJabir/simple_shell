#include "shell.h"
/**
 * main - Entry point
 *
 * @argc: number of arguments
 *
 * @argv: array that contain arguments
 *
 * Return: always 0
 */

int main(int argc, char *argv[])
{
	global_argc = argc;
	global_argv = argv;

	execute();
	return (0);
}
