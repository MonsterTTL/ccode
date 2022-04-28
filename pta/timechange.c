#include<stdio.h>
#include<math.h>
typedef struct{
    int h;
    int m;
    int s;
}TIME;


int main(void)
{   TIME system;
    scanf("%d:%d:%d",&system.h,&system.m,&system.s);
    int change=0;
    getchar();
    scanf("%d",&change);getchar();
    system.s+=change;
    while(system.s>=60)
        {system.s-=60;
         system.m++;}
    while(system.m>=60)
        {system.m-=60;
         system.h++;} 
    system.h%=24;   
    printf("%02d:%02d:%02d",system.h,system.m,system.s);      
 }