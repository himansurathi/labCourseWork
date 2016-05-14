#include<stdio.h>
#include<netinet/in.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<string.h>
#include<stdlib.h>
int main(void){
int id,new,i,num_one,num_two,l,ss,g,va;
char buff[50];
struct sockaddr_in  address,client_address;
id=socket(AF_INET,SOCK_STREAM,0);


address.sin_family=AF_INET;
address.sin_addr.s_addr=inet_addr("127.0.0.1");

address.sin_port=50054;



if(bind(id,(struct sockaddr *)&address,sizeof(address))<0)
printf("Error \n");


listen(id,5);
while(1){

ss=sizeof(client_address);

new=accept(id,(struct sockaddr *) & client_address,&ss);
if(new<0){
exit(0);}
while(1){
recv(new,buff,50,0);
if(strcmp("#",buff)==0)
break;
printf("Received expression by server is %s\n",buff);
l=strlen(buff);

num_one=0;
i=0;
while(buff[i]!='*'&&buff[i]!='/'&&buff[i]!='+'&&buff[i]!='-'){
num_one=num_one*10+buff[i]-'0';

i++;
}


while(l>i){

char ch=buff[i];
i++;
num_two=0;
while(buff[i]!='*'&&buff[i]!='/'&&buff[i]!='+'&&buff[i]!='-'&&l>i){
num_two=num_two*10+buff[i]-'0';
i++;
}

if(ch=='*'){
num_one=num_one*num_two;}

if(ch=='/'){
num_one=num_one/num_two;}
if(ch=='+'){
num_one=num_one+num_two;}
if(ch=='-'){
num_one=num_one-num_two;}

}
i=0;
while(num_one>0){
buff[i]='0'+num_one%10;
i++;
num_one=num_one/10;}
buff[i]='\0';

send(new,buff,sizeof(buff),0);
//sleep(10);
}
}
close(id);}
