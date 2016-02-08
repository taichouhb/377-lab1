#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main() {
	int c_pid = fork();
	int g_pid;
	if(c_pid == 0) {
		g_pid = fork();
		if(g_pid == 0) {
			sleep(10);
			printf("Grandchild process with process id %d has completed.\n", getpid());
		} else {
			int g_status;
			if(waitpid(g_pid, &g_status, 0)) {
				printf("Child process with process ID %d has completed.\n", getpid());
				exit(0);
			}
		}
	} else {
		int c_status;
		if(waitpid(c_pid, &c_status, 0)) {
			printf("Parent process with process ID %d has finished.\n", getpid());
			exit(0);
		}
	}
}
