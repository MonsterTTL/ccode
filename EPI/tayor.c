#include<stdio.h>
#include<math.h>
#define MAX 20
#define pie 3.1415926
static float jieceng(float x);
int main(void)
{
    float num;//要求的数
    float result=0;// 结果数
    float flag=1;//正负控制符
    fputs("请输入要求的值：（输入其余键退出）",stdout);
    fputs("sin:",stdout);
    while(scanf("%f",&num))
    {  result=0;
        num=fmod(num,pie);//对浮点数进行取余
      for(int i=1;i<=MAX;i++)
      { 
         result+=flag*pow(num,2*i-1)/jieceng(2*i-1);
         flag=-1*flag;
       
       }
     printf("结果为：%f \n",result);
    }
    fputs("程序结束 ",stdout);
    

}  


float jieceng(float x)//求阶层 
{
    
    float sum=1;
    int i;
    for(i=1;i<=x;i++)
    {
        sum*=i;
    }
    return sum;
}