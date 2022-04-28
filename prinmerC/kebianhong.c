#include <stdio.h>
#include <stdarg.h>
int sum(int num,...);

int main()
{int re;
 re=sum(5,1,2,3,4,5);
 printf("%d",re);

}


int sum(int num,...)
{  va_list var_list;
   int count;
   int sum1=0;
   va_start(var_list,num);
   for(count=0;count<num;count++)
    {   sum1+=va_arg(var_list,int);

    }
    va_end(var_list);
    return sum1;



}