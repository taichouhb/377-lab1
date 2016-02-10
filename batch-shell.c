#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main() {
	char *input;
	char *program;
	char *input_p;
	int status;
	while(input != "quit") {
		printf("batch-shell> ");
		scanf("%s",input);
		input_p = input;
		printf("input: %s\n", input);
		while(input_p != NULL) {
			program = strsep(&input_p, " ");
			//printf("%s", program);
			int pid = fork();
			if(pid == 0) {
				execl("./", program, NULL);
				exit(0);
			} else {
				wait(&status);	
			}
		}
	}
}

