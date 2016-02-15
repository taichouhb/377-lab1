## 377-lab1
# Authors: Ben Cheung, Cheyan Setayesh, Zach Milrod
# 2/16/15




### P1 Documentation

#### To run P1:
 ` gcc -o p1 p1.c `


>This one is fairly simple. We fork once, and then within the child process, we fork again and print within the grandchild's process. we make sure the child and the root process (the two process' with forked children) wait for their child to finish before executing so that we get the desired order of print statements. Depending on the scheduler, there's a chance that it may schedule the parent process before the child, and if we don't explicitly wait for the child, then the parents may finish before the children in this manner. That's why it’s important that in the parent's process, we explicitly wait for the child to finish before printing and exiting.


### P2 Documentation

#### To run P2:
 ` gcc -o p2 p2.c `

>This program starts off by prompting the user to enter the process ID for which process to kill. Once it has obtained the ID, it checks to see if the current process is in the same process group as the process to be killed. If it is not within the same group, the process does not have the privilege to kill that process where a message explaining that is printed and returns without doing anything else. If the process and the process to be killed are within the same process group, meaning the process has the right to kill the process to be killed, it then performs the kill function with the user entered ID. If kill returns 0, the kill command was successful and a line is printed stating the success. If kill returns anything besides 0, a line is printed to the console stating the failure and the number that is returned from the kill function.


### P3 Batch Shell Documentation

#### To run P2:
 ` gcc -o batch-shell batch-shell.c `

>The program is a shell that reads in the standard in buffer and attempts to run the space delimited text as programs in their own child processes in FIFO order and waits for each line of programs to finish. The program indicates that it is prepared to take in text when the cursor is preceded by “batch-shell> “ in the same line. When running a program, each program is forked into their own child process, the process ID is printed then the process image is replaced when executing the program with execlp. The currently executing program has full control of stdio and prints and reads as if it were normally running through the plain terminal.The batch shell continuously runs in a while loop unless the user types in “exit”.

