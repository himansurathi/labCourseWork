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
int main()
{
	char string[100],w[100],process_name[100],newstring[100],*arglist[6];
	int i,len=0,start=0,p=0,flag=0;
	//Input the string
	printf("Enter the combination of programs to be used\n");
	scanf("%[^\n]s",string);
	//Extract the input number from string
	len=strlen(string)-1;
	for(i=len;i>=0;i--)
	  {
		  if(string[i]!=' ' )
		  {
			  if(string[i]>='0' && string[i]<='9')
				len--;
			  else 
			    {
				  flag=1;
				  break;
				}
		  }
		  else
		   break;
      }
    //Check all Invalid cases of Input
   if(i==-1 || flag==1 || len==strlen(string)-1)
      {
		  printf("Insufficient Arguments");
		  exit(0);
	  }
	//Newstring is the same as old string excluding input number
      for(i=0;i<=len;i++)
       newstring[start++]=string[i];
      newstring[start]='\0';
      start=0;
     //w contains our input number
      for(i=len+1;i<strlen(string);i++)
        {
			w[start++]=string[i];
		}
      w[start]='\0';
   for(i=0;i<=len;i++)
	{
	  if(string[i]==' ')
	  {
		 process_name[p]='\0';
		 //Each process has name,input number,start and end index of input string ,new string followed by NULL
		 //if process is twice call twice process using execvp
		 if(!strcmp(process_name,"twice"))
		  {
			arglist[0] = (char *)malloc(8*sizeof(char)); 
			strcpy(arglist[0],"./twice");
			arglist[1] = (char *)malloc((start+1)*sizeof(char));
			strcpy(arglist[1],w);
			arglist[2]=  (char *)malloc(10*sizeof(char)); 
			sprintf(arglist[2],"%d",i); 
			arglist[3]=  (char *)malloc(10*sizeof(char)); 
			sprintf(arglist[3],"%d",len); 
			arglist[4]=  (char *)malloc(len*sizeof(char)); 
			strcpy(arglist[4],newstring);
		    arglist[5] = NULL;
			execvp("./twice",arglist);
			printf("This statement is not executed if execvp succeeds.\n");
		  }
		 //if process is square call square process using execvp
		  else if(!strcmp(process_name,"square"))
		  {
			arglist[0] = (char *)malloc(8*sizeof(char)); 
			strcpy(arglist[0],"./square");
			arglist[1] = (char *)malloc((start+1)*sizeof(char));
			strcpy(arglist[1],w);
			arglist[2]=  (char *)malloc(10*sizeof(char)); 
			sprintf(arglist[2],"%d",i); 
			arglist[3]=  (char *)malloc(10*sizeof(char)); 
			sprintf(arglist[3],"%d",len); 
			arglist[4]=  (char *)malloc(len*sizeof(char)); 
			strcpy(arglist[4],newstring);
		    arglist[5] = NULL;
			execvp("./square",arglist);
			printf("This statement is not executed if execvp succeeds.\n");

		  }
         //if process is half call half process using execvp
		  else if(!strcmp(process_name,"half"))
		  {
 			arglist[0] = (char *)malloc(8*sizeof(char)); 
			strcpy(arglist[0],"./square");
			arglist[1] = (char *)malloc((start+1)*sizeof(char));
			strcpy(arglist[1],w);
			arglist[2]=  (char *)malloc(10*sizeof(char)); 
			sprintf(arglist[2],"%d",i); 
			arglist[3]=  (char *)malloc(10*sizeof(char)); 
			sprintf(arglist[3],"%d",len); 
			arglist[4]=  (char *)malloc(len*sizeof(char)); 
			strcpy(arglist[4],newstring);
		    arglist[5] = NULL;
			execvp("./half",arglist);
			printf("This statement is not executed if execvp succeeds.\n");
		  }
		  //if process is unknown
  		else if(strlen(process_name))
		 {
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
  return 0;
}
