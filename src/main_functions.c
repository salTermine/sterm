#include "../include/sterm.h"

/* Main program loop */
int sterm_loop() {

	char *prompt = NULL;
	char *cmd = NULL;
	char **arguments = NULL;

	WELCOME();

	prompt = (malloc(sizeof(char) * MAX_LENGTH));
	prompt = get_prompt();

	while((cmd = readline(prompt)) != NULL) {
		arguments = parse_cmd(cmd);
		isBuiltin(arguments);
		prompt = get_prompt();
	}
	return EXIT_SUCCESS;
}

/* Prompt */
char *get_prompt() {

    char *hostname = malloc(sizeof(char) * MAX_LENGTH);
    memset(hostname, 0, strlen(hostname));
    gethostname(hostname, sizeof(hostname));

    fprintf(stdout, "%s:$ ", hostname);

    free(hostname);
    return 0;
}

/* Parse command */
char **parse_cmd(char *cmd) {
  int max = 128;
  int position = 0;
  char **args = malloc(sizeof(char *) * MAX_LENGTH);
  char *arg;

  if (!args) {
    fprintf(stderr, "Allocation error\n");
    exit(EXIT_FAILURE);
  }

  arg = strtok(cmd, DELIM);

  while (arg != NULL) {
    args[position] = arg;

    position++;

    if (position >= max) {
      max += max;
      args = realloc(args, max * sizeof(char*));
      if (!args) {
        fprintf(stderr, "Allocation error\n");
        exit(EXIT_FAILURE);
      }
    }
    arg = strtok(NULL, DELIM);
  }
  args[position] = NULL;
  return args;
}

/* Check if arguments are builtin commands */
int isBuiltin(char **arguments) {
	if(strcmp(arguments[0], "help") == 0) {
        HELP(arguments[0]);
        return 1;
    }
    else if(strcmp(arguments[0], "exit") == 0) {
        exit(EXIT_SUCCESS);
    }
    else if(strcmp(arguments[0], "clear") == 0) {
        clear_screen();
        return 1;
    }
    return 0;
}