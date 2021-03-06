Shivam Mitra	
Shivam Mitra
SRE at LinkedIn

Follow
Producer-consumer Problem Solution in C using Semaphore and Mutex
 3 minute read
python tutorial

Similar Posts You May Be Interested In:

Reader Writer Problem Code in C
FCFS Scheduling Algorithm Code
Nonpreemptive Priority Scheduling Code
Preemptive Priority Scheduling Code
SJF Scheduling Code
SRTF Scheduling Code
Round Robin Scheduling Code
IMPORTANT

If you or your friends are interested for live classes on youtube for operating system topics which can help you either in interviews, competitive exams like GATE or your college exams, do fill the form and mention your reason. In case, you also need 1-1 meetings for clearing some of your doubts and mentorship, do mark it in the form. Do share this with your friends :)

Form link: https://bit.ly/2LVLWWy

Do subscribe to my youtube channel also for live classes: https://www.youtube.com/c/codophobia

What is Producer-consumer Problem?
The producer and consumer share a fixed-size buffer used as a queue. The producer?s job is to generate data and put this in the buffer. The consumer?s job is to consume the data from this buffer, one at a time.

Problem Statement

How do you make sure that producer doesn?t try to put data in buffer when the buffer is full and consumer doesn?t try to consumer data when the buffer is empty?

When producer tries to put data into the buffer when it is full, it wastes cpu cycles. The same is true for consumer it tries to consumer from an empty buffer. It?s better that they go on sleep in these cases so that the scheduler can schedule another process.



Pseudocode Solution using Semaphore and Mutex
Initialization

Mutex mutex; // Used to provide mutual exclusion for critical section
Semaphore empty = N; // Number of empty slots in buffer
Semaphore full = 0 // Number of slots filled
int in = 0; //index at which producer will put the next data
int out = 0; // index from which the consumer will consume next data
int buffer[N];

 
Producer Code

while(True) {
   // produce an item
   wait(empty); // wait/sleep when there are no empty slots
   wait(mutex);
   buffer[in] = item
   in = (in+1)%buffersize;
   signal(mutex);
   signal(full); // Signal/wake to consumer that buffer has some   data and they can consume now
}
Consumer Code

while(True) {
   wait(full); // wait/sleep when there are no full slots
   wait(mutex);
   item = buffer[out];
   out = (out+1)%buffersize;
   signal(mutex);
   signal(empty); // Signal/wake the producer that buffer slots are emptied and they can produce more
   //consumer the item
}
Solution in C using Semaphore and Mutex
We will be converting the above Pseudocode to actual code in C language. Let?s first have a look at some important data structures we will be using in the code.

One can use include header file and declare a semaphore of type sem_t in c.
Some important methods that can be used with semaphore in c
sem_init -> Initialise the semaphore to some initial value
sem_wait -> Same as wait() operation
sem_post -> Same as Signal() operation
sem_destroy -> Destroy the semaphore to avoid memory leak
One can use include header file and declare a mutex of type pthread_mutex_t in c.
Some important methods that can be used with semaphore in c
pthread_mutex_init -> Initialise the mutex
pthread_mutex_lock() -> Same as wait() operation
pthread_mutex_unlock() -> Same as Signal() operation
pthread_mutex_destroy() -> Destroy the mutex to avoid memory leak
For complete details on the parameters these function takes, do read posix mutex and semaphore

Code github link: https://github.com/codophobia/producer-consumer-problem-solution-in-c


 

 
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <stdio.h>

/*
This program provides a possible solution for producer-consumer problem using mutex and semaphore.
I have used 5 producers and 5 consumers to demonstrate the solution. You can always play with these values.
*/

#define MaxItems 5 // Maximum items a producer can produce or a consumer can consume
#define BufferSize 5 // Size of the buffer

sem_t empty;
sem_t full;
int in = 0;
int out = 0;
int buffer[BufferSize];
pthread_mutex_t mutex;

void *producer(void *pno)
{   
    int item;
    for(int i = 0; i < MaxItems; i++) {
        item = rand(); // Produce an random item
        sem_wait(&empty);
        pthread_mutex_lock(&mutex);
        buffer[in] = item;
        printf("Producer %d: Insert Item %d at %d\n", *((int *)pno),buffer[in],in);
        in = (in+1)%BufferSize;
        pthread_mutex_unlock(&mutex);
        sem_post(&full);
    }
}
void *consumer(void *cno)
{   
    for(int i = 0; i < MaxItems; i++) {
        sem_wait(&full);
        pthread_mutex_lock(&mutex);
        int item = buffer[out];
        printf("Consumer %d: Remove Item %d from %d\n",*((int *)cno),item, out);
        out = (out+1)%BufferSize;
        pthread_mutex_unlock(&mutex);
        sem_post(&empty);
    }
}

int main()
{   

    pthread_t pro[5],con[5];
    pthread_mutex_init(&mutex, NULL);
    sem_init(&empty,0,BufferSize);
    sem_init(&full,0,0);

    int a[5] = {1,2,3,4,5}; //Just used for numbering the producer and consumer

    for(int i = 0; i < 5; i++) {
        pthread_create(&pro[i], NULL, (void *)producer, (void *)&a[i]);
    }
    for(int i = 0; i < 5; i++) {
        pthread_create(&con[i], NULL, (void *)consumer, (void *)&a[i]);
    }

    for(int i = 0; i < 5; i++) {
        pthread_join(pro[i], NULL);
    }
    for(int i = 0; i < 5; i++) {
        pthread_join(con[i], NULL);
    }

    pthread_mutex_destroy(&mutex);
    sem_destroy(&empty);
    sem_destroy(&full);

    return 0;
    
}