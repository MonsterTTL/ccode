#include<stdio.h>
#include<math.h>
#include"angle.h"

int main(void)
{  Rect exam;
   Rect_ji result;
   puts("��ֱ����� X��ֵ��Y��ֵ");
   scanf("%d %d",&exam.x,&exam.y);
   result=RtoJ(exam);
   showStruct(result);
   return 0;


}