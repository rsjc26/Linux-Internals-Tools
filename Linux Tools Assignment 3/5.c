//Question:5 5.Write a program that implements threads synchronization using mutex techniques.
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>


int gx = 10;		//global variable declared

pthread_mutex_t my_mutex;			//creating mutex lock


void* inc(void *arg);
void* dec(void *arg);



void main()
{
	pthread_t tid, tid1;
	
	pthread_mutex_init(&my_mutex, NULL);		//initialize mutex lock
	
	pthread_create(&tid, NULL, inc, NULL);
	pthread_create(&tid1, NULL, dec, NULL);
	
	pthread_join(tid, NULL);
	pthread_join(tid1, NULL);

	printf("global variable is : %d\n", gx);
	
}




//increase globalVar by 15
void* inc(void *arg)
{
	pthread_mutex_lock(&my_mutex);		//apply lock
	
	gx += 15;		//critical section
	
	pthread_mutex_unlock(&my_mutex);	//release lock
	
	printf("increased value = %d\n",gx);
}





//decrease globalVar by 5
void* dec(void *arg)
{
	pthread_mutex_lock(&my_mutex);		//apply lock
	
	gx -= 5;				//critical section

	pthread_mutex_unlock(&my_mutex);	//release lock
	
	printf("decreased value = %d\n",gx);
}
