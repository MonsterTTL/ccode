/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 void heapmin(int arr[],int location);
 void exchange(int arr[],int x ,int y);
 void heapdown(int arr[],int location,int size);
int* getLeastNumbers(int* arr, int arrSize, int k, int* returnSize){
    
    
    int * ret = (int *)malloc(sizeof(int) * k);
    for(int i = 0;i < arrSize; i++)
            {
              heapmin(arr,i);
             }
    for(int i = 0;i < k;i++)
        {
            ret[i] = arr[0];
          //  printf("%d ",arr[0]);
            exchange(arr,0,--arrSize);
            heapdown(arr,0,arrSize);
        }
       

    *returnSize = k;
    return ret;

}


void heapmin(int arr[],int location)
{
    int father = (location - 1) / 2;
    while(arr[location] < arr[father])
        {   
            exchange(arr,location,father);
            location = father;
            father = (location - 1) / 2;
        }
    return ;
}

void heapdown(int arr[],int location,int size)
{
    int left = location * 2 + 1;
    int min;
    while(left < size - 1)
            {
                min = (arr[left] < arr[left + 1] ? left : left + 1);
                min = (arr[location] < arr[min] ? location : min);
                if(min == location)
                    break ;
                exchange(arr,location,min);
                location = min ;
                left = location * 2 + 1;
            }
    return;
}


void exchange(int arr[],int x ,int y)
{
    int temp = arr[x];
    arr[x] = arr[y];
    arr[y] = temp;
    return ;
}