/*
 * Roll Number = 12/CS/06,12/CS/07
 * Name = Himansu Rathi, R Om Prakash
 * Group No = 3 
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<signal.h>
 
void childAlarm(int sig)
{
	printf("\nNumeric value of signal SIGALRM is %d\n",sig);
	printf("Child received the signal\n");
	exit(0);
}
void childExit(int sig)
{
	printf("\nNumeric value of signal SIGCHLD is %d\n",sig);
	printf("Parent received the signal\n");
	exit(0);
}
int main ()
{
int pid;
pid = fork();
if (pid) {
//Parent process and pid= child id
signal(SIGCHLD, childExit);	
//If child has terminated or not
sleep(1);
//sleep for one second
kill(pid,SIGALRM);
//Send an alarm to child
while(1)
{
  printf("\nparent waiting\n");
  //Parent is waiting
}
}
else
{
	signal(SIGALRM, childAlarm);
	//Check if Alarm has been set by parent
	while(1)
	{
	  printf("\nchild waiting\n");
	  //Child is waiting
	}

}
return 0;
}
