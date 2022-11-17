// C program to demonstrate mutual exclusion using semaphore
// Reference: https://www.geeksforgeeks.org/use-posix-semaphores-c/
#include <stdio.h> 
#include <pthread.h> 
#include <semaphore.h> 
#include <unistd.h> 

sem_t mutex;   //semaphore variable called mutex is declared

void* thread(void* arg) 
{ 
	int *t_number = ((int *)arg);	//cast the argument(thread number) as type int

	//wait 
	sem_wait(&mutex); 
	printf("\n Traffic %d Entered the bridge\n", *t_number); 
  
  	//critical section 
	printf("\n Traffic %d is flowing 10s\n", *t_number);
	sleep(10); 
      
	//signal 
	printf("\n Traffic %d Just Exiting the bridge...\n", *t_number); 
	sem_post(&mutex); //this represents SemSignal
} 

int main() 
{ 
	//these values are used to identify thread number
	int thread0_id=0, thread1_id=1; 

	//initialize semaphore mutex value as 1 (3rd argument)
	sem_init(&mutex, 0, 1); 

	pthread_t t1,t2; 
	
	//create two threads, passing thread number as the forth argument
	pthread_create(&t1,NULL,thread,&thread0_id); 
	pthread_create(&t2,NULL,thread,&thread1_id); 

	//join two threads after they finished running
	pthread_join(t1,NULL); 
	pthread_join(t2,NULL); 

	//destroy the semaphore after finished using it
	sem_destroy(&mutex); 
	return 0; 
} 