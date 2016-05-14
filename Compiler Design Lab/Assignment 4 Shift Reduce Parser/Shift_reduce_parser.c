/*
									Assignment 4
 
		Implement a shift Reduce parser whose Input is a context free Grammer
		and the output is the sequence of productions to be used to reduce 
		to the start symbol 

Compiled By:
Himansu Rathi  12/CS/06
R Om prakash   12/CS/07

*/

#include<stdio.h>
#include<string.h>

char nt[300],handles[300][300],str1[300],stack[600];
int top=-1,lookahead=0;

void push(char a)
{
    stack[++top]=a;
}
void pop()
{
    stack[top]='\0';
    top--;
}

void shift_reduce_parser(int n,char start)
{
    char a;
    int i,k,j,flag,m,fl;
    a=str1[lookahead];
    printf("\n----------BEGIN PARSING STEPS----------\n\n");
    while(a!='\0')
    {
        lookahead++;
        push(a);
        printf("\t\tShift %c into stack\n",a);
        while(1)
        {
            for(i=0;i<n;i++)
            {
                fl=0;
                flag=1;
                for(j=strlen(handles[i])-1,k=top;j>=0&&k>=0;j--,k--)
                {
                    if(handles[i][j]!=stack[k]) flag=0;
                }
                if(flag)
                {
                    for(m=strlen(handles[i]);m>=1;m--)
                    {
                        pop();
                    }
                    push(nt[i]);
                    printf("\t\tReduce by %c->%s\n",nt[i],handles[i]);
                    fl=1;
                    break;
                }
            }
            if(!fl) break;
        }
        a=str1[lookahead];
    }
    if(stack[2]!='\0') printf("\n\nThe string does not belong the the grammar...\n");
    else printf("\n----------String Parsed Successfully-----------\n");
}
int main()
{
    char str[20],filename[20],start;
    int a=0;
    stack[0]='$';top++;
    printf("Enter the string to parsed :");
    gets(str1);
    printf("Enter filename for the set of production\n");
    scanf("%s",filename);
    freopen(filename,"r",stdin);
    gets(str);
    while(str[0]!='\0')
    {
        if(!a) start=str[0];
        nt[a]=str[0];
        strcpy(handles[a],str+3);
        a++;
        gets(str);
    }
    shift_reduce_parser(a,start);
    return 0;
}
