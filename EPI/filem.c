#include<stdio.h>
#include<strings.h>
#include<stdlib.h>
#define MAX 20
struct item_a{
    char name[MAX];
    int score;
    struct item_a * next;
};//����ṹ��

char * s_get(char * letter,int n)//�������뺯��
{    fgets(letter,n,stdin);
     char * pt;
     if((pt=strchr(letter,'\n'))!=NULL)
     {   *pt='\0'; }
     else{
         while(getchar()!='\n')
           continue;
     }
     return letter;

}


int main()
{  char mingzi[MAX];
   struct item_a * head=NULL;
   struct item_a * temp,* prev;
   struct item_a * test;
   puts("������һ����Ӱ��¼��������Ӱ�������֣�");
   while(s_get(mingzi,MAX)!=NULL&&mingzi[0]!='\0')
   {  if(head==NULL)
        { head=(struct item_a *)malloc(sizeof(struct item_a));
          head->next=NULL;
          temp=head;
        
        }
      else{temp=(struct item_a *)malloc(sizeof(struct item_a));
           temp->next=NULL;
           prev->next=temp;

      }
      strcpy(temp->name,mingzi);
      scanf("%d",&temp->score);
      while(getchar()!='\n')
        continue;//����������
      prev=temp;  




   }
   test=head;
   puts("here are the list:");
   while(test->next!=NULL)
   { puts(test->name);
     printf("%d\n",test->score);
     test=test->next;

   }  
   puts(test->name);
   printf("%d\n",test->score);
   test=head;
   while(test->next!=NULL)//�ͷ��ڴ�
   {
       free(test);
       test=test->next;
   }
   free(test);
   
} 