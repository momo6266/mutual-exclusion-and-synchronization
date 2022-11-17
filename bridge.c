// C program to demonstrate creating 2 threads
#include <stdio.h> 
#include <pthread.h> 
#include <unistd.h> 
  
void* thread(void* arg) 
{ 
	int *t_number = ((int *)arg);	//cast the argument(thread number) as type int
	
	//To show the line of code before critical section
	printf("\n Traffic %d Entered the bridge\n", *t_number); 
  
  	//critical section 
	printf("\n Traffic %d is flowing 10s\n", *t_number);
	//make the thread sleeps 10s to simulate traffic flows. The thread will go to Blocked state.
	sleep(10); 
      
	//To show the line of code after critical section 
	printf("\n Traffic %d Just Exiting the bridge...\n", *t_number); 
} 

int main() 
{ 
	//these values are used to identify thread number
	int thread0_id=0, thread1_id=1; 
	
	pthread_t t1,t2; 
	
	//create two threads, passing thread number as the forth argument
	pthread_create(&t1,NULL,thread,&thread0_id); 
	pthread_create(&t2,NULL,thread,&thread1_id); 

	//join two threads after they finished running
	pthread_join(t1,NULL); 
	pthread_join(t2,NULL); 

	return 0; 
} 