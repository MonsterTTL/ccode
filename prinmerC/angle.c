#include<stdio.h>
#include<math.h>
#define PI (4*atan(1))
#include"angle.h"

void showStruct(Rect_ji temp)
{
    printf("����Ϊ%lf\n",temp.jijing);
    printf("�������¼���Ϊ%lf\n",temp.jijiao);
    printf("�Ƕ�ֵ�¼���Ϊ%lf",temp.jijiao*(180/PI));
}

Rect_ji RtoJ(Rect test)
{  Rect_ji temp;
   temp.jijing=sqrt(test.x*test.x+test.y*test.y);
   temp.jijiao=atan2(test.x,test.y);
   return temp;
}
