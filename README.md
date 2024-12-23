# simple_shell
 
- [ ] **Who designed and implemented the original Unix operating system?**
  - The original Unix operating system was designed and implemented by Ken Thompson, Dennis Ritchie, and others at AT&T's Bell Labs in the late 1960s.

- [ ] **Who wrote the first version of the UNIX shell?**
  - The first version of the UNIX shell, known as the Thompson shell, was written by Ken Thompson.

- [ ] **Who invented the B programming language (the direct predecessor to the C programming language)?**
  - The B programming language was developed by Ken Thompson in the late 1960s.

- [ ] **Who is Ken Thompson?**
  - Ken Thompson is a computer scientist and one of the co-creators of Unix. He also contributed to the development of the B programming language and is known for his work on the Go programming language.

- [ ] **How does a shell work?**
  - A shell is a command-line interface that allows users to interact with the operating system. It interprets user commands and executes them, often launching programs or scripts.

- [ ] **What is a PID and a PPID?**
  - PID (Process ID) is a unique identifier for each running process. PPID (Parent Process ID) is the identifier of the process that created (or spawned) the current process.

- [ ] **How to manipulate the environment of the current process?**
  - The environment can be manipulated using shell commands such as `export` to set environment variables or `unset` to remove them.

- [ ] **What is the difference between a function and a system call?**
  - A function is a block of code that performs a specific task within a program, while a system call is a request made by a program to the operating system to perform a specific operation or access hardware resources.

- [ ] **How to create processes?**
  - Processes can be created using system calls like `fork()` to create a new process and `exec()` to execute a new program in that process.

- [ ] **What are the three prototypes of main?**
  - The three prototypes of `main` are:
    1. `int main(void)`
    2. `int main(int argc, char *argv[])`
    3. `int main(int argc, char **argv)`

- [ ] **How does the shell use the PATH to find the programs?**
  - The shell uses the `PATH` environment variable, which contains a list of directories, to locate executable files. When a command is entered, the shell searches these directories in order until it finds the executable.

- [ ] **How to execute another program with the execve system call?**
  - The `execve` system call is used to execute a program by providing the path to the executable, an array of arguments, and an array of environment variables.

- [ ] **How to suspend the execution of a process until one of its children terminates?**
  - A process can suspend its execution by using the `wait()` system call, which waits for one of its child processes to terminate.

- [ ] **What is EOF / “end-of-file”?**
  - EOF (End Of File) is a condition in a computer operating system that indicates no more data can be read from a data source, such as a file or input stream.
