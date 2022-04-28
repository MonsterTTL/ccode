#include <stdio.h>
#include <stdlib.h>
#define MAX 10
#define M_(X,Y)    ((X)>(Y)?(X):(Y))

int rerange(int arr[],int L,int R);
void binggui(int arr[],int L,int R);
void merge(int arr[],int L,int mid,int R);
int main()
{int test[MAX]={1,5,6,8,7,11,6,9,4,2};
 binggui(test,0,9);
 for(int i=0;i<MAX;i++)
    {
        printf("%3d",test[i]);
    }
  



}


int rerange(int arr[],int L,int R)  //递归求最值
{if(L==R)
   return arr[L];
    
 int mid=((L+R)>>1);
 int Leftmax,Rightmax;
 Leftmax=rerange(arr,L,mid);
 Rightmax=rerange(arr,mid+1,R);
 return (M_(Leftmax,Rightmax));  
}

void binggui(int arr[],int L,int R)//归并排序
{if(L==R)
    return ;
  int mid=((L+R)>>1)  ;
  binggui(arr,L,mid);
  binggui(arr,mid+1,R);
  merge(arr,L,mid,R);


}


void merge(int arr[],int L,int mid,int R)
{if(L==R)
   return ;
  int now=0;
  int p1=L,p2=mid+1;
  int *temp=(int *)(malloc(sizeof(int)*(R-L+1)));
  while(p1<=mid&&p2<=R)
    {temp[now++]=(arr[p1]<=arr[p2]?arr[p1++]:arr[p2++]);
    } 
   while(p1<=mid)
    {
      temp[now++]=arr[p1++];
    }
   while(p2<=R) 
    {
      temp[now++]=arr[p2++];
    }
    now=0;
   for(int i=L;i<=R;i++)
   {
      arr[i]=temp[now++];
   }
  free(temp);

}