#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

//4.17 @地心钛兽
//较为完整的单链表操作
struct linklist{
    struct linklist * next;
    char data[10];
};

typedef struct linklist LinkList;

LinkList * linklist_init(void);//链表初始化
void linklist_change(LinkList * head,int number,char * data);//改变链表的数据
int linklist_length(LinkList * head);//返回链表长度，头节点不算
void linklist_change_last(LinkList * head,int number,char * data);//改变链表的倒数第N向的数据
void linklist_show_last(LinkList * head,int number);//展示链表倒数第N项的数据
LinkList * linklist_add(LinkList * head,char * data);//在链表中添加一项，同时添加数据
void linklist_show(LinkList * head, int number);

int main()
{   LinkList * head =linklist_init();
    linklist_add(head,"hello");
    linklist_add(head,"my_load");
    linklist_show_last(head,1);
    linklist_show_last(head,2);
    linklist_change(head,1,"Superhero");
    linklist_show_last(head,2);
    linklist_show(head,1);

}

LinkList * linklist_init(void)
{   LinkList * ret ;
    ret = (LinkList *)(malloc(sizeof(LinkList)));
    ret -> next = NULL;
    return ret;
}

LinkList * linklist_add(LinkList * head,char * data)
{   LinkList * temp = head;
    LinkList * temp2;
    while(temp->next!=NULL)
        temp=temp->next;
    temp2 = (LinkList *)(malloc(sizeof(LinkList)));
    temp2->next = NULL;
    strcpy(temp2->data,data);
    temp->next = temp2;
    return temp2; //返回尾节点
}

int linklist_length(LinkList * head)//返回链表长度，头节点不算
{   int ret = 0;
    LinkList * temp = head;
    while(temp->next != NULL)
        {
            ret++;
            temp = temp->next;
        }
    return ret;
}

void linklist_change_last(LinkList * head,int number,char * data)//改变倒数第N项的数据
{   LinkList * temp = head;
    LinkList * fast = head->next;
    LinkList * slow = head->next;
    if(linklist_length(head)<number)
        {
            printf("add_linklist fail!\n");
            return ;
        }
    for(int i = 0 ;i < number; i++)
        {
            fast = fast->next;
        }
    while(fast != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
    strcpy(slow->data,data);
    return ;

}

void linklist_change(LinkList * head,int number,char * data)
{
    int length = linklist_length(head);
    length = length - number + 1;
    linklist_change_last(head,length,data);
    return ;

}

void linklist_show_last(LinkList * head,int number)//显示倒数第N项的数据
{   
    
    LinkList * fast = head->next;
    LinkList * slow = head->next;    
    if(linklist_length(head)<number)
        {
            printf("show fail!");
            return ;
        }
    for(int i = 0;i < number;i++)
        {
            fast = fast->next;
        }
    while(fast != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
    printf("%s\n",slow->data);
    return ;
}

void linklist_show(LinkList * head, int number)
{   int length = linklist_length(head);
    if(number > length)
        {
            printf("show fail");
            return ;
        }
    length = length - number + 1;
    linklist_show_last(head,length);
    return ;
}

