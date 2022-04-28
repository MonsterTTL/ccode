#include <stdio.h>
#include <stdlib.h>
typedef union a{
    int number;
    char string[10];
}b;
typedef struct c{
    b d;
    int e;
    double f;
    char h;
}g;
int main()
{ int nums[]={1,5,7};
  int cnt=0;
  int a;
   a=printf("\n\n");
   printf("a=%d\n",a);
  switch(0){
      case 0:
         cnt = printf("%d\n",sizeof(b));
      case 1:
         printf("%d\n",cnt+=sizeof(g));
      case 2:
         cnt+=1[nums];
         break;
      case 3:
         cnt--;

  }
 printf("%d",cnt);
 return 0;


}