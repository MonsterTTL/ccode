#include <stdio.h>
#include <stdlib.h>


struct LIST1{   struct LIST1 * pre;
                 struct LIST1 * next;
                 int num;//标号
                 int data;//数据 
} ;
typedef struct LIST1 LIST;

LIST * LIST_Init() // 带头结点
{ LIST *p;
  p= (LIST *)(malloc(sizeof(LIST)));
  p->pre=NULL;
  p->next=NULL;
  p->num=0;   //不计入正式项
  return p;
}

int add_list(LIST * temp,LIST **test)//  用完后当前指针要往后指
{if(temp->next!=NULL)
   {printf("add fail!");
       return -1;}
 LIST * p;
 p= (LIST *)(malloc(sizeof(LIST)));
 temp->next=p;
 p->pre=temp;
 p->num=(p->pre->num+1);
 p->next=NULL;
 (*test)=temp->next;
   return 0;
  
}

char * s_get(char * string,int x)
{  char * ret;
   int n=0;
   ret=fgets(string,x,stdin);
   while(string[n]!='\0'&&string[n]!='\n')
      n++;
   if(string[n]=='\n')
       string[n]='\0';
   else
   {
       while(getchar()!='\n')
          continue;
   }       
   return ret;
}

int list_add_data(LIST * head,int num,int data)//head 为头指针
{LIST * temp;                                   //在第num项添加数据为data
 temp=head;
 while(temp->num!=num)
    { if(temp->next==NULL)
        return -1;//failure
        temp=(temp->next);
    }
    temp->data=data;
    return 0;//success


}

int list_showdata(LIST * head,int num)//para:num为编号，head为头指针
{LIST * p=head;                        // 显示第num项的值
 while(p->num!=num)
    { if(p->next==NULL)
        return -1;//failure
        p=(p->next);
    }
  printf("data=%d\n",(p->data));



}

int list_str(LIST * head,int data) //查找指定的数据，若找到返回编号，否则返回-1
{while(head->data!=data&& head->next!=NULL)
  {
   head=head->next;
  }
  if(head->data==data)
    return (head->num);
  else
    return -1;  
 


}

void list_deleteAll(LIST * head)  //删除整个链表
{LIST * temp;
 while(head->next!=NULL)
   {
      temp=head->next;
      free(head);
      head=temp;


   }
  free(head); 
}

int list_delete(LIST * head,int num)  //删除单节点
{  LIST * pre,* next;
   while(head->num!=num)
     {
     head=head->next;
     }
     pre=head->pre;
     next=head->next;

     pre->next=next;
     next->pre=pre;
   while(next->next!=NULL)  
     {next->num--;
      next=next->next;
     }
     next->num--;
   free(head);
      



}
int list_conut(LIST * head)//计算项数
{int i=0;
 while(head->next!=NULL)
    { i++;
      head=head->next; 
    }
    i++;
  return i;



}

int list_fanzhuan(LIST ** head)  //反转双向链表
{LIST * pre,* next;
 int m=list_conut(*head);//计算末编号
 while((*head)->next!=NULL)
 {pre=(*head)->pre;   //  存储前
  next=(*head)->next;  //   存储后
  (*head)->num=m;      //交换编号
  (*head)->next=pre;
  (*head)->pre=next;
  (*head)=(*head)->pre;
  m--;    //编号递减
 }
 pre=(*head)->pre;
 next=(*head)->next;
 (*head)->num=m;
 (*head)->next=pre;
 (*head)->pre=next;
 return 1;





}



int main()
{  LIST * user;//当前指针
   LIST * head;//头指针
   user=LIST_Init();
   head=user;
   add_list(user,&user);
   //user=(user->next);
   list_add_data(head,1,5);
   add_list(user,&user);
   //user=(user->next);
   list_add_data(head,2,55);
   add_list(user,&user);
   list_add_data(head,3,555);
   list_showdata(head,1);list_showdata(head,2);list_showdata(head,3);
   printf("\n");
   list_fanzhuan(&head);
   list_showdata(head,1);list_showdata(head,2);list_showdata(head,3);
   printf("\n");
  
   if(list_str(head,55)>=0)
      {printf("find success,num:%d",list_str(head,55));}
   else
      printf("str fail!!");   
}