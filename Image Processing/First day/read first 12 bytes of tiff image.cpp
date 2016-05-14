#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    FILE *fp;
    char file_name[1000];
    printf("Enter the full name of file (with extension) you wish to open\n");
    gets(file_name);
    fp = fopen(file_name,"rb"); // read mode in binary
    if( fp == NULL )
       {
          perror("Error while opening the file.\n");
          exit(EXIT_FAILURE);
       }
    else if (!strstr(file_name,".tif")){
        printf("Not a TIFF File. Please choose one \n");
        exit(EXIT_FAILURE);
    }
    else{
      char buffer[1000];
      fread(buffer,1,8,fp);
      for(int i=0;i<8;i++){
        printf("%x\n",buffer[i]);
      }
      fclose(fp);
    }
}
