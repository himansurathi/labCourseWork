/*
Compiler Design
Assignment 3
Himansu Rathi,R Om prakash
*/

#include<stdio.h>
#include<ctype.h>
#include<limits.h>
#include<string.h>
#define MAX_TOKENS 70
#define MAX_INPUT 500

/*different accepted tokens */
char *keywords[]= {"auto","extern","sizeof","break","float","static","case",
					"for","struct","char","goto","switch","const","if","typedef",
					"continue","int","union","default","long","unsigned","do",
					"register","void","return","double","volatile","else","short",
	      			"while","enum","signed"};
char *relational_op[]= {"<",">","<=",">=","==","!="};
char *arithmetic_op[]= {"+","-","*","/","%"};
char *conditional_op[]= {"&&","||","!"};
char *assignment_op[]= {"="};
char *incdec_op[]= {"++","--"};
char *delimiter[]= {"{","}","(",")","[","]"};

/*structure for indivisual token */
typedef struct token
{
    char name[30];
    int code;
    unsigned int ptr[100];
    int occur;
} token;
token st[MAX_TOKENS];

/*Symbol Table valid insertion*/
void symbol_table()
{
    int k,j,len,code=0;
    k=0;
    /*valid keyword*/
    len=sizeof(keywords)/sizeof(*keywords);
    while(k<len)
    {
        strcpy(st[k].name,keywords[k]);
        st[k].code=(k+1);
        st[k].ptr[0]=-1;
        st[k].occur=0;
        k++;
    }

    j=k;
    k=0;
    /*valid relational operator*/
    len=sizeof(relational_op)/sizeof(*relational_op);
    while(k<len)
    {
        strcpy(st[j].name,relational_op[k]);
        st[j].code=32;
        st[j].ptr[0]=(k+1);
        st[j].occur=0;
        k++;
        j++;
    }
    k=0;
    /*valid arithmetic operator*/
    len=sizeof(arithmetic_op)/sizeof(*arithmetic_op);
    while(k<len)
    {
        strcpy(st[j].name,arithmetic_op[k]);
        st[j].code=38;
        st[j].ptr[0]=(k+1);
        st[j].occur=0;
        k++;
        j++;
    }
    k=0;
    /*valid conditional operator*/
    len=sizeof(conditional_op)/sizeof(*conditional_op);
    while(k<len)
    {
        strcpy(st[j].name,conditional_op[k]);
        st[j].code=43;
        st[j].ptr[0]=(k+1);
        st[j].occur=0;
        k++;
        j++;
    }
    k=0;
    /*valid assignment operator*/
    len=sizeof(assignment_op)/sizeof(*assignment_op);
    while(k<len)
    {
        strcpy(st[j].name,assignment_op[k]);
        st[j].code=46;
        st[j].ptr[0]=(k+1);
        st[j].occur=0;
        k++;
        j++;
    }
    k=0;
    /*valid increment-decrement operator*/
    len=sizeof(incdec_op)/sizeof(*incdec_op);
    while(k<len)
    {
        strcpy(st[j].name,incdec_op[k]);
        st[j].code=47;
        st[j].ptr[0]=(k+1);
        st[j].occur=0;
        k++;
        j++;
    }
    k=0;
    /*valid Delimiter*/
    len=sizeof(delimiter)/sizeof(*delimiter);
    while(k<len)
    {
        strcpy(st[j].name,delimiter[k]);
        st[j].code=49;
        st[j].ptr[0]=(k+1);
        st[j].occur=0;
        k++;
        j++;
    }
}

