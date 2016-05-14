#include<string.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<stdlib.h>
int main(void){
int id,length;
char buff[30];
char buf[50];

id=socket(AF_INET,SOCK_STREAM,0);
struct sockaddr_in address;
address.sin_family=AF_INET;
address.sin_addr.s_addr=inet_addr("127.0.0.1");

address.sin_port=50054;
int a;
connect(id,(struct sockaddr *)&address,sizeof(address));
while(1){


printf("Enter value of a positive if expression have to give \n");
scanf("%d",&a);

if(a<0){
buff[0]='#';
buff[1]='\0';
send(id,buff,sizeof(buff),0);
printf("string is %s\n",buff);
break;}

printf("Enter expression ");
scanf("%s",buff);
send(id,buff,sizeof(buff),0);

recv(id,buf,50,0);
length=strlen(buf);
printf("Answer received by client is = ");
while(length>0){
printf("%c",buf[length-1]);
length--;}
printf("\n");
//close(id);
}
printf("Client is going to close \n");
close(id);}
