#include<stdio.h>
#include<stdlib.h>
void showarr(int *a,int b);
int compare(const void *a,const void *b);
int main()
{   int test[10]={0};
    for(int i=0;i<10;i++)
    { scanf("%d",&test[i]);}
    qsort(test,10,sizeof(int),compare) ;
    showarr(test,10);


}


int compare(const void *c,const void *d)
{  const int *a=c;const int *b=d;
    
   if((*a)>(*b))
      return 1;
   else if((*a)==(*b))
      return 0;
   else
      return -1;      
   }

void showarr(int *a,int b)
{ for(int i=0;i<b;i++)
    printf("%3d",a[i]);

}   