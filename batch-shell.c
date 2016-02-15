//imports
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main() {
	//allocate space for the program on deck, the line, and line pointer for
	//where we've gone through to
	char *program, *line_p, *line = (char *) malloc(sizeof(char));
	size_t size = 0;
	int status;
	//continuos while loop
	while(1) {
		//our shell view
		printf("batch-shell> ");
		//if quit is ever inputed
		if(strcmp(fgets(line, 1024, stdin),"quit\n") == 0) {
			exit(0);
		}
		//traverse through the input string to the next available token (next program)
		line_p = line = strtok(line, "\n");
		//while there are more tokens in the inputed string to run
		while(line_p != NULL) {
			//set program to the place where the pointer is set to
			program = strsep(&line_p, " ");
			//fork off the process 
			int pid = fork();
			//if in child
			if(pid == 0) {
				//execute the program
				execlp(program, "", (char *)0);
				exit(0);
			}
			//wait for the program to finish executing
			waitpid(pid, &status, 0);
		}
		//free the current line and malloc another data
		//we ran into a problem with the execution, and this was the fix for that
		free(line);
		line = (char *)malloc(sizeof(char));
	}
}

