#include <signal.h>
#include <stdio.h>
#include <unistd.h>
int main() {
	int id;
	printf("Enter a pid: \n");
	scanf("%d", &id);
	if(getpgid(id) >= 0) {
		if(kill(id,4) != 0) {
			printf("You don't have permission to kill %d\n", id);
		}
	} else {
		printf("Process %d does not exist within killable group\n", id);
	}
}
