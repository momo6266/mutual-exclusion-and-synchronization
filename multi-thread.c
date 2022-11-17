// C program to demonstrate a simple multi-threaded process using two threads.
#include <stdio.h> 
#include <pthread.h> 
#include <unistd.h> 

//thread t0 does the following
void* thread_t0(void* arg)		
{ 
	int *t_number = ((int *)arg);	//cast the argument(thread number) as type int
	printf("\nHello world! I am thread number %d\n", *t_number);
}

//thread t1 does the following
void* thread_t1(void* arg)		
{ 
	int *t_number = ((int *)arg);	//cast the argument(thread number) as type int
	printf("\nHello world! I am thread number %d\n", *t_number);
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

	return 0; 
} 
