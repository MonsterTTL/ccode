#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define MAX 20
void countsort(int arr[],int size);
void init(int arr[],int num);
int main(void)
{       int arr[MAX];
        init(arr,MAX);
        for(int i=0;i<MAX;i++)
        printf("%d ",arr[i]);
        printf("\n");
        countsort(arr,MAX);
}
void countsort(int arr[],int size)
{ int temp[20]={0};
  for(int i=0;i<size;i++)
     {   temp[arr[i]]++;
         }
  for(int z=0;z<size;z++)
     {while(temp[z]>0)
        {
            printf("%d ",z);
            temp[z]--;
        }
     }
}
void init(int arr[],int num)
{   srand((unsigned int)time(NULL));
     
    for(int i=0;i<num;i++)
       {arr[i]=rand()%17;
       }
}