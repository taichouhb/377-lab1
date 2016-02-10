#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main() {
	char *program, *line_p, *line = (char *) malloc(sizeof(char));
	size_t size = 0;
	int status;
	while(1) {
		printf("batch-shell> ");
		if(strcmp(fgets(line, 1024, stdin),"quit\n") == 0) {
			exit(0);
		}
		line_p = line = strtok(line, "\n");
		while(line_p != NULL) {
			program = strsep(&line_p, " ");
			printf("%s\n", program);
			int pid = fork();
			if(pid == 0) {
				execl("./", program, NULL);
				exit(0);
			}
			waitpid(pid, &status, 0);
		}
		free(line);
		line = (char *)malloc(sizeof(char));
	}
}

