#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define MAX 50

void rand_happen(int *a)
{
  srand((unsigned int)time(NULL));
  for(int i=0;i<MAX;i++)
  {
    a[i]=(rand())%1000;
  }
}

void pr(int * op)
{for(int i=0;i<MAX;i++)
  {
    printf("%d ",op[i]);

  }



}

void min_limited(int * temp)
{int mid=MAX/2;
 if(temp[0]<temp[1])
    printf("Location:test[%d]",0);
 else if(temp[MAX-1]<temp[MAX-2])
    printf("Location:test[%d]",MAX-1);
 else{while(!(temp[mid]<temp[mid+1]&&temp[mid]<temp[mid-1]))
       {mid/=2;
       }
    printf("Location:temp[%d]",mid);


 }       
     



}


int main()
{int test[MAX];
 rand_happen(test);
 pr(test);
 printf("\n");
 min_limited(test);

}