#include <stdio.h>
#include <stdlib.h>


struct linklist{
       struct linklist * next;
       int data;
       
};


typedef  struct linklist LK ;

LK * linklist_init()
{   LK* head=(LK*)(malloc(sizeof(LK)));//head
    head->data=0;
    head->next=NULL;
    return head;
}

LK * linklist_add(LK * head,int data)
{    LK *temp1 =head;
     while(temp1->next!=NULL)
     {
         temp1=temp1->next;
     }
     
     LK * temp=(LK *)(malloc(sizeof(LK)));
     temp->data=data;
     temp->next=NULL;
     temp1->next=temp;
     temp1=temp;
     return temp1;
}

LK * linklist_delect(LK * head,int NO)
{   LK * fast =head;
    LK * slow =head->next;
    
    for(int i=0;i<NO;i++)
        {  
            fast=fast->next;
        }
           slow=slow->next;
        
    while(fast->next!=NULL)
        {
            fast=fast->next;
            slow=slow->next;
        }
    slow->next=slow->next->next;
    free(slow->next);
    
}




int main()
{




}