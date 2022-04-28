#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAX 10

void exchange(int arr[],int x,int y);
int * partitation(int arr[],int L,int R);
void q_sort(int arr[],int L,int R);
void init(int arr[], int num);
void arr_show(int arr[],int size);
void heapinsert(int arr[],int location);//往上放
void heapen_up(int arr[],int size);
void heapify(int arr[],int location,int size);
void heapen_down(int arr[],int size);
void heap_sort(int arr[],int size);

int main()
{   int arr[MAX];
    init(arr,MAX);
    arr_show(arr,MAX);
    printf("\n");
 //   q_sort(arr,0,MAX-1);
  //  heapen_up(arr,MAX);
  //heapen_down(arr,MAX);
    heap_sort(arr,MAX);
    arr_show(arr,MAX);


}



void exchange(int arr[],int x,int y)
{
    int temp = arr[x];
    arr[x] = arr[y];
    arr[y] = temp;
}

int * partitation(int arr[],int L,int R)
{   srand((unsigned int)(time(NULL)));
    int location = L+(rand()%(R-L+1));
    int * ret = (int *)(malloc(sizeof(int)*3));
    int now = L,min = L-1,max = R;
    exchange(arr,R,location);
    while(now<max)
        {if(arr[now]<arr[R])
            {
                exchange(arr,now++,++min);
               // now++;min++;

            }
         else if(arr[now]>arr[R])
            {
                exchange(arr,now,--max);
                //max--;
            }
         else
            {
                now++;
            }   

        }
    exchange(arr,R,max);
    ret[0] = min;
    ret[1] = max+1;//不加1的话会在又半边排好的情况下出现死循环 ，导致段错误
    return ret;   //别忘了返回值
}

void q_sort(int arr[],int L,int R)
{   int * temp;
    if(L>=R)
        return ;
    temp = partitation(arr,L,R);
    q_sort(arr,L,temp[0]);
    q_sort(arr,temp[1],R);
    free(temp);
    return ;
}

void init(int arr[], int num)
{
    srand((unsigned int)time(NULL));

    for (int i = 0; i < num; i++)
    {
        arr[i] = rand() % 50;
    }
}

void arr_show(int arr[],int size)
{
    for(int i = 0;i < size;i++)
        {
            printf("%d ",arr[i]);

        }

}


void heapinsert(int arr[],int location)//往上放
{   
    int father = (location-1)/2;
    if(father == location)
        return ;
    while(arr[location]>arr[father])
        {   
            
            exchange(arr,location,father); //顺序注意
            location = father;
            father = (location-1)/2;
            
        }
    return ;

}

void heapen_up(int arr[],int size)//堆化，向上
{
    for(int i = 0;i < size;i++)
        heapinsert(arr,i);
}

void heapify(int arr[],int location,int size)//往下放
{
    int left = location * 2 + 1;
    int max;
    //arr[size]=-999999;
    while(left < size - 1)
        {
            max = (arr[left] > arr[left+1] ? left : left+1 );
            max = (arr[location] > arr[max] ? location : max );
            if(location == max)
                break;
            exchange(arr,location,max);
            location = max;
            left = location * 2 + 1;
        }
    return ;
}

void heapen_down(int arr[],int size)//反过来 因为向下调整只能保证每次尾部正确，所以从尾部调整
{
    for(int i = size - 1;i >= 0;i--)
        heapify(arr,i,size);
}

void heap_sort(int arr[],int size)//碓排序
{  // int help[size];   
   // int p=0;
    while(size>0)
        {heapen_up(arr,size);
         exchange(arr,0,size-1);
         size--;
        }
    return ;

}