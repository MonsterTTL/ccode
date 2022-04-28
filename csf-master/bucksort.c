#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 15

int arr_max(int arr[],int size);//取出一个数组中的最大值
void init(int arr[],int size);//
void arr_show(int arr[],int size);
int inter_bits(int a);//返回整数的位数
void buck_sort(int arr[],int size);//桶排序，优化版
int git_bit(int a,int b);//取出指定位的数字

int main()
{  // int test;
    int arr[MAX];
    init(arr,MAX);
    arr_show(arr,MAX);
    buck_sort(arr,MAX);
    arr_show(arr,MAX);
  //  printf("%d \n",test=arr_max(arr,MAX));
  //  printf("%d",inter_bits(test));


}


int arr_max(int arr[],int size)
{
    int bit = 0;
    int max = arr[0];
    for(int i = 0;i < size ; i++)
        {
            max = (max > arr[i] ? max : arr[i]);
        }
    return max;
    
}

void init(int arr[],int size)
{   srand((unsigned int)(time(NULL)));
    for(int i = 0;i < size ;i++)
        {
            arr[i]=rand()%50;
        }
}

void arr_show(int arr[],int size)
{
    for(int i = 0;i < size; i++)
        printf("%d ",arr[i]);
    printf("\n");
}

int inter_bits(int a)
{
    int bit = 1;
    while(a/10 != 0)
        {
            bit++;
            a /= 10;
        }
    return bit;
}

void buck_sort(int arr[],int size)
{   
    int maxbit = arr_max(arr,size);
    maxbit = inter_bits(maxbit);
    int *help = (int *)(malloc(sizeof(int)*size));
    int count[10] = {0};
    for(int d = 1;d <= maxbit;d++)
        {
            for(int i = 0;i < size; i++)
                {
                    count[git_bit(arr[i],d)]++;
                }
            for(int i = 1;i < 10;i++)
                {
                    count[i]+=count[i-1];
                }
            for(int i = size - 1;i >= 0; i--)
                {   int j = git_bit(arr[i],d);
                    help[count[j]-1] = arr[i];
                    count[j]--;
                }
            for(int i = 0;i < 10;i++)
                {
                    count[i]=0;
                }
            for(int i = 0;i < size;i++)
                {
                    arr[i]=help[i];
                }
        }
    return ;
}

int git_bit(int a,int b)
{   
    int ret;
    int st1 = 1,st2 = 10;
    while(b>0)
        {
            ret = (a/st1)%st2;
            st1 *= 10;
            st2 *= 10;
            b--;
        }
    return ret;
}


