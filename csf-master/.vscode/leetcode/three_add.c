#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 50

void arr_show(int arr[],int size);
void init(int arr[],int size);
int com(void * s1, void * s2);


int main()
{
    int arr[MAX];
    init(arr,MAX);
    qsort(arr,MAX,sizeof(int),com);
    arr_show(arr,MAX);
}


int com(void * s1, void * s2)
{
    int * x = (int *)(s1);
    int * y = (int *)(s2);
    if( *x > *y)
        return 1;
    else if( *x < *y)
        return -1;
    else
        return 0;
}

void init(int arr[],int size)
{   srand((unsigned int)(time(NULL)));

    for(int i = 0;i < size;i++)
        {
            arr[i] = rand() % 50;
        }
    return ;
}

void arr_show(int arr[],int size)
{
    for(int i = 0;i < size;i++)
        {
            printf("%d ",arr[i]);
        }
}