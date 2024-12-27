# Simple Explanations of System Calls and Functions
### 1. `access`
Check if you can read, write, or execute a file.  
**Prototype:** `int access(const char *path, int mode);`
---
### 2. `chdir`
Move to a new folder as your working directory.  
**Prototype:** `int chdir(const char *path);`
---
### 3. `close`
Close a file you're done using.  
**Prototype:** `int close(int fd);`
---
### 4. `closedir`
Close a folder you're done using.  
**Prototype:** `int closedir(DIR *dirp);`
---
### 5. `execve`
Run a new program.  
**Prototype:** `int execve(const char *file, char *const args[], char *const env[]);`
---
### 6. `exit`
End your program.  
**Prototype:** `void exit(int status);`
---
### 7. `_exit`
End your program immediately (no cleanup).  
**Prototype:** `void _exit(int status);`
---
### 8. `fflush`
Push any leftover data to the file.  
**Prototype:** `int fflush(FILE *stream);`
---
### 9. `fork`
Create a copy of your program (a child process).  
**Prototype:** `pid_t fork(void);`
---
### 10. `free`
Free up memory you don’t need anymore.  
**Prototype:** `void free(void *ptr);`
---
### 11. `getcwd`
Find out where you are (current folder).  
**Prototype:** `char *getcwd(char *buf, size_t size);`
---
### 12. `getline`
Read one line of text from a file.  
**Prototype:** `ssize_t getline(char **lineptr, size_t *n, FILE *stream);`
---
### 13. `getpid`
Get your program's unique ID.  
**Prototype:** `pid_t getpid(void);`
---
### 14. `isatty`
Check if something is a terminal (like the keyboard).  
**Prototype:** `int isatty(int fd);`
---
### 15. `kill`
Send a signal (like stop or restart) to a program.  
**Prototype:** `int kill(pid_t pid, int sig);`
---
### 16. `malloc`
Grab some memory to use for data.  
**Prototype:** `void *malloc(size_t size);`
---
### 17. `open`
Open a file to read/write.  
**Prototype:** `int open(const char *path, int flags);`
---
### 18. `opendir`
Open a folder to look inside it.  
**Prototype:** `DIR *opendir(const char *name);`
---
### 19. `perror`
Print a helpful error message.  
**Prototype:** `void perror(const char *msg);`
---
### 20. `read`
Read data from a file.  
**Prototype:** `ssize_t read(int fd, void *buf, size_t count);`
---
### 21. `readdir`
Get the next file in a folder.  
**Prototype:** `struct dirent *readdir(DIR *dirp);`
---
### 22. `signal`
Decide what to do when a signal (like interrupt) happens.  
**Prototype:** `void (*signal(int sig, void (*handler)(int)))(int);`
---
### 23. `stat`
Get information about a file (like size or permissions).  
**Prototype:** `int stat(const char *path, struct stat *buf);`
---
### 24. `lstat`
Like `stat`, but works with symlinks too.  
**Prototype:** `int lstat(const char *path, struct stat *buf);`
---
### 25. `fstat`
Get file info from a file descriptor.  
**Prototype:** `int fstat(int fd, struct stat *buf);`
---
### 26. `strtok`
Split a string into smaller pieces.  
**Prototype:** `char *strtok(char *str, const char *delim);`
---
### 27. `wait`
Pause until a child process is done.  
**Prototype:** `pid_t wait(int *status);`
---
### 28. `waitpid`
Pause for a specific child process.  
**Prototype:** `pid_t waitpid(pid_t pid, int *status, int options);`
---
### 29. `wait3`
Like `wait`, but gives extra info (resources used).  
**Prototype:** `pid_t wait3(int *status, int options, struct rusage *rusage);`
---
### 30. `wait4`
Like `waitpid`, but gives extra info.  
**Prototype:** `pid_t wait4(pid_t pid, int *status, int options, struct rusage *rusage);`
---
### 31. `write`
Write data to a file.  
**Prototype:** `ssize_t write(int fd, const void *buf, size_t count);
