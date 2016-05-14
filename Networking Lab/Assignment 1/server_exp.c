
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include<stdlib.h>

char buf[100];  
int arr[100];
char op[100];
main()
{
      int sockfd, newsockfd; 
      int clilen;
      struct sockaddr_in cli_addr, serv_addr;
      int i;
              
      if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
            printf("Cannot create socket\n");
      exit(0);
}
serv_addr.sin_family          = AF_INET;
serv_addr.sin_addr.s_addr     = inet_addr("127.0.0.1");
serv_addr.sin_port            = htons(6000);

if (bind(sockfd, (struct sockaddr *) &serv_addr,
                        sizeof(serv_addr)) < 0) {
      printf("Unable to bind local address\n");
      exit(0);
}
listen(sockfd, 5); 
while (1) {

      clilen = sizeof(cli_addr);
      newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr,
                        &clilen) ;
      if (newsockfd < 0) {
            printf("Accept error\n");
            exit(0);
      }
    if (fork() == 0) {
     int i,j,s,len;
s=0;
          close(sockfd); 
          for(i=0; i < 100; i++) buf[i] = '\0';        
          send(newsockfd, buf, strlen(buf) + 1, 0);
          recv(newsockfd, buf, 100, 0); 
          printf("Expression received=%s\n", buf);
          len=strlen(buf);
          i=0;
          j=0;
          while(i<len)
          {
                if(i==len-1){
                s=s*10+(buf[i]-'0');
		arr[j]=s;
                j++;
                }
                else if(buf[i]!='+' && buf[i]!='*' && buf[i]!='-' && buf[i]!='/'){
		s=s*10+(buf[i]-'0');
                }              
                else{
		arr[j]=s;
                op[j]=buf[i];
		j++;
		s=0;
                }
		i++;
           }
          printf("%d ",arr[0]);
          for(i=0;i<j;i++)
          {
            printf("%d ",arr[i+1]);
            printf("%c ",op[i]);
           }
          
          close(newsockfd);
          exit(0);
    }
    close(newsockfd);
  }
}
 

