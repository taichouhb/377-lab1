
//Imports 
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main() {
	//immediately fork
	int c_pid = fork();
	int g_pid; //pointer for grandchild's process ID to be stored at
	if(c_pid == 0) {
		//if we are in child process
		g_pid = fork(); //fork into grandchild process
		if(g_pid == 0) {
			//if we are in grandchild process
			sleep(10); 
			printf("Grandchild process with process id %d has completed.\n", getpid());
		} else {
			//when we are back in child process
			int g_status;
			//the child process needs to wait for the grandchild to finish executing
			if(waitpid(g_pid, &g_status, 0)) {
				printf("Child process with process ID %d has completed.\n", getpid());
				exit(0);
			}
		}
	} else {
		//and now if we are not in child, but are in parent/root process, then this parent 
		//simply waits for the child to finish executing before printing and finishing 
		int c_status;
		if(waitpid(c_pid, &c_status, 0)) {
			printf("Parent process with process ID %d has finished.\n", getpid());
			exit(0);
		}
	}
}
