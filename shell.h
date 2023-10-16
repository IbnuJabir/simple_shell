#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdarg.h>
#include <stddef.h>

#define MAX_ARGS 64
#define MAX_PATH_LENGTH 1024

extern char **global_argv;
extern int global_argc;

/* prototypes */

void search_file_in_path(const char *filename, const char *path);
void executeCommand(char *command);
void execute(void);
void executeCmd(char *command, char *token);
void exec(char* command);
char *path(char *command);
char *pathArg(char *commandArg);
void executeCommandArg(char *commandArg);
void printEnvironment(void);

/*  break    */

int _printf(const char *format, ...);
int _putchar(char c);
int print_char(char c);
int print_number(int n);
int print_str(char *str);
int print_hex_u(unsigned int num);
int print_custom_string(char *str);

/* handler fumctions */

int handle_char(va_list args);
int handle_string(va_list args);
int handle_number(va_list args);
int handle_hex_u(va_list args);
int handle_custom_str(va_list args);

/* custom functions */

void _puts(const char *str);
char* _getenv(const char* name);
int _snprintf(char* buffer, size_t size, const char* format, ...);
int _vsnprintf(char *str, size_t size, const char *format, va_list args);
int _strcmp(const char *s1, const char *s2);
int _strncmp(const char *s1, const char *s2, size_t n);
char *_strchr(const char *s, int c);
char *_strdup(const char *str);
size_t _strlen(const char *str);
void *_memcpy(void *dest, const void *src, size_t n);
size_t _strcspn(const char *str, const char *reject);

#endif /* SHELL_H */