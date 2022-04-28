#include <stdio.h>
#define MAX(X,Y)  ((X)>(Y)?(X):(Y))
int main()
{   int a = 1;
    int b = 0;
    int x = ++a + --a + ++a;
    int y =b++ + b-- + b++;
    printf("%d , %d ,",x,y);
    int z =MAX(x--,--y);
    printf("%d",z);
    return 0;
 

}