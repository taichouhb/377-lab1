#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
int main() {
	char *input;
	char *program;
	int status;
	while(input != "quit") {
		printf("batch-shell>");
		scanf("%s",input);
		program = strtok(input, " ");
		while(program != NULL) {
			int pid = fork();
			if(pid == 0) {
				execl("./", program, NULL);
				exit(0);
			} else {
				wait(&status);	
			}
			program = strtok(NULL, " ");
		}
	}
}

