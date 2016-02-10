#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main() {
	char *input = (char *) malloc(sizeof(char));
	char *program;
	char *input_p;
	int status;
	while(1) {
		printf("batch-shell> ");
		scanf("%s",input);
		if(strcmp(input, "quit") == 0){
			exit(0);
		}
		input_p = input;
		while(input_p != NULL) {
			program = strsep(&input_p, " ");
			printf("%s\n", program);
			int pid = fork();
			if(pid == 0) {
				execl("./", program, NULL);
				exit(0);
			}
			waitpid(pid, &status, 0);
		}
	}
}

