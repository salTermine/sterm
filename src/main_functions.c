#include "../include/sterm.h"

/* Main program loop */
int sterm_loop() {

	char *prompt = NULL;
	char *cmd = NULL;
	char **arguments = NULL;
  
  /* Show welcome message to users */
	WELCOME();

  /* Create custom prompt */
	prompt = (malloc(sizeof(char) * MAX_LENGTH));
	prompt = get_prompt();

	while((cmd = readline(prompt)) != NULL) {

    if(strlen(cmd) > 0) {
      arguments = parse_cmd(cmd);
      if(!isBuiltin(arguments))
        execute_cmd(arguments);
    }
		prompt = get_prompt();
	}
  free(prompt);
  free(cmd);
  free(arguments);
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

    if (position >= CMD_LENGTH) {
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

int execute_cmd(char **arguments) {
  pid_t pid, wpid;
  int status;

  pid = fork();
  if (pid == 0) {
    // Child process
    if (execvp(arguments[0], arguments) == -1) {
      perror("sterm");
    }
    exit(EXIT_FAILURE);
  } else if (pid < 0) {
    // Error forking
    perror("sterm");
  } else {
    // Parent process
    do {
      wpid = waitpid(pid, &status, WUNTRACED);
    } while (!WIFEXITED(status) && !WIFSIGNALED(status));
  }
  return 1;
}

/* Check if arguments are builtin commands */
int isBuiltin(char **arguments) {

	if(strcmp(arguments[0], "help") == 0) {
    HELP(arguments[0]);
    return 1;
  }
  else if(strcmp(arguments[0], "exit") == 0) {
    exit(3);
  }
  else if(strcmp(arguments[0], "clear") == 0) {
    clear_screen();
    return 1;
  }
  else if(strcmp(arguments[0], "cd") == 0) {
    ch_dir(arguments);
    return 1;
  }
  else if(strcmp(arguments[0], "pwd") == 0) {
    p_dir();
    return 1;
  }
  return 0;
}