#ifndef MAIN
#define MAIN

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

void simple_shell(void);
void e_of(char *);
char *tokenize_pro_name(char **);
char *str_cspn(char *);
#endif
