//Ques-2.Write a program such that parent process create two child processes,such that each child executes a separate task.



#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main()
{
	int pid, pid1, pid2;
	int x,y,z;

	
	pid = fork();
   
	//if fork=0 i.e child process

	if (pid == 0) {


	// This is first child process getpid() gives the process id and getppid() gives the 		parent id of that process.
	printf("child[1] --> pid = %d and ppid = %d",
	getpid(), getppid());
	printf("\nI am First Child\n");
	
	//task to perform date and time fuction
	
	time_t t;   // not a primitive datatype
    	time(&t);
    	printf("Today Date and Time : %s", ctime(&t));
	}

//Second Child
	else {
		pid1 = fork();
		if (pid1 == 0)
		{
			sleep(2);
			printf("\nchild[2] --> pid = %d and ppid = %d", getpid(), getppid());
			printf("\nI am Second Child");
			
			//task to give present files in the directory
			printf("\nFiles in Directory are:\n");
        		execl("/bin/ls","ls", "-l",0);
		}
			

// If value returned from fork() in not zero and >0 that means it is parent process.
			
	        else {
				sleep(3);
				printf("\nparent --> pid = %d\n", getpid());
			}
		}
	

	return 0;
}

