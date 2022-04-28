#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 20
void range(int arr[],int size)
{  
    if(size<4)
      return ;
     int result[3];
    result[0]=arr[0];
    result[1]=arr[0];
    result[2]=arr[0];
    for(int i=0;i<size;i++)
       {  if(result[2]<arr[i])
             {   result[0]=result[1];
                 result[1]=result[2];
                 result[2]=arr[i];
               
             }
           else if(result[1]<arr[i])
           {
                 result[1]=result[2];
                 result[2]=arr[i];

           } 
           else if(result[2]<arr[i])
           {
               result[2]=arr[i];
           } 




       }
       for(int i=0;i<3;i++)
         printf("%d ",result[i]);




}

void exchange(int arr[],int x,int y)
{ int temp;
  temp=arr[x];
  arr[x]=arr[y];
  arr[y]=temp;




}

void init(int arr[],int size)
{   srand((unsigned int)(time(NULL)));
     for(int i=0;i<size;i++)
         arr[i]=(rand()%100);
}
int main()
{
   int test[SIZE];
   init(test,SIZE);
   for(int i=0;i<SIZE;i++)
     printf("%d ",test[i]);
   printf("\n");
   range(test,SIZE);


}