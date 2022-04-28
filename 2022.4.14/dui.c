#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define MAX 20
void exchange(int arr[],int x,int y);
void heapinsert(int arr[],int location)//��locationλ�����ѻ�������λ��  ����ֻ�ÿ�һ�� ����Խ��
{
    while(arr[location]>arr[location-1>>1])
     {   //if(location<=0)
           //return ;
         exchange(arr,location,location-1>>1);
         location=location-1>>1;
         
     }
     return ;
   
}

void heapfiy(int arr[],int location,int heapsize)//from location to heapsize ����Ҫ�����߿� ���ܻ��½�
{int left =location*2+1;
 while(left<heapsize)
    {
      int max = arr[left]>arr[left+1]?left:left+1; //˫�ӱȽ�

      max=arr[max]>arr[location]?max:location;//���ӱȽ�
      if(max==location)
        break;
      exchange(arr,max,location);
      location=max;
      left=location*2+1;
    }
    return ;
}

void exchange(int arr[],int x,int y)
{int temp=arr[x];
 arr[x]=arr[y];
 arr[y]=temp;
 return ;
}



void heapsort(int arr[],int size)
{ if(size<2||arr==(NULL))
     return ;
   for(int i=0;i<size;i++)
       heapinsert(arr,i);
   exchange(arr,0,--size);
   while(size>0)
       {
         heapfiy(arr,0,size);
         exchange(arr,0,size--);
       }      
    return ;
}

void rand_init(int arr[],int number)
{
   srand((unsigned int)(time(NULL)));
   for(int i=0;i<number;i++)
      arr[i]=rand()%100;
  return;
}
void arr_show(int arr[],int number)
{ for(int i=0;i<number;i++)
   printf("%d ",arr[i]);




}

int main()
{
  int test[MAX];
  rand_init(test,MAX);
  arr_show(test,MAX);
  printf("\n");
  heapsort(test,MAX);
  arr_show(test,MAX);




}