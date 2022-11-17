// C program to demonstrate race condition using two threads and two shared resources/global var.
#include <stdio.h> 
#include <pthread.h> 
#include <unistd.h> 

int x = 2, y = 3;	//initial values of global variables x and y 

//thread t0 does the following
void* thread_t0(void* arg)		
{ 
	x = x + y;
} 

//thread t1 does the following
void* thread_t1(void* arg)		
{ 
	y = x * y;
} 

int main() 
{ 
	//these values are used to identify thread number
	int thread0_id=0, thread1_id=1; 

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

	return 0; 
} 
