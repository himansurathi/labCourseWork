#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#define CHAR_INT(x) (x-'0')
void process(char exp[],char res[])
{
	int len=strlen(exp);
	for(i=0;i<len;i++)
	{
		if(exp[i]>='0' && exp[i]<='9')
		  number=number*10+CHAR_INT(exp[i]);
		else if(exp[i]='+')
		   {
			 count+=number;
			 number=0;
		   }
		else if(exp[i]='-')
		   {
			 count-=number;
			 number=0;
		   }
		else if(exp[i]='*')
		   {
			 count*=number;
			 number=0;
		   }

	}
}
int main()
{
	int sock,newsock;
	int len_client;
	struct sockaddr_in clien_addr,serv_addr;
	if((sockfd=socket(AF_INET,SOCK_STREAM,0))<0)
	{
		printf("The requested socket could not be created\n");
		exit(0);
	}
	serv_addr.sin_family=AF_INET;
	serv_addr.sin_addr.s_addr=INADDR_ANY;
	serv_addr.sin_port=htons(6666);
	if(bind(sockfd, (struct sockaddr*)&serv_addr,sizeof(serv_addr))<0)
	{
		printf("Unable to bindd local address\n");
		exit(0);
	}
	listen(sockfd,5);
	while(1)
	{
		len_client=sizeof(clien_addr);
		newsock=accept(sockfd,(struct sockaddr *)&clien_addr,&len_client);
		if(newsock<0)
		{
			printf("Accept error\n");
			exit(0);
		}
		strcpy(buf,"Connected to server\n");
		send(newsock,buf,strlen(buf)+1,0);
		for(i=0;i<100;i++)
		buf[i]='\0';
		recv(newsock,buf,100,0);
		printf("The expression you entered is %s\n",buf);
		process(buf,result);
		send(newsock,result,strlen(result)+1,0);	
		close(newsock);
	}
	return 0;
}
