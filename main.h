#ifndef MAIN
#define MAIN

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

/**environ variable**/
extern char **environ;

/**for simple shell versions**/
void simple_shell(void);
void simple_shell02(void);
void simple_shell03(void);

/**for certen cases**/
void e_of(char *);
void getline_check(ssize_t stat, char *cmd);
void exec_process(char *cmd_path, char **args, int exec_stat, char *cmd, pid_t pid);
char *tokenize_pro_name(char **, char **);

/**for environement variables**/
int env_exists(const char *name);
char *get_env(const char *name);
char *cmd_type(char *pro);

/****/
/**for strings manupilation**/
char *str_find(char *str, char dil);
char *str_cspn(char *);
int str_ncpm(char *s1, char *s2);
#endif
