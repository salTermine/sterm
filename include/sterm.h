/* Header file for sterm
 * Author: Salvatore Termine
 * Date: 08/05/17
 */

#ifndef STERM_H
#define STERM_H

#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <glob.h>

/* Define functions */
int sterm_loop();
int isBuiltin(char **arguments);
int execute_cmd(char **arguments);
char *get_prompt();
char **parse_cmd(char *cmd);
void clear_screen();
void ch_dir(char **arguments);
void p_dir();
void *check_malloc(size_t size);

/* Declare constants */
#define MAX_LENGTH 1024
#define CMD_LENGTH 256
#define DELIM " \t\r\n"

/* Macros */
#define WELCOME() do {                                                                \
        fprintf(stdout,                                                               \
            "\n*****************************************************************\n"   \
            "**                 WELCOME TO THE STERM SHELL                  **\n"     \
            "**           For a list of available commands type help        **\n"     \
            "*****************************************************************\n\n"   \
            );                                                                        \
    } while(0);

#define HELP(name) do {                                                                                           \
        fprintf(stderr,                                                                                           \
            "\n%s menu\n"                                                                                         \
            "\n"                                                                                                  \
            "help                           Displays this sdfsfsdfhelp menu.\n\n"                                 \
            "exit                           Exits the shell\n\n"                                                  \
            "cd [  | path]                  Changes the current working directory of the shell.\n"                \
            "                               If a path is not supplied, cd returns to home directory\n\n"          \
            "pwd                            Returns the absolute path of the current working directory\n\n"       \
            "prt                            Prints the return code of the command that was last executed\n\n"     \
            "chpmt                          Changes the prompt settings.\n\n"                                     \
            "chclr                          Changes the prompt colors\n\n"                                        \
            ,(name));                                                                                             \
    } while(0);

#endif /*STERM_H*/