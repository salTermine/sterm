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