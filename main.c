#include "shell.h"

char **global_argv;
int global_argc;

int main(int argc, char *argv[])
{
	global_argc = argc;
	global_argv = argv;

	execute();
	return 0;
}
