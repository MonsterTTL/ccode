#include <stdio.h>
#include <stdlib.h>
struct static_list{
   int data;
   int cur;


};

typedef struct static_list  ST_LIST[1000];

int STLT_Init(ST_LIST * p)
{p=(ST_LIST *)malloc(sizeof(ST_LIST));
 int i=0;
 for(i=0;i<999;i++)
   {
       p[i]->cur=i+1;
   }
 return 1;
}











int main()
{  ST_LIST *head;
   STLT_Init(head);
    




}