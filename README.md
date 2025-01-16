# simple_shell

> [note]
> This project is not fully complete and is still awaiting new features to be added.

      The original Unix operating system was designed and implemented by Ken Thompson, Dennis Ritchie, and others at AT&T's Bell Labs in the late 1960s. Ken Thompson also wrote the first version of the UNIX shell and invented the B programming language, which is the direct predecessor to C, later developed by Dennis Ritchie. Ken Thompson is a renowned computer scientist known for his contributions to Unix and programming languages, including the Go language.

### The following sections summarize key concepts related to Unix operating systems and shell functionality:
- **How does a shell work?** A shell serves as an interface between the user and the operating system, interpreting and executing commands.
  
- **What is a PID and a PPID?** A PID (Process ID) is a unique identifier for each process, while a PPID (Parent Process ID) identifies the parent process that created it.
  
- **How to manipulate the environment of the current process?** Use commands like `export`, `set`, and `unset` to modify environment variables.
  
- **What is the difference between a function and a system call?** A function is a reusable code block, while a system call requests the operating system to perform tasks.
  
- **How to create processes?** Use the `fork()` system call to create a new process by duplicating the calling process.

## About: 

      This project implements a simple shell with various versions, each designed to build upon the last, enhancing functionality and usability. The primary features include:
- **Input Handling:** The shell presents a prompt where you can enter commands and navigate the file system.
- **Command Execution:** You can execute commands just like in a standard terminal. For example, typing `ls` will list files in the current directory.
- **Built-in Commands:** The shell includes built-in commands such as:
  - `ls , /bin/ls [arguments]`: to view the details of the `ls` command.
  - `env`: to display the current environment variables.
  - `setenv [name] [value]`: to set new environment variables.
  - `unsetenv [variable]`: to remove existing environment variables.
  - `exit [status]`: to terminate the shell with a specified exit status.

### Usage:

To compile the shell, use the following command:

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```

 (use the prompt10.c instead of all versions)
After compilation, you can run the shell by executing ./hsh in your terminal. This will launch the simple shell where you can enter commands and explore its functionality.

## Different Versions of Simple Shell

The project includes multiple versions of a simple shell, each enhancing functionality and features:

| **File**        | **Description**                                                                                     |
|------------------|-----------------------------------------------------------------------------------------------------|
| `prompt01.c`     | Creates a basic UNIX command line interpreter that displays a prompt, accepts single-word commands, and handles errors, including "end of file" (Ctrl+D). |
| `prompt02.c`     | Extends the shell to handle command lines with arguments.                                            |
| `prompt03.c`     | Implements PATH handling for locating executable commands.                                           |
| `prompt04.c`     | Implements the built-in `exit` command to terminate the shell.                                        |
| **`prompt10.c`**     | Finalizes a ready-to-use implementation of the simple shell.                                         |
| `prompt011.c`    | Used a custom `getline` function for input handling.                                             |
| `prompt021.c`    | Used a custom `strtok` function for string tokenization.                                       |
| `prompt041.c`    | Implements exit functionality that returns an exit status code.                                     |

## File Descriptions

| File Name             | Description                                      |
|-----------------------|--------------------------------------------------|
| `env_manip.c`        | Functions to manipulate every thing that has to do smtg with the environment variables. |
| `get_line.c`         | Functions to read a line of input. (get_line stuff)                |
| `main.c`             | Main program file containing the entry point.    |
| `main.h`             | Header file containing function prototypes.      |
| `set_unset_env.c`    | Functions to set and unset environment variables. |
| `sp_functions.c`     | Specialized functions for specila cases.    |
| `str_functions.c`    | Core string manipulation functions.               |
| `str_functions2.c`   | Additional string manipulation functions.        |
| `strat/`             | Directory containing files (warm-ups for simple shell).             |


> Shell Project Task Breakdown - 4 Week Schedule

| **Week** | **Task Number** | **Task Name**                                   | **Time Estimate per Task** | **Status** | **Total Time Estimate** |
|----------|------------------|-------------------------------------------------|----------------------------|------------|-------------------------|
| Week 1  | 0                | Documentation                                   | (a lot)                    |  done          |                         |
|          | 1                | Betty checks                                    | 2-4 hours                  |  didn't get the task purpose          |                         |
|          | 2                | Write UNIX interpreter                          | 10-15 hours                |  mostly done (error handling)         |                         |
|          | 3                | Handle command-line args                        | 4-6 hours                  |  done         | **~25 hours**          |
|----------|------------------|-------------------------------------------------|----------------------------|------------|-------------------------|
| Week 2  | 4                | PATH handling                                   | 8-12 hours                 |   done (used sfprintf lol)     |                         |
|          | 5                | Exit built-in                                   | 4-6 hours                  |  done         |                         |
|          | 6                | env built-in                                    | 6-8 hours                  |     done      |                         |
|          | 7                | Write getline                                   | 10-15 hours                |     done      | **~35 hours**       
|----------|------------------|-------------------------------------------------|----------------------------|------------|-------------------------|
| Week 3  | 8                | No strtok                                       | 8-10 hours                 |  done          |                         |
|          | 9                | Exit args                                       | 6-8 hours                  |   done       |                         |
|          | 10               | setenv/unsetenv                                 | 10-15 hours                |   done       |                         |
|          | 11               | cd built-in                                     | 15-20 hours                |           |                         |
|          | 12               | Command separator                               | 8-10 hours                 |            | **~45 hours**          |
|----------|------------------|-------------------------------------------------|----------------------------|------------|-------------------------|
| Week 4  | 13               | Logical operators `&&` `II`                     | 10-15 hours                |            |                         |
|          | 14               | Alias                                           | 10-15 hours                |            |                         |
|          | 15               | Variable replacement                             | 8-12 hours                 |            |                         |
|          | 16               | Comments                                        | 4-6 hours                  |            |                         |
|          | 17               | File input                                      | 6-10 hours                 |            | **~40 hours**          |
|----------|------------------|-------------------------------------------------|----------------------------|------------|-------------------------|
|**Total**|                  |                                                 |                            |   i         | **~178 hours**       | 
* **This project is posed for the momemnt.**
