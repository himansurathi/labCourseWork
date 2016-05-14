#include<stdio.h>
#include<string.h>
#define SIZE (sizeof(keyword)/sizeof(keyword[0]))
int key(char *p)
{
	// Identify Keywords in our file
	char keyword[][100]={"auto","extern","sizeof","break","float","static","case",
					"for","struct","char","goto","switch","const","if","typedef",
					"continue","int","union","default","long","unsigned","do",
					"register","void","return","double","volatile","else","short",
	      			"while","enum","signed"};
	int i;
    for(i=0;i<SIZE;i++)
    {
		if(!strcmp(keyword[i],p))
		  return 1;
	}
	return 0;
}
int main()
{
    char s[1000],k[1000],identifier[1000][100],keyword[1000][100],filename[20];
	char operator[100],delimiter[100],constant[1000][25];
	printf("Enter the file name with.txt extension\n");
	scanf("%s", filename);
	FILE *fp=fopen(filename, "r");
	int l=0,r=0,o=0,p=0,i,f,j,m=0,n=0;
	//Read file line by line
	while(fgets(s,sizeof(s),fp)!=NULL){
       for(i=0;i<strlen(s);i++)
       {
		   //Check for an Operator
		   if((s[i]=='+')||(s[i]=='%')||(s[i]=='-')||(s[i]=='*')||(s[i]=='<')||(s[i]=='/')||(s[i]=='>')||(s[i]=='='))
		   {
   			 // Check for a pre-existing operator
			   for(j=0;j<n;j++)
				   {
                      if(operator[j]==s[i])
                        break;
					}	
                 if(j==n)
                 {
					 operator[n]=s[i];
					 n++;
				 }
			 }
			// Check for a delimiter
		   if((s[i]==' ')||(s[i]==',')||(s[i]==';')||(s[i]=='{')||(s[i]=='}')||(s[i]=='(')||(s[i]==')')||(s[i]=='[')||(s[i]==']'))
		   {
			   // Check for a pre-existing delimiter
			   	 for(j=0;j<o;j++)
				   {
                      if(delimiter[j]==s[i])
                        break;
					}	
                 if(j==o)
                 {
					 delimiter[o]=s[i];
					 o++;
				 }
			}
			 // Check for an identifier
			if((s[i]>='a' && s[i]<='z')||(s[i]>='A' && s[i]<='Z')|| (s[i]>='0' && s[i]<='9')|| (s[i]=='_'))
		   {
			   k[r]=s[i];
			   r++;
		   } 
		   else
		   {
			   k[r]='\0';
			   //Check for a constant
			   if(k[0]>='0' && k[0]<='9')
			   { 
				   // Check for a pre-existing constant
			  	 for(j=0;j<p;j++)
				   {
                      if(!strcmp(constant[j],k))
                        break;
					}	
				 if(j==p)
				 {			
			       for(j=0;j<r;j++)
				   {
                      constant[p][j]=k[j];
                    }	
                    p++;
 				 }
 				 r=0;
 				}
 			  else
 				{  
				//Check for a keyword
			   f=key(k);
			   if(f==1)
			   {
				// Check for a pre-existing keyword
				 for(j=0;j<m;j++)
				   {
                      if(!strcmp(keyword[j],k))
                        break;
					}	
				 if(j==m)
				 {			
			       for(j=0;j<r;j++)
				   {
                      keyword[m][j]=k[j];
                    }	
                    m++;
 				 }
 				 r=0;
			 }
			 else
			 {
				 // Check for a pre-existing identifier
				for(j=0;j<l;j++)
				   {
                      if(!strcmp(identifier[j],k))
                        break;
					}	
				 if(j==l)
				 {			
			       for(j=0;j<r;j++)
				   {
                      identifier[l][j]=k[j];
                    }	
                    l++;
 				 }
 				 r=0;
			 }
		   }
		 }   
	  }
	  
  }
  //Printing all tokens
	   printf("\nKEYWORDS :\n");
	   for(i=0;i<m;i++)
	   {
		   printf("%s,",keyword[i]);
	   }    
	   printf("\n\nIDENTIFIER :\n");
	   for(i=0;i<l;i++)
	   {
		   printf("%s,",identifier[i]);
	   }    	   
	   printf("\n\nOPERATOR :\n");
	   for(i=0;i<n;i++)
	   {
		   printf("%c,",operator[i]);
	   }    	   
      	printf("\n\nDELIMITER :\n");
	   for(i=0;i<o;i++)
	   {
		   printf("%c\t",delimiter[i]);
	   }    	   
	   printf("\n\nCONSTANT :\n");
	   for(i=0;i<p;i++)
	   {
		   printf("%s,",constant[i]);
	   }    	   
	return 0;
}
