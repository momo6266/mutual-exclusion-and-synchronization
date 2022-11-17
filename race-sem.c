// C program to demonstrate thread synchronization using semaphore
#include <stdio.h> 
#include <pthread.h> 
#include <unistd.h>
#include <semaphore.h> 

sem_t s0;   //semaphore variable called s0 is declared

int x = 2, y = 3;	//initial values of global variables x and y 

//thread t0 does the following
void* thread_t0(void* arg)		
{ 
	sem_wait(&s0);	//Semaphore Wait
	x = x + y;
} 

//thread t1 does the following
void* thread_t1(void* arg)		
{ 
	y = x * y;
	sem_post(&s0); //Semaphore Signal. Note: it is called SemSignal in your lecture notes
} 

int main() 
{ 
	//these values are used to identify thread number
	int thread0_id=0, thread1_id=1; 

	//initialize semaphore mutex value as 0 (3rd argument)
	sem_init(&s0, 0, 0);

	//intialize two variables type pthread_t called t0 and t1
	pthread_t t0,t1; 
	
	//create two threads, passing thread number as the forth argument
	pthread_create(&t0,NULL,thread_t0,&thread0_id); 
	pthread_create(&t1,NULL,thread_t1,&thread1_id); 

	//join two threads after they finished running
	pthread_join(t0,NULL); 
	pthread_join(t1,NULL); 
	
	//print the value of x and y after threads finished running
	printf("The final value of x is %d\n", x);
	printf("The final value of y is %d\n", y);

	//destroy the semaphore after finished using it
	sem_destroy(&s0);

	return 0; 
} 
