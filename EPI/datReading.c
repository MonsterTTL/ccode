#include<stdio.h>
#include<stdlib.h>
#include<strings.h>
#define MAX 50
#define SPACE 4096
char * s_get(char * letter,int n);
void coppy(FILE * fb,FILE * out);
int main()
{FILE * fb;
 char name[MAX]={""};
 char temp[SPACE]={""};
 puts("enter the name");
 if((s_get(name,MAX-4))==NULL) // ‰»ÎºÏ≤‚ 
    puts("wrong!");
 strcat(name,".dat");
 if((fb=fopen(name,"a+"))==NULL);
    {
       puts("cant open!");
       exit(EXIT_FAILURE);
    }
 if(setvbuf(fb,NULL,_IOFBF,100)!=0)
    {fprintf(stderr,"Error!");
     exit(EXIT_FAILURE);
    }
 while(s_get(temp,SPACE)!=NULL&&temp[0]!='\0')
 {
      fputs(temp,fb);
 }

 fclose(fb);
 




}

char * s_get(char * letter,int n)
{   
     char * rev;
     char * pt;
     rev = fgets(letter,n,stdin);
     if((pt=strchr(letter,'\n'))!=NULL)
     {   *pt='\n'; }
     else{
         while(getchar()!='\n')
           continue;
     }
     return rev;

}

void coppy(FILE * fb,FILE * out)
{  int ch;
   while((ch=getc(fb))!=EOF)
   {putc(ch,out);

   }

}