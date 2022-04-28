#include <stdio.h>
#include <stdlib.h>

#define mx 24

int main()
{ int test[mx]={1,1,1,1,2,2,2,2,2,2,3,3,3,3,3,7,7,7,7,7,3,3,3,5577};
  int result=0;
  int mid=0;int mid2=0;
  for(int i=0;i<mx;i++)
    {mid^=test[i];
    }
    mid2=mid&(~mid+1);
   for(int i=0;i<mx;i++) 
   {
       if(test[i]&mid2)
       {
         result^=test[i];


       }
   }
 printf("%d  %d",result,result^mid);



}