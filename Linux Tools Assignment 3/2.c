//Ques-2.Write a program where thread cancel itself.(use pthread_cancel())

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>


void *th(void *thrdId);




int main(void)
{
	pthread_t tid;
	int s;
	
	printf("Creating a thread\n");
	
	pthread_create(&tid, NULL, th, NULL);		
	
	printf("thread id %ld\n", tid);
		
	
	sleep(3);	
	
	printf("Cancelling thread .....\n");
	
	s = pthread_cancel(tid);
	
	printf("Thread cancelled.....\n");
	
	
	return 0;
}



void* th(void *thrdId)
{
	printf("\ncallThread() function called by thread_id 'tid1' in execution....\n\n");
	while(1);		//infinite loop
}

