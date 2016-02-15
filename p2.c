//imports

#include <signal.h>
#include <stdio.h>
#include <unistd.h>


int main() {

	int id;
	//Prompt for user or console input for a PID to kill
	printf("Enter a pid: \n");
	scanf("%d", &id);

	//check to see if the PID entered is within this processe's process group
	if(getpgid(id) >= 0) {  
		//if it is, (kill returns a non zero number) then we have authority to kill 
		if(kill(id,4) != 0) {
			printf("You don't have permission to kill %d\n", id);
			//need to return something here to indicate failure
		} else {
			printf("%d has been killed\n", id);
		}
		//return something here to indicate success
		//since we called kill in the if, kill is run. If an error turns up, then we'll catch
		//it with the print, otherwise the process is killed without much indication. 
	} else {
		//if we get here that means 
		printf("Process %d does not exist within killable group\n", id);
	}
}
