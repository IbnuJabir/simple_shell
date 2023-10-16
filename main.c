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

struct GlobalData globalData;

int main(int argc, char *argv[])
{
	globalData.argc = argc;
	globalData.argv = argv;

	execute();
	return (0);
}
