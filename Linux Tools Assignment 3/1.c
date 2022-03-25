//Ques-1.Write a multithreading program, where threads runs same shared golbal variable of the process between them.

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<pthread.h>

pthread_t tid, tid1;	//variables to store thread id

int x = 10;		//global variable declared


                       //increase globalVar by 15
void* inc(void *arg)
{
	printf("first thread in executions\n");
	x += 15;
	printf(" increment after : %d\n", x);
	
	return NULL;
}


                         //decrease globalVar
void* dec(void *arg)
{
	printf("second thread in executions\n");
	x -= 5;
	printf(" decrement after : %d\n", x);
	
	return NULL;
}
int main(void)
{
	pthread_create(&tid, NULL, inc, NULL);
	pthread_create(&tid1, NULL, dec, NULL);
	
	                           //executing threads
	                           
	pthread_join(tid, NULL);
	pthread_join(tid1, NULL);
	
                               	//returning to parent process
	printf("\nExecuting parent process\n");
	printf("\nExecuting parent process\n");
	printf("\nExecuting parent process\n");
	
	return 0;
}
