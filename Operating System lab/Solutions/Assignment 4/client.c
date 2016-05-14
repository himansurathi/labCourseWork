/*
 * Roll Number = 12/CS/06,12/CS/07
 * Name = Himansu Rathi, R Om Prakash
 * Group No = 3 
*/

#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MSGSIZE 256
#define PERMS 0666
struct msg {
	long int mtype;
	char mtext[MSGSIZE];
};
int main()
{
	static int up_id=-1,down_id=-1;
	struct msg *sbuffer,*rbuffer; 
	key_t inkey1,inkey2;
	rbuffer=(struct msg*)malloc(sizeof(struct msg));
	sbuffer=(struct msg*)malloc(sizeof(struct msg));
	inkey1=ftok("inputfile1.txt",33);
	inkey2=ftok("inputfile2.txt",34);
	if((up_id=msgget(inkey1,PERMS))<0){
		perror(" megget "); exit(1);
	}
	if((down_id=msgget(inkey2,PERMS))<0){
		perror(" megget "); exit(1);
	}
	printf(" Insert message to send to server: ");
	scanf("%[^\n]s",sbuffer->mtext);
	sbuffer->mtype=getpid();
	if(msgsnd(up_id,sbuffer,strlen(sbuffer->mtext),0)<0){
		perror(" msgsnd "); exit(1) ;
	}
	if(strcmp(sbuffer->mtext,"Quit")==0)
	{
		printf("Thank You!!!");
		return 0;
	}
	if(msgrcv(down_id,rbuffer,MSGSIZE,sbuffer->mtype,0)<0){
		perror(" msgrcv "); exit(1) ;
	}
	printf(" Processed msg from server: %s\n",rbuffer->mtext);
	free(rbuffer);
	free(sbuffer);
	return 0;
}
