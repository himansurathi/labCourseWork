/*
 * Roll Number = 12/CS/06,12/CS/07
 * Name = Himansu Rathi, R Om Prakash
 * Group No = 3 
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/ipc.h>
unsigned long long int square(char* p)
{
	unsigned long long int q=atoi(p);
	q=q*q;
	return q;
}

int main(int argc,char *argv[])
{
	
	char *arglist[6],process_name[100],string[100];
	int p=0,i;
	unsigned long long int res=0;
	printf("Child id = %d ,Parent id= %d",getpid(),getppid());
	//Call square if Command Line Arguments Present
	if(argc>=2)
	   {
		 res=square(argv[1]);
		 printf(",Process Name= square\n");
	   }
	else
	   {
		 printf("Insufficient Arguments");
		 exit(0);
	   }
	int start=atoi(argv[2]);
	int end=atoi(argv[3]);
	strcpy(string,argv[4]);
	for(i=start;i<=end;i++)
	{
	  if(string[i]==' ')
	  {
		 //Each process has name,input number,start and end index of input string ,new string followed by NULL
		 //if process is twice call twice process using execvp
		 process_name[p]='\0';
		 if(!strcmp(process_name,"twice"))
		  {
			arglist[0] = (char *)malloc(8*sizeof(char)); 
			strcpy(arglist[0],"./twice");
			arglist[1] = (char *)malloc(100*sizeof(char));
			sprintf(arglist[1],"%llu",res);
			arglist[2]=  (char *)malloc(10*sizeof(char)); 
			sprintf(arglist[2],"%d",i); 
			arglist[3]=  (char *)malloc(10*sizeof(char)); 
			sprintf(arglist[3],"%d",end); 
		    arglist[4]=  (char *)malloc(end*sizeof(char)); 
			strcpy(arglist[4],string);
		    arglist[5] = NULL;
			execvp("./twice",arglist);
			printf("\nThis statement is not executed if execvp succeeds.\n");
		  }
		 //if process is square call square process using execvp
		  else if(!strcmp(process_name,"square"))
		  {
			arglist[0] = (char *)malloc(8*sizeof(char)); 
			strcpy(arglist[0],"./square");
			arglist[1] = (char *)malloc(100*sizeof(char));
			sprintf(arglist[1],"%llu",res);
			arglist[2]=  (char *)malloc(10*sizeof(char)); 
			sprintf(arglist[2],"%d",i); 
			arglist[3]=  (char *)malloc(10*sizeof(char)); 
			sprintf(arglist[3],"%d",end); 
		    arglist[4]=  (char *)malloc(end*sizeof(char)); 
			strcpy(arglist[4],string);
		    arglist[5] = NULL;
			execvp("./square",arglist);
			printf("\nThis statement is not executed if execvp succeeds.\n");
		  }
	     //if process is half call half process using execvp
		else if(!strcmp(process_name,"half"))
		  {
			arglist[0] = (char *)malloc(8*sizeof(char)); 
			strcpy(arglist[0],"./half");
			arglist[1] = (char *)malloc(100*sizeof(char));
			sprintf(arglist[1],"%llu",res);
			arglist[2]=  (char *)malloc(10*sizeof(char)); 
			sprintf(arglist[2],"%d",i); 
			arglist[3]=  (char *)malloc(10*sizeof(char)); 
			sprintf(arglist[3],"%d",end); 
		    arglist[4]=  (char *)malloc(end*sizeof(char)); 
			strcpy(arglist[4],string);
		    arglist[5] = NULL;
			execvp("./half",arglist);
			printf("\nThis statement is not executed if execvp succeeds.\n");
		  }
		  //if process is unknown
 		else if(strlen(process_name))
		 {
        	  //Stores the name of process
			  printf("Error! No such %s Process Exist",process_name);
			  exit(0);
		 }

	   }
	 else
	  {
		//Stores the name of process
		process_name[p]=string[i];
		p++;
	  }
  }
	printf("\nFinal Result is %llu",res);
	return 0;
}
	
