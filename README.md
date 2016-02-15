## 377-lab1
# Authors: Ben Cheung, Cheyan Setayesh, Zach Milrod
# 2/16/15




### P1 Documentation

#### To run P1:
 ` gcc -o p1 p1.c `


> This one is fairly simple. We fork once, and then within the child process, we fork again and print within the grandchild's
> process. we make sure the child and the root process (the two process's with forked children) wait for their child to finish
> before executing so that we get the desired order of print statements. Depending on the scheduler, there's a chance that it
> may schedule the parent process before the child, and if we don't explicitly wait for the child, then the parents may finish 
> before the children in this manor. That's why its important that in the parent's process, we explcitly wait for the child to
> finish before prinitng and exiting. 


### P2 Documentation

#### To run P2:
 ` gcc -o p2 p2.c `
