/*
 * Roll Number = 12/CS/06,12/CS/07
 * Name = Himansu Rathi, R Om Prakash
 * Group No = 3 
*/


#include <stdlib.h> 
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <sys/wait.h>

#define LIMIT 50
#define NUM_ELEM 20   
#define SEM_MUTEX 0
#define SEM_EMPTY 1
#define SEM_FULL 2

int semID, shmID, status,*shmPtr,m,n,i;
union semun
{
    int val;
    struct semid_ds *buf;
    ushort *array;
} seminfo;
  
struct sembuf WaitMutex={SEM_MUTEX, -1, 0};
struct sembuf SignalMutex={SEM_MUTEX, 1, 0};
struct sembuf WaitEmpty={SEM_EMPTY, -1, 0};
struct sembuf SignalEmpty={SEM_EMPTY, 1, 0};
struct sembuf WaitFull={SEM_FULL, -1, 0};
struct sembuf SignalFull={SEM_FULL, 1, 0};

struct shmid_ds shminfo;

void producer();
void consumer();

int main()
{
      printf("Enter no.of producers ");
      scanf("%d",&m);
      printf("Enter no.of consumers ");
      scanf("%d",&n);
    
  semID=semget(IPC_PRIVATE, 3, 0666 | IPC_CREAT);
  seminfo.val=1;
  semctl(semID, SEM_MUTEX, SETVAL, seminfo);
  seminfo.val=NUM_ELEM;
  semctl(semID, SEM_EMPTY, SETVAL, seminfo);
  seminfo.val=0;
  semctl(semID, SEM_FULL, SETVAL, seminfo);
  shmID=shmget(IPC_PRIVATE, NUM_ELEM+3, 0666 | IPC_CREAT);
  shmPtr=(int *)shmat(shmID, 0, SHM_R);
  *shmPtr=0;
  *(shmPtr+1)=0;
  *(shmPtr+2)=0;
  for(i=0;i<m;i++)
  {
        if(fork()==0)
        {
               producer();
               exit(0);
        }
  }
  for(i=0;i<n;i++)
  {
        if(fork()==0)
        {
               consumer();
               exit(0);
        }
  }  
  while(wait(&status)>0);
  return 0;
}

void producer()
{
     int p;
    shmPtr=(int *)shmat(shmID, 0, SHM_W);
    
    for(i=1;i<=LIMIT;i++)
    {
        semop(semID, &WaitEmpty, 1);
        semop(semID, &WaitMutex, 1);
        p=*(shmPtr+1);
        *(shmPtr+3 + (p%NUM_ELEM))=i;
        *(shmPtr+1)+=1;
        semop(semID, &SignalMutex, 1);
        semop(semID, &SignalFull, 1);
    }
}
void consumer()
{

     int p;
    shmPtr=(int *)shmat(shmID, 0, SHM_R);
    while(1)
    {
        semop(semID, &WaitFull, 1);
        semop(semID, &WaitMutex, 1);
        p=*(shmPtr+2);
        i=*(shmPtr+3 + (p%NUM_ELEM));
        *(shmPtr+2)+=1;
        *shmPtr+=i;
        
        if(*(shmPtr+2)>=m*LIMIT)
        {
        	if(*(shmPtr+2)==m*LIMIT)
        		printf("Sum : %d\n",*shmPtr);
        	*(shmPtr+2)+=1;
    		shmctl(shmID, IPC_RMID, &shminfo);
    		semctl(semID, SEM_MUTEX, IPC_RMID, seminfo);
             exit(0);
       }

        semop(semID, &SignalMutex, 1);

        semop(semID, &SignalEmpty, 1);
    }
}
