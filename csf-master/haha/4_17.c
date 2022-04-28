#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 50

//四月十八日
void init(int arr[],int size);
void arr_show(int arr[],int size);
int * partitation(int arr[],int L,int R);
void q_sort(int arr[],int L,int R);
void exchange(int arr[],int x,int y);
void arr_copy(int const arr[],int size,int tip[]);
void heapinsert(int arr[],int location);
void heapsortfy_up(int arr[],int start,int end);
void heapsort_up(int arr[],int start,int end);
void heapfy_down(int arr[],int location,int size);
void heap_sort_plus(int arr[],int start,int end);
void merge_sort(int arr[],int L,int R);
void merge(int arr[],int L,int R);

int main(void)
{
    int test[MAX];
    int test2[MAX];
    int test3[MAX]; 
    init(test,MAX);
    arr_show(test,MAX);
    arr_copy(test,MAX,test2);
    arr_copy(test,MAX,test3);
    arr_show(test,MAX);
    q_sort(test,0,MAX - 1);
    arr_show(test,MAX);
    printf("hear comes heapsort!...............\n");
    //heapsort
    heapsort_up(test2,0,MAX - 1);
    arr_show(test2,MAX);
    //
    printf("hear comes mergesort!...............\n");
    merge_sort(test3,0,MAX - 1);
    arr_show(test3,MAX);


}


void init(int arr[],int size)
{
    srand((unsigned int)(time(NULL)));
    for(int i = 0;i < size ; i++)
        {
            arr[i] = rand() % 50;
        }
    return ;
}


void arr_show(int arr[],int size)
{
    for(int i =0 ;i < size ; i++)
        {
            printf("%d ",arr[i]);
        }
    printf("\n");
}

int * partitation(int arr[],int L,int R)
{   //if(L >= R)
     //   return ;
    srand((unsigned int)(time(NULL)));
    int now = L;int min = L - 1;int max = R;
    int * ret=(int *)(malloc(sizeof(int)*2));
    int location = L + ((rand()%(R - L + 1)));
    exchange(arr,R,location);
    while(now < max)
        {
            if(arr[now] > arr[R])
                {
                    exchange(arr,now,--max);
                }
            else if(arr[now] < arr[R])
                {
                    exchange(arr,now++,++min);
                }
            else
                {
                    now++;
                }
        }
    exchange(arr,R,max);
    ret[0] = min;
    ret[1] = max + 1;
    return ret;
}

void q_sort(int arr[],int L,int R)
{   if(L >= R)
        return ;
    int * use;
    use = partitation(arr,L,R);
    q_sort(arr,L,use[0]);
    q_sort(arr,use[1],R);
    return;

}

void exchange(int arr[],int x,int y)
{
    int temp = arr[x];
    arr[x] = arr[y];
    arr[y] = temp;
    return ;
}

void arr_copy(int const arr[],int size,int tip[])
{
    for(int i = 0;i < size;i++)
        {
            tip[i] = arr[i];
        }
    return ;
}

void heapinsert(int arr[],int location)
{
    if(location <= 0)
        return ;
    int father = (location - 1) / 2;
    while(arr[location] > arr[father])
        {
            exchange(arr,location,father);
            location = father;
            father = (location - 1) / 2;
        }
    return ;
}

void heapsortfy_up(int arr[],int start,int end)
{   
    for(int i = start;i <= end; i++)
        {
            heapinsert(arr,i);
        }
    return ;
}

void heapsort_up(int arr[],int start,int end)
{
    for(int i = start;i <= end; end--)
        {
            heapsortfy_up(arr,start,end);
            exchange(arr , i , end);
        }
    return ;
}

void heapfy_down(int arr[],int location,int size)
{   int left = location * 2 + 1;
    int max;
    while(left < size - 1)
        {
            max = (arr[left] > arr[left+1] ? left : left + 1);
            max = (arr[location] > arr[max] ? location : max);
            if(max == location)
                break;
            exchange(arr,max,location);
            location = max;
            left = location * 2 + 1;
        }
    return ;
}

void heap_sort_plus(int arr[],int start,int end)
{
    heapsortfy_up(arr,start,end);
    while((end - start + 1) > 0)
        {
            exchange(arr,start,end);
            end--;
            heapfy_down(arr,start,end);
        }
    return ;
}

void merge(int arr[],int L,int R)
{
    if(L >= R)
        return ;
    int size = (R - L + 1);
    int mid = ((L+R) >> 1);
    int * use = (int *)(malloc(sizeof(int)*size));
    int p1 = L;int p2 = mid + 1;int p3 = 0;
    while(p1 < mid + 1 && p2 <= R)
        {
            if(arr[p1] < arr[p2])
                {
                    use[p3++] = arr[p1];
                    p1++;
                }
            else if(arr[p1] >= arr[p2])
                {
                    use[p3++] = arr[p2];
                    p2++;
                }

        }
    while(p1 < mid + 1)
        {
            use[p3++] = arr[p1];
            p1++;
        }
    while(p2 <= R)
        {
            use[p3++] = arr[p2];
            p2++;
        }
    for(int i = L ,p3 = 0;i <= R; i++)
        {
            arr[i] = use [p3++];
        }
    free(use);
    return ;
}


void merge_sort(int arr[],int L,int R)
{
    if(L >= R)
        return ;
    int mid = ((L + R) >> 1);
    merge_sort(arr,L,mid);
    merge_sort(arr,mid+1,R);
    merge(arr,L,R);
    return;
}