//Question:4. Write a program where pthread task displays the thread id and also prints the calling process pid.

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<pthread.h>
#include<sys/types.h>

pthread_t tid1;



void* thread(void *arg);




int main(void)
{
	int ret;
	
	ret = pthread_create(&tid1, NULL, thread, NULL);			//thread creation
	
	if(ret)
	{
		printf("not created\n");
	}
	
	else
	{
		printf("thread created\n");
		
	}
	
	pthread_join(tid1, NULL);
	
	printf("\nExiting main process\n");
	
	return 0;
}



void* thread(void *arg)
{
	printf("\nnewly created thread in execution\n");
	printf("pthread id : %lu\nCalling Process id : %d\n", pthread_self(), getpid());
	
	return NULL;
}
