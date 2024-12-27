| Function   | Description                                      | Prototype                                               |
|------------|--------------------------------------------------|--------------------------------------------------------|
| `access`   | Check if you can read, write, or execute a file.| `int access(const char *path, int mode);`             |
| `chdir`    | Move to a new folder as your working directory.  | `int chdir(const char *path);`                         |
| `close`    | Close a file you're done using.                  | `int close(int fd);`                                   |
| `closedir` | Close a folder you're done using.                | `int closedir(DIR *dirp);`                            |
| `execve`   | Run a new program.                               | `int execve(const char *file, char *const args[], char *const env[]);` |
| `exit`     | End your program.                                | `void exit(int status);`                              |
| `_exit`    | End your program immediately (no cleanup).       | `void _exit(int status);`                             |
| `fflush`   | Push any leftover data to the file.              | `int fflush(FILE *stream);`                           |
| `fork`     | Create a copy of your program (a child process). | `pid_t fork(void);`                                   |
| `free`     | Free up memory you don’t need anymore.           | `void free(void *ptr);`                               |
| `getcwd`   | Find out where you are (current folder).        | `char *getcwd(char *buf, size_t size);`              |
| `getline`  | Read one line of text from a file.              | `ssize_t getline(char **lineptr, size_t *n, FILE *stream);` |
| `getpid`   | Get your program's unique ID.                   | `pid_t getpid(void);`                                 |
| `isatty`   | Check if something is a terminal (like keyboard).| `int isatty(int fd);`                                 |
| `kill`     | Send a signal (like stop or restart) to a program.| `int kill(pid_t pid, int sig);`                       |
| `malloc`   | Grab some memory to use for data.                | `void *malloc(size_t size);`                          |
| `open`     | Open a file to read/write.                       | `int open(const char *path, int flags);`             |
| `opendir`  | Open a folder to look inside it.                 | `DIR *opendir(const char *name);`                     |
| `perror`   | Print a helpful error message.                   | `void perror(const char *msg);`                       |
| `read`     | Read data from a file.                           | `ssize_t read(int fd, void *buf, size_t count);`     |
| `readdir`  | Get the next file in a folder.                   | `struct dirent *readdir(DIR *dirp);`                 |
| `signal`   | Decide what to do when a signal (like interrupt) happens.| `void (*signal(int sig, void (*handler)(int)))(int);` |
| `stat`     | Get information about a file (like size or permissions).| `int stat(const char *path, struct stat *buf);`    |
| `lstat`    | Like `stat`, but works with symlinks too.       | `int lstat(const char *path, struct stat *buf);`     |
| `fstat`    | Get file info from a file descriptor.            | `int fstat(int fd, struct stat *buf);`                |
| `strtok`   | Split a string into smaller pieces.              | `char *strtok(char *str, const char *delim);`        |
| `wait`     | Pause until a child process is done.             | `pid_t wait(int *status);`                            |
| `waitpid`  | Pause for a specific child process.              | `pid_t waitpid(pid_t pid, int *status, int options);`|
| `wait3`    | Like `wait`, but gives extra info (resources used).| `pid_t wait3(int *status, int options, struct rusage *rusage);` |
| `wait4`    | Like `waitpid`, but gives extra info.            | `pid_t wait4(pid_t pid, int *status, int options, struct rusage *rusage);` |
| `write`    | Write data to a file.                            | `ssize_t write(int fd, const void *buf, size_t count);` |
