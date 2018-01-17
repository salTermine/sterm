#include "../include/sterm.h"

/* Wrapper for malloc */
void *check_malloc(size_t size) {
	void *value = malloc(size);
	if(value == 0) {
		fprintf(stderr, "Memory error\n");
		return 0;
	}
	return value;
}

void clear_screen() {
    fprintf(stdout,"\033[2J\033[1;1H");
}

void ch_dir(char **arguments) {
	if(arguments[1] == NULL) chdir(getenv("HOME"));
	else if(chdir(arguments[1]) == -1) fprintf(stderr," %s: Directory does not exist\n", arguments[1]);
}

void p_dir() {

	char cwd[256];

	if (getcwd(cwd, sizeof(cwd)) == NULL)
	    perror("getcwd() error");
	else
		fprintf(stdout,"%s\n", cwd);
}