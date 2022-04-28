#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 12
void exchang(int arr[],int i,int r);
int * partation(int arr[],int L,int R);//最小方法
void kuaipai_1(int arr[],int L,int R,int mid)
{int p1=L;int p2=L-1;int temp;
 while(p1<=R)
   {if(arr[p1]<mid)
    {temp=arr[p2+1];
      arr[p2+1]=arr[p1];
      arr[p1]=temp;
      p2++;  
       
    }
    p1++;

   
   }

}
int * kuaipai_2(int arr[],int L,int R,int mid)
{int p1=L-1,p2=R+1;
 int p=L;int temp;
 int *result;
 while(p<p2)
 {if(arr[p]<mid)
   {temp=arr[p1+1];
      arr[p1+1]=arr[p];
      arr[p]=temp;
      p1++; 
      p++;

   }
   else if(arr[p]>mid)
   {temp=arr[p2-1];
    arr[p2-1]=arr[p];
    arr[p]=temp;
    p2--;
   }
   else if(arr[p]==mid)
   {
       p++;
   }
   
 }
  exchang(arr,R,p2);
  //result=(int *)(malloc(sizeof(int)*2));
  //result[0]=p1;
  //result[1]=p2;
  return (int[2]){p1,p2};
}


void rand_init(int arr[],int number)
{  srand((unsigned int)(time(NULL)));
   for(int i=0;i<number;i++)
     { arr[i]=rand()%10;
     }
}


void q_sort_p(int arr[],int L,int R)
{int *temp;
 if(L<R)
  {temp=partation(arr,L,R);
   q_sort_p(arr,L,temp[0]);
   q_sort_p(arr,temp[1]+1,R);
   free(temp);//释放暂存区
  }
  return ;
}


int * partation(int arr[],int L,int R)//最小方法
{ srand((unsigned int)(time(NULL)));
  int location=L+(rand()%(R-L+1));int *kk;//fanhuizhi
 // printf("%d\n",location);//
  exchang(arr,R,location);
 // for(int i=0;i<MAX;i++)
 //   printf("%3d",arr[i]);
 //printf("\n");
  int p=L,p1=L-1,p2=R;
  while(p<p2)
  {
    if(arr[p]<arr[R])
     { exchang(arr,p,p1+1);
      p++;
      p1++;}
     else if (arr[p]>arr[R])
     {  exchang(arr,p,p2-1);
        p2--;
         }
     else
     {
       p++; 
     }
   }
   exchang(arr,p2,R);
 //  for(int i=0;i<MAX;i++)
  //  printf("%3d",arr[i]);
 //printf("\n");
  kk=(int *)(malloc(sizeof(int)*3));
  kk[0]=p1;
  kk[1]=p2;   
  return kk;
}

void exchang(int arr[],int i,int r)
{
   int temp;
   temp=arr[i];
   arr[i]=arr[r];
   arr[r]=temp;
}

void kong(void)
{
  
}


int main()
{int test[MAX];
 rand_init(test,MAX);
 for(int i=0;i<MAX;i++)
    printf("%3d",test[i]);
 printf("\n");
 //int *men=partation(test,0,MAX-1);
 //for(int i=0;i<MAX;i++)
  //  printf("%3d",test[i]);
  q_sort_p(test,0,11);
  for(int i=0;i<MAX;i++)
     printf("%3d",test[i]);
 printf("\n");
    
 
}