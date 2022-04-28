#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 15
void exchange(int arr[],int x,int y);
int * participation(int arr[],int L,int R)
{   srand((unsigned int )(time(NULL)));
    int location=L+(rand()%(R-L+1));
    int *next;
    exchange(arr,location,R);
    int p1=L-1,p2=R,p=L;
    while(p<p2)
        {if(arr[p]<arr[R])
             {
                 exchange(arr,p++,++p1);
             }
         else if(arr[p]>arr[R])
             {
                 exchange(arr,p,--p2);
             }    
         else
             {
                 p++;
             }


        }
    exchange(arr,R,p2);
    next=(int *)(malloc(sizeof(int)*2));
    next[0]=p1;
    next[1]=p2;
    return next;
   
}

void exchange(int arr[],int x,int y)
{  int temp;
   temp=arr[x];
   arr[x]=arr[y];
   arr[y]=temp;
   return ;
}


void q_sort(int arr[],int L,int R)
{   if(L>=R)
      return ;
    int *use;
    use=participation(arr,L,R);
    q_sort(arr,L,use[0]);
    q_sort(arr,use[1],R);
    free(use);
}
void init(int arr[],int size)
{   srand((unsigned int)(time(NULL)));
     for(int i=0;i<size;i++)
         arr[i]=(rand()%100);
}


int main()
{
    int arr[MAX];
    init(arr,MAX);
    for(int i=0;i<MAX;i++)
       printf("%d ",arr[i]);
       printf("\n");
    q_sort(arr,0,MAX-1);

    for(int i=0;i<MAX;i++)
       printf("%d ",arr[i]);


}