#include <stdio.h>
#include <stdlib.h>


struct LIST1{   struct LIST1 * pre;
                 struct LIST1 * next;
                 int num;//���
                 int data;//���� 
} ;
typedef struct LIST1 LIST;

LIST * LIST_Init() // ��ͷ���
{ LIST *p;
  p= (LIST *)(malloc(sizeof(LIST)));
  p->pre=NULL;
  p->next=NULL;
  p->num=0;   //��������ʽ��
  return p;
}

int add_list(LIST * temp,LIST **test)//  �����ǰָ��Ҫ����ָ
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

int list_add_data(LIST * head,int num,int data)//head Ϊͷָ��
{LIST * temp;                                   //�ڵ�num���������Ϊdata
 temp=head;
 while(temp->num!=num)
    { if(temp->next==NULL)
        return -1;//failure
        temp=(temp->next);
    }
    temp->data=data;
    return 0;//success


}

int list_showdata(LIST * head,int num)//para:numΪ��ţ�headΪͷָ��
{LIST * p=head;                        // ��ʾ��num���ֵ
 while(p->num!=num)
    { if(p->next==NULL)
        return -1;//failure
        p=(p->next);
    }
  printf("data=%d\n",(p->data));



}

int list_str(LIST * head,int data) //����ָ�������ݣ����ҵ����ر�ţ����򷵻�-1
{while(head->data!=data&& head->next!=NULL)
  {
   head=head->next;
  }
  if(head->data==data)
    return (head->num);
  else
    return -1;  
 


}

void list_deleteAll(LIST * head)  //ɾ����������
{LIST * temp;
 while(head->next!=NULL)
   {
      temp=head->next;
      free(head);
      head=temp;


   }
  free(head); 
}

int list_delete(LIST * head,int num)  //ɾ�����ڵ�
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
int list_conut(LIST * head)//��������
{int i=0;
 while(head->next!=NULL)
    { i++;
      head=head->next; 
    }
    i++;
  return i;



}

int list_fanzhuan(LIST ** head)  //��ת˫������
{LIST * pre,* next;
 int m=list_conut(*head);//����ĩ���
 while((*head)->next!=NULL)
 {pre=(*head)->pre;   //  �洢ǰ
  next=(*head)->next;  //   �洢��
  (*head)->num=m;      //�������
  (*head)->next=pre;
  (*head)->pre=next;
  (*head)=(*head)->pre;
  m--;    //��ŵݼ�
 }
 pre=(*head)->pre;
 next=(*head)->next;
 (*head)->num=m;
 (*head)->next=pre;
 (*head)->pre=next;
 return 1;





}



int main()
{  LIST * user;//��ǰָ��
   LIST * head;//ͷָ��
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