void print_stm()
{
    int i=0,j;
    printf("\n------------------------------------------------\nSYMBOL TABLE\n");
    printf("\n%50s \t%s \t%s\n","TYPE","NAME","CODE","POINTER");
    for(i=0; i<MAX_TOKENS; i++)
    {
        if(st[i].code!=0 && st[i].occur>=1)
            {
			  if(st[i].code<32)
			  printf("\t   KEYWORD");
			  else if(st[i].code<38)
			  printf("RELATIONAL OPERATOR");
			  else if(st[i].code<43)
			  printf("ARITHMETIC OPERATOR");
			  else if(st[i].code<46)
			  printf("CONDITIONAL OPERATOR");
			  else if(st[i].code<47)
			  printf("ASSIGNMENT OPERATOR");
			  else if(st[i].code<49)
			  printf("INC/DEC OPERATOR");
			  else if(st[i].code<55)
			  printf("\t   DELIMITER");
			  else if(st[i].code<56)
			  printf("\t   CONSTANT");
			  else if(st[i].code<57)
			  printf("\t   IDENTIFIER");
			  
              printf("%20s \t%d \t%d",st[i].name,st[i].code,st[i].ptr[0]);
              for(j=1;j<st[i].occur;j++)
                  printf(",%d",st[i].ptr[j]);
              printf("\n");
            }
    }
}
/* Read from File*/
void fileread(FILE *f, char *input)
{
    char c;
    int j=0;
    do
    {
        c=fgetc(f);
        input[j++]=c;
    }
    while(c!=EOF);
    input[j]='\0';
}
/* print input file*/
void input_print(char *in)
{
    printf("Input file:\n");
    printf("\n%s",in);
}
/* For other symbols as delimiter*/
void other(char *input)
{
int i,j,k=0,flag=0,count=0;
char temp[100];
  for(i=0;i<strlen(input);i++)
    {
       /* Non Alpha Numeric Characters*/
      if((!isalnum(input[i])) || (count==1))
       {
       if(input[i]=='+' || input[i]=='-' || input[i]=='>' || input[i]=='<' || input[i]=='=' || input[i]=='!'|| input[i]=='&' ||input[i]=='|' )
       {
           //for +,-,<,>
           count++;
           // for <=,>=,==,&&,!=,++
           temp[k++]=input[i];
           if(count<2)
            continue;
       }
       else if(count!=1)
       {
           temp[k++]=input[i];
           temp[k]='\0';
       }
           for(j=0;j<56;j++)
           {
               /*compare with existing structure*/
               if(strcmp(st[j].name,temp)==0)
               {
                 st[j].occur=1;
                 break;
               }
           }
          if(j==56 && (!(strcmp(temp," ")==0 || strcmp(temp,"\n")==0 || strcmp(temp,"\t")==0)))
          {
            /* invalid tokens*/
            strcpy(st[58].name,"INVALID");
            st[58].ptr[st[58].occur]=&st[58].ptr[st[58].occur];
            st[58].occur++;
          }
          temp[0]='\0' ;
          k=0;
          count=0;
        }
    }

}
/*Parsing Lexical Analyzer*/
void lexical_analyzer(char* input)
{
    int i=0,temp_i=0,j,k,z,l,flag=0,val=56;
    char c,*temp;
    char delim[]="; =+-*/%^{}!()&|<>,.\"\'\n\t\r";

    for(temp=strtok(input,delim); temp!=NULL; temp=strtok(NULL,delim))
    {
        flag=0;
        /* Checking which keywords are appearing*/
        for(j=0; j<sizeof(keywords)/sizeof(*keywords); j++)
            if(strcmp(temp,keywords[j])==0)
                {
                    st[j].occur=1;
                    flag=1;
                    break;
                }
        if(flag==0)
        {
            //then temp is an identifier and so add to st
            if(isdigit(temp[0]))
                {
                  for(k=1;k<strlen(temp);k++)
                  {
                     if(isdigit(temp[k]))
                          st[56].code=56;
                     else
                          {
                              /*For Invalid characters*/
                            st[58].code=58;
                            flag=1;
                            val=58;
                            break;
                          }
                   }
                   /*For Constants*/
                   if(flag==0)
                       {
                         strcpy(st[56].name,temp);
                         val=56;
                       }
                }
            else
            {
              for(k=0;k<strlen(temp);k++)
              {
                 /*Alpha numeric characters*/
                 if(isalpha(temp[k]))
                      {
                         st[57].code=57;
                         val=57;
                      }
                 else
                      {
                        st[58].code=58;
                        val=58;
                        break;
                      }
               }
            if(flag==0)
            {
              /* add Identifier*/
               strcpy(st[57].name,temp);
               val=57;
            }
            }
            if(flag)
              {
                /*add invalid charcter*/
                strcpy(st[58].name,"INVALID");
                val=58;
              }
              if(!(strcmp(temp," ")==0 || strcmp(temp,"\n")==0 || strcmp(temp,"\t")==0))
              {
                /* both for identifiers and Invalid words*/
                st[val].ptr[st[val].occur]=&st[val].ptr[st[val].occur];
                st[val].occur++;
              }
         }
      }
    }

int main()
{
    char input[MAX_INPUT],filename[50];
 	/*Input file name asked from user*/
 	printf("Enter the file name with.txt extension\n");
	scanf("%s", filename);
    FILE *fp=fopen(filename, "r");
    fileread(fp,input);
    input_print(input);
    /*For Parsing of code to get keywords ,operators and identifiers*/
    symbol_table();
    other(input);
    lexical_analyzer(input);
    /* Printing output symbol table*/
    print_stm();
    return 0;
}
