#include<stdio.h>
#include<math.h>
#define MAX 20
#define pie 3.1415926
static float jieceng(float x);
int main(void)
{
    float num;//Ҫ�����
    float result=0;// �����
    float flag=1;//�������Ʒ�
    fputs("������Ҫ���ֵ��������������˳���",stdout);
    fputs("sin:",stdout);
    while(scanf("%f",&num))
    {  result=0;
        num=fmod(num,pie);//�Ը���������ȡ��
      for(int i=1;i<=MAX;i++)
      { 
         result+=flag*pow(num,2*i-1)/jieceng(2*i-1);
         flag=-1*flag;
       
       }
     printf("���Ϊ��%f \n",result);
    }
    fputs("������� ",stdout);
    

}  


float jieceng(float x)//��ײ� 
{
    
    float sum=1;
    int i;
    for(i=1;i<=x;i++)
    {
        sum*=i;
    }
    return sum;
}