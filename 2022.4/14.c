#include <stdio.h>




int main()
{
 int a[5]={1,2,3,4,5};
 int *b=a+3;
 printf("%d %d %d",b[-2],b,a+1);
}