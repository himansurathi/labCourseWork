/*
 * Roll Number = 12/CS/06,12/CS/07
 * Name = Himansu Rathi, R Om Prakash
 * Group No = 3 
*/

#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
int main()
{
  int n,arr[100],current_id1,current_id2,pid1,pid2,i,sodd=0,seven=0,status,ppid1,ppid2;   
  printf("Enter the number of elements in an array\n");
  scanf("%d",&n);
  printf("Enter the elements in the array\n");
  for(i=0;i<n;i++)
  scanf("%d",&arr[i]);
  if((pid1=fork())==0)
   {
       ppid1=getppid();
       current_id1=getpid();
       printf("Child 1 process id =%d Parent id of child 1 =%d\n",current_id1,ppid1);
       for(i=0;i<n;i++)
         if(arr[i]%2!=0)
           sodd+=arr[i];
       sleep(1);
       printf("Sum of Odd Numbers =%d\n",sodd);
    }
  else
   {
	  if((pid2=fork())==0)
      {
		 ppid2=getppid();
		 current_id2=getpid();
		 printf("Child 2 process id =%d Parent id of child 2 =%d\n",current_id2,ppid2);
		 for(i=0;i<n;i++)
			 if(arr[i]%2==0)
         seven+=arr[i];
		 sleep(1);
		 printf("Sum of Even Numbers =%d\n",seven);
	   }
	   else
		{

		  waitpid(pid1,&status,0);
		  waitpid(pid2,&status,0);
		  printf("Parent process id =%d\n",getpid());
		}
   }
  return 0;
}   
     
