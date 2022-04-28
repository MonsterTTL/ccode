#include<stdio.h>
#include<stdlib.h>
#include<strings.h>
#define MAX 100
#define M1 19
#define cha ('1'-1) 
char * s_gets(char *arr,int n);

int main(void)
{ char arr[MAX][M1];
  const int quan[M1-2]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
  const char jiaoyan[11]={'1','0','x','9','8','7','6','5','4','3','2'};
  int n;
  int flag2=1;
  int z=0;int flag;
  scanf("%d",&n);
  fflush(stdin);
  for(int i=0;i<n;i++)
     {  s_gets(arr[i],M1);
     }
  for(int i=0;i<n;i++)
     {z=0;
        for(int x=0;x<M1-2;x++)
          z+=(arr[i][x]-cha)*quan[x];
      flag=z%11;printf("%d\n",flag);
          if(jiaoyan[flag]!=arr[i][17])
          {
             flag2=0;
             puts(arr[i]);
             
          }
        
     }
     if(flag2)
       printf("All passed");
   
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