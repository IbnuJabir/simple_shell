# Simple Shell - ALX SE Project

## Overview
This repository contains the Simple Shell project, developed as part of the ALX Software Engineering (SE) program. It is a command-line interpreter that mimics the basic functionalities of the Unix shell (/bin/sh), designed to help students understand advanced concepts in shell programming, including process management, system calls, and error handling. This project is implemented in C and serves as a milestone for learning low-level system programming.

## Description
The Simple Shell, also known as "hsh," reads commands from either standard input (interactive mode) or a file (batch mode) and executes them. It is built to replicate essential shell behaviors, such as executing commands, handling environment variables, and managing processes, using Unix system calls. This project is part of the ALX SE curriculum to deepen understanding of operating system interactions and C programming.

## Installation
To get started with the Simple Shell, follow these steps:

1. Clone this repository to your local machine:
   ```
   git clone https://github.com/IbnuJabir/simple_shell.git
   ```
2. Navigate to the project directory:
   ```
   cd simple_shell
   ```
3. Compile the source code using gcc with the following command (ensure you have gcc installed):
   ```
   gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
   ```
   Note: This project is built and tested on Ubuntu 20.04 LTS. Ensure your environment matches for compatibility.
4. Run the shell:
   ```
   ./hsh
   ```

## Usage
The Simple Shell supports both interactive and non-interactive (batch) modes. Here are some examples:

### Interactive Mode
- Launch the shell and type commands directly:
  ```
  $ ./hsh
  #cisfun$ ls -l
  #cisfun$ cd /tmp
  #cisfun$ env
  #cisfun$ exit
  ```
- Use Ctrl+C to interrupt a command without exiting the shell.
- Press Ctrl+D or type "exit" to terminate the shell, optionally with a status (e.g., `exit 1`).

### Batch Mode
- Run commands from a script file by piping:
  ```
  echo "/bin/ls" | ./hsh
  ```
- Or execute a script file:
  ```
  ./hsh < script.sh
  ```

For more details, refer to the man page for /bin/sh or consult the project documentation.

## Features
The Simple Shell includes the following features:
- **Interactive Mode**: Displays a prompt ("#cisfun$") and waits for user input, executing commands line by line.
- **Batch Mode**: Reads and executes commands from a file or standard input, suitable for scripting.
- **Command Execution**: Supports executing commands with arguments (e.g., `ls -l`), using the PATH environment variable to locate executables.
- **Built-in Commands**:
  - `exit [status]`: Exits the shell with an optional exit status.
  - `env`: Prints all environment variables.
  - `cd [directory]`: Changes the current directory, handling `cd -` and `cd $HOME` if no argument is provided.
  - `setenv [variable] [value]`: Sets or updates an environment variable.
  - `unsetenv [variable]`: Removes an environment variable.
- **Environment Variable Management**: Handles PATH for command resolution and supports setting/removing variables.
- **Signal Handling**: Manages Ctrl+C (SIGINT) to interrupt commands without terminating the shell, and handles EOF (Ctrl+D) for graceful exit.
- **Error Handling**: Prints error messages for invalid commands, non-existent executables, or failed operations, and redisplays the prompt.

Note: Advanced features like command separators (;), pipes (|), redirections (>), logical operators (&&, ||), variable replacements ($?, $$), comments (#), history, and aliases may not be implemented in this version; check the code for specifics.

## Technical Details
- **Programming Language**: Written entirely in C, adhering to the GNU89 standard.
- **System Calls**: Utilizes key Unix system calls such as `fork`, `execve`, `waitpid`, `access`, and `chdir` for process creation, execution, and management.
- **Build Requirements**: Compiled with gcc using options `-Wall -Werror -Wextra -pedantic -std=gnu89` to enforce strict C compliance and error checking.
- **Code Style**: Follows Betty style guidelines, checked using `betty-style.pl` and `betty-doc.pl`, ensuring clean, readable, and well-documented code.
- **Memory Management**: Designed to have no memory leaks, with custom string functions for efficient memory usage.
- **Testing Environment**: Built and tested on Ubuntu 20.04 LTS; ensure compatibility for other Unix-like systems.

## Contributing
This project is a developed under the ALX SE program, developed by: **[Kedir Jabir (@IbnuJabir)](https://ibnujabir.tech)**

Contributions and feedback are welcome! If you’d like to contribute, please fork the repository, make your changes, and submit a pull request. For inquiries or suggestions, contact:
- Email: kedirjabir12@gmail.com
- GitHub: https://github.com/IbnuJabir/simple_shell

Please ensure your contributions adhere to the Betty style and include appropriate documentation.

## License
This project is licensed under the MIT License. See the LICENSE file for details.

Copyright (C) 2025 by Kedir Jabir. All rights reserved.

## Acknowledgments
We would like to thank:
- ALX Software Engineering program for providing the educational framework and resources.
- Our mentors and instructors for guidance throughout the project.
- Betty Holberton for inspiring coding standards.
- The open-source community for tools and documentation that supported development.

## Troubleshooting
If you encounter issues, here are some common solutions:
- **Compilation Errors**: Ensure gcc is installed (`sudo apt-get install build-essential` on Ubuntu). Check for missing files or syntax errors.
- **Runtime Errors**: Verify the PATH environment variable includes necessary directories (e.g., /bin, /usr/bin). Ensure executable permissions for compiled files (`chmod +x hsh`).
- **Memory Leaks**: Use tools like valgrind to check for leaks (`valgrind --leak-check=full ./hsh`).
- **Compatibility**: Confirm your system is Ubuntu 20.04 LTS or a compatible Unix-like environment.
