#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 3

void exchange(int arr[], int x, int y);
int *partitation(int arr[], int L, int R);
void q1_sort(int arr[], int L, int R);
void init(int arr[], int num);

int main()
{
    int test[MAX];
    init(test, MAX);
    q1_sort(test, 0, MAX - 1);
    // int * p=partitation(test,0,MAX-1);
    for (int i = 0; i < MAX; i++)
    {
        printf("%d ", test[i]);
    }
    // printf("\n%d %d",p[0],p[1]);
}

void exchange(int arr[], int x, int y)
{
    int temp = arr[x];
    arr[x] = arr[y];
    arr[y] = temp;

    return;
}

int *partitation(int arr[], int L, int R)
{
    srand((unsigned int)(time(NULL)));
    int location = L + (rand() % (R - L + 1));
    printf("%d \n", location);
    exchange(arr, R, location);
    int *ret;
    int now = L, max_area = R, min_area = L - 1;
    while (now < max_area)
    {
        if (arr[now] < arr[R])
        {
            exchange(arr, now++, ++min_area);
        }
        else if (arr[now] > arr[R])
        {
            exchange(arr, now, --max_area);
        }
        else
        {
            now++;
        }
    }
    exchange(arr, R, max_area);
    ret = (int *)malloc(sizeof(int) * 3);
    ret[0] = min_area;
    ret[1] = max_area; //换区！！！！

    return ret;
}

void q1_sort(int arr[], int L, int R)
{
    if (L >= R || L < 0)
        return;
    int *use;
    use = partitation(arr, L, R);
    q1_sort(arr, L, use[0]);
    q1_sort(arr, use[1]+1, R);
    free(use);
}

void init(int arr[], int num)
{
    srand((unsigned int)time(NULL));

    for (int i = 0; i < num; i++)
    {
        arr[i] = rand() % 50;
    }
}
