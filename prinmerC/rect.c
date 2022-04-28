//极坐标转化
#include<stdio.h>
#include<math.h>
#include"angle.h"
#include<strings.h>


int main(void)
{  Rect exam;
   Rect_ji result;
   puts("请分别输入 X的值和Y的值");
   scanf("%lf %lf",&exam.x,&exam.y);
   result=RtoJ(exam);
   showStruct(result);
   return 0;


}


