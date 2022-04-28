#include<strings.h>
#include<stdio.h>
#include<stdlib.h>
#define MAX 100
char * s_gets(char *arr,int n);
int main()
{  char letter[MAX];
   char wait;
   char * point;
   scanf("%c",&wait);
   fflush(stdin);
   s_gets(letter,MAX);
   point=strrchr(letter,wait);
   if(point)
   {
       printf("index = %d",(point-letter)/sizeof(char));
   }
   else
    printf("Not Found");
   

}

char * s_gets(char *arr,int n)
{    char * re;
     int num=0;
     re=fgets(arr,n,stdin);
     if(re)
     { while(arr[num]!='\n'&&arr[num]!='\0')
         num++;
       if(arr[num]=='\n')
	       arr[num]='\0';
	else
	   while(getchar()!='\n')
	      continue;	     
	 }
	return re; 
}