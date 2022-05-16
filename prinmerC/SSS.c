#include <stdio.h>
#include <stdlib.h>
struct  A
{
    double c;
    double b;
    char a;
};

struct B
{   
    int c;
    double b;
    char a;
};

struct C
{   
    int c;
    struct A;
    struct B;
    
};







int main()
{   

    printf("%d\n",sizeof(struct A));
    printf("%d\n",sizeof(struct B));
    printf("%d ",sizeof(struct C));
}