#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 50





void rand_happen(int *a)
{
  srand((unsigned int)time(NULL));
  for(int i=0;i<MAX;i++)
  {
    a[i]=(rand())%1000;
  }
}


void insert(int *a)
{int temp=0;
    for(int i=1;i<MAX;i++)
    {
      for(int z=i-1;z>=0&&a[z]>a[z+1];z--)
      {temp=a[z];
       a[z]=a[z+1];
       a[z+1]=temp;
      }





    }
}

void pr(int * op)
{for(int i=0;i<MAX;i++)
  {
    printf("%d ",op[i]);

  }



}

int main()
{int test[MAX];
 rand_happen(test);
 insert(test);
 pr(test);

}