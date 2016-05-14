/*
 * Roll Number = 12/CS/06,12/CS/07
 * Name = Himansu Rathi, R Om Prakash
 * Group No = 3 
*/

#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#define MSGSIZE 256
#define PERMS 0666
struct message {
	long int mtype;
	char mtext[MSGSIZE];
};
int main () 
{
	time_t t;
	static int up_id=-1,down_id=-1;
	int i=0;
	struct message *sbuffer,*rbuffer;
	key_t inkey1,inkey2;
	inkey1=ftok("inputfile1.txt",33);
	inkey2=ftok("inputfile2.txt",34);
	if((up_id=msgget(inkey1,PERMS|IPC_CREAT))<0)
	{
		perror(" megget "); exit(1);
	}
	if((down_id=msgget(inkey2,PERMS|IPC_CREAT))<0)
	{
		perror(" megget "); exit(1);
	}
	while(1)
	{
		i=0;
		rbuffer=(struct message*)malloc(sizeof(struct message));
		sbuffer=(struct message*)malloc(sizeof(struct message));
		if(msgrcv(up_id,rbuffer,MSGSIZE,0,0)<0){
			perror(" msgrcv "); exit(1);
		}
		if(strcmp(rbuffer->mtext,"Quit")==0)
		{
			exit(0);
		}
		time(&t);
		printf(" Msg received at time : %s ",ctime(&t));
		//printf(" Received message : %s \n",rbuf->mtext);
		while(rbuffer->mtext[i]!='\0')
		{	
			if(rbuffer->mtext[i]>=65 && rbuffer->mtext[i]<=90)
				sbuffer->mtext[i]=rbuffer->mtext[i]+32;
			else if(rbuffer->mtext[i]>=97 && rbuffer->mtext[i]<=122)
				sbuffer->mtext[i]=rbuffer->mtext[i]-32;
			else
				sbuffer->mtext[i]=rbuffer->mtext[i];
			i++;
		}
		sbuffer->mtext[i]='\0';
		sbuffer->mtype=rbuffer->mtype;
		if(msgsnd(down_id,sbuffer,strlen(sbuffer->mtext),0)<0){
			perror(" msgsnd "); exit(1);
		}
		printf(" Sent message : %s \n\n",sbuffer->mtext);
		free(rbuffer);
		free(sbuffer);
	}
}
