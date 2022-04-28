#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 15
void insert(int arr[],int size);
void init(int arr[],int max);
int main()
{
  int test[MAX];
  init(test,MAX);
  for(int i=0;i<MAX;i++)
    printf("%3d",test[i]);
    printf("\n");
  insert(test,MAX);
  for(int i=0;i<MAX;i++)
    printf("%3d",test[i]);
}



void insert(int arr[],int size)
{int temp;
 for(int i=1;i<size;i++)
  {
     for(int j=i-1;j>=0&&arr[j]>arr[j+1];j--)
       {temp=arr[j];
        arr[j]=arr[j+1];
        arr[j+1]=temp;

       }
  }
}

void init(int arr[],int max)
{srand((unsigned int)(time(NULL)));
 for(int i=0;i<max;i++)
   { arr[i]=(rand()%100);


   }




}