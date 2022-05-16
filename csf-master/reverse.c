#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct linklist{
    int data;
    struct linklist * next;
}Linklist;

void arr_scanf(Linklist * head,int times);
void arr_show(Linklist * head);
void init(Linklist ** head);
void add(Linklist * head,int data);
Linklist * reverse(Linklist * head);
Linklist * delete(Linklist * head ,int index);
Linklist * merge(Linklist * head1 ,Linklist * head2);
Linklist * reverse2(Linklist * head);

typedef struct stack{
    char arr[MAX];
    int cur;
}Stack;

void stack_init(Stack * use)
{
    use -> cur = -1;
    return ;
}

char stack_pop(Stack * use)
{
    char ret = use -> arr[use -> cur];
    use -> cur--;
    return ret;

}

void stack_push(Stack * use,char a)
{
    use -> cur++;
    use -> arr[use -> cur] = a;
    return ;
}

int main(void)
{
    Linklist * use ;
    init(&use);
   // Linklist * use2;
  //init(&use2);
    arr_scanf(use,5);
 //arr_scanf(use2,5);
    arr_show(use);
    printf("\n");
  // arr_show(use2);
   // delete(use,1);
   use = reverse(use);
 
  //  use = reverse2(use -> next);
  //  use = use -> next;
    arr_show(use);
    printf("\n");
    
  //  Linklist * new = merge(use,use2);
  //  arr_show(new);
   

}

void arr_scanf(Linklist * head,int times)
{
    int data;
    for(int i = 0;i < times;i++)
    {
        scanf("%d ",&data);
        add(head,data);
    }
}

void arr_show(Linklist * head)
{
    Linklist * temp = head;
    temp = temp -> next;
    while(temp != NULL )
    {
        printf("%d ",temp ->data);
        temp = temp -> next;
    }
}

void init(Linklist ** head)
{
    (*head) = (Linklist *)(malloc(sizeof(Linklist)));
    (*head) -> data = 0;
    (*head) -> next = NULL;
    return ;
}

void add(Linklist * head,int data)
{
    Linklist * node = (Linklist *)(malloc(sizeof(Linklist)));
    Linklist * gg = head;
    while(gg -> next != NULL)
        {
            gg = gg -> next;
        }
    gg -> next = node;
    node -> data = data;
    node -> next = NULL;
    return ;
    
}




Linklist * reverse(Linklist * head)
{
    Linklist * temp = head -> next ;
    Linklist * newhead = NULL;
    Linklist * node;
    
    while(temp != NULL )
    {
         node = temp ;
         temp = temp -> next;
         node -> next = newhead;
         newhead = node;
    }
    head -> next = newhead;
    return head;
}



Linklist * reverse2(Linklist * head)
{
    Linklist * new = head;
    if(head == NULL ||head -> next == NULL )
     return head;
    new = reverse2(head);
    head -> next -> next = head;
    head -> next = NULL;
    return new;
    
}
Linklist * delete(Linklist * head ,int index)
{
    Linklist * fast = head;
    Linklist * slow = head;
    for(int i = 0;i < index;i++)
    {
        fast = fast -> next;
    }
    while(fast != NULL && fast -> next != NULL)
    {
        fast = fast -> next;
        slow = slow -> next;
    }
    (*slow) = *(slow -> next);

}


Linklist * merge(Linklist * head1 ,Linklist * head2)
{
    Linklist * ret = (Linklist *)(malloc(sizeof(Linklist)));
    Linklist * retu = ret;
    Linklist * p1 = head1 -> next;
    Linklist * p2 = head2 -> next;
    while(p1 != NULL && p2 != NULL)
    {
        if(p1 -> data < p2 -> data)
        {
            ret -> next = p1;
            p1 = p1 -> next ;
        }
        else
        {
            ret -> next = p2;
            p2 = p2 -> next ;
        }
        ret = ret -> next;
    }
    while(p1 != NULL)
    {
        ret -> next = p1;
        p1 = p1 -> next;
        ret = ret -> next;
        
    }
    while(p2 != NULL)
    {
        ret -> next = p2;
        p2 = p2 -> next;
        ret = ret -> next;
    }
    return (retu->next) ;
}

