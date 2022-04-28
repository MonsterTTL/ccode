#include<stdio.h>
#include<math.h>
#include<stdlib.h>
typedef struct{
    char number[31];
    int shiji;
    int kaoshi;
}INF;

int main(void)
{int n;scanf("%d",&n);getchar();
 INF * p;int n2;
 p=(INF *)malloc(sizeof(INF)*n);
 for(int i=0;i<n;i++)
    {scanf("%s%d%d",p[i].number,&p[i].shiji,&p[i].kaoshi);
    }
 getchar();
 scanf("%d",&n2); 
 int *p2;
 p2=(int *)malloc(sizeof(int)*n2);
 for(int i=0;i<n2;i++)
    {
        scanf("%d",&p2[i]);
    }
 for(int i=0;i<n2;i++)
 {  for(int y=0;y<n;y++)
      {
          if(p2[i]==p[y].shiji)
            printf("%s %d\n",p[y].number,p[y].kaoshi);
      }

 }      

}