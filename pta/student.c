#include<stdio.h>
#include<math.h>
#include<stdlib.h>

typedef struct{
    char xuehao[8];
    char name[11];
    int score[3];
}STUDENT;
void huoqu(STUDENT *temp,int n);


int main()
{   int n;scanf("%d",&n);getchar();
    STUDENT *p;
    p=(STUDENT *)malloc(sizeof(STUDENT)*n);
    huoqu(p,n);
    STUDENT max=p[0];
    for(int i=0;i<n;i++)
    {  if((max.score[0]+max.score[1]+max.score[2])<((p+i)->score[0]+(p+i)->score[1]+(p+i)->score[2]))
           max=(*(p+i));}
    printf("%s %s %d",max.name,max.xuehao,max.score[0]+max.score[1]+max.score[2]);       
}


void huoqu(STUDENT *temp,int n)
{  for(int i=0;i<n;i++)
    {scanf("%s%s%d%d%d",(temp+i)->xuehao,(temp+i)->name,(temp+i)->score,(temp+i)->score+1,(temp+i)->score+2);
    }
    getchar();

}