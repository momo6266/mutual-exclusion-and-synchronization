#include <stdio.h> 
#include <pthread.h> 
#include <semaphore.h> 
#include <unistd.h> 

sem_t mutex;   //semaphore variable called mutex is declared
int green_1 = 1, green_2 = 0, loop = 0;

//Switch green light between two thread
void switch_green()
{
	if (green_1 == 1)
	{
		green_1 = 0;
		green_2 = 1;
	}

	else if (green_2 == 1)
	{
		green_1 = 1;
		green_2 = 0;
	}
}

void* thread_t0(void* arg)
{
	int* t_number = ((int*)arg);	//cast the argument(thread number) as type int

	if (green_1 == 0)
	{
		//wait 
		sem_wait(&mutex);

	}

	if (green_1 == 1)
	{
		printf("\n Traffic %d Entered the bridge\n", *t_number);

		//critical section 
		printf("\n Traffic %d is flowing 10s\n", *t_number);
		sleep(10);

		//signal 
		printf("\n Traffic %d Just Exiting the bridge...\n", *t_number);

		switch_green();

		sem_post(&mutex); //this represents SemSignal

	}
	
	
}

void* thread_t1(void* arg)
{
	int* t_number = ((int*)arg);	//cast the argument(thread number) as type int

	if (green_2 == 0)
	{
		//wait 
		sem_wait(&mutex);

	}


	if (green_2 = 1)
	{
		printf("\n Traffic %d Entered the bridge\n", *t_number);

		//critical section 
		printf("\n Traffic %d is flowing 10s\n", *t_number);
		sleep(10);

		//signal 
		printf("\n Traffic %d Just Exiting the bridge...\n", *t_number);

		switch_green();

		sem_post(&mutex); //this represents SemSignal
	}

}

int main()
{
	//Infinite loop
	while (loop == 0)
	{
		//these values are used to identify thread number
		int thread0_id = 0, thread1_id = 1;

		//initialize semaphore mutex value as 1 (3rd argument)
		sem_init(&mutex, 0, 0);

		pthread_t t1, t2;
	
		//create two threads, passing thread number as the forth argument
		pthread_create(&t1, NULL, thread_t0, &thread0_id);
		pthread_create(&t2, NULL, thread_t1, &thread1_id);

		//join two threads after they finished running
		pthread_join(t1, NULL);
		pthread_join(t2, NULL);

		//destroy the semaphore after finished using it
		sem_destroy(&mutex);

	}

	return 0;
}