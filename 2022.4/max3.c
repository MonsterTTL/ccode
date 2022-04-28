#include <stdio.h>
#include <math.h>
#define MIM(X,Y) (X)<(Y)?(X):(Y)


int  MAX_three(int * temp,int n)
{int number =(n/sizeof(int));
 if(number<3)
    return -1;
  int result[3];
  result[0]=temp[0];
  result[1]=temp[0];
  result[2]=temp[0];
  for(int i=1;i<number;i++)
    { if(temp[i]>result[0])
         {   result[2]=result[1];
             result[1]=result[0];
             result[0]=temp[i];

         }
         else if(temp[i]>result[1])
         {result[2]=result[1];
         result[1]=temp[i];}
         else if(temp[i]>result[2])
          {result[2]=temp[i];}



    }
    printf("%d %d %d",result[0],result[1],result[2]);


}


int main()
{
   int a[10]={1,5,6,8,7,6,3,2,10,11};
   MAX_three(a,sizeof(a));
   
   return 0;





}