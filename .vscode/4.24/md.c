#include <stdio.h>

int sum1(int a ,int b)  ;
int mult(int a , int b);
  int mins(int a,int b);
  int devide_2times(int a , int b);
   int devide(int devided,int devider);

int main()
{
  int a = devide(32,-4);
  printf("%d" , a);
}

int sum1(int a ,int b)  
  {    
       
       int ret = (a ^ b);//用于记录无进位相加
       int yichu = (a & b) << 1 ;//用于管理进位
       int temp ;
       while(yichu != 0)
        {
           temp = ret; 
           ret = ret ^ yichu ;
           yichu = (temp & yichu) << 1;
            
        }
       return ret ;

  }


   int mult(int a , int b)
    {   
        int flag = 1;
        if(a < 0)
            {
                a = (~a) + 1;//若为负数，则转化为正数
                flag = -flag; //控制符号正负
            }
        if(b < 0)
            {
                b = (~b) + 1;
                flag = -flag;
            }
        if(a == 0 || b == 0)
            return 0;//考虑乘数为0时
        int ret = 0;
        while(b)
            {
                if(b & 0x01)
                {
                    ret = sum1(ret , a);
                }
                a <<= 1;   //进行加权左移
                b >>= 1;
            }
        if(flag == 1)
            return ret;
        else
            return -ret;
        
    }


    int mins(int a,int b){ 

        return (sum1(a,(~b) + 1)) ;
    }


     int devide_2times(int a , int b)
    {
        int flag = 1;
        if(a == 0 ||b == 0)
            return 0;
        if(a < 0)
            {
                a = (~a) + 1;
                flag = -flag;
            }
         if(b < 0)
            {
                b = (~b) + 1;
                flag = -flag;
            }
        while(b != 0x01)
            {
                a >>= 1;
                b >>= 1;
            }
        if(flag == 1)
            return a;
        else
            return -a;
       
    }


    int devide(int devided,int devider)
      {
          if(devided == 0 || devider == 0)
            return 0;
          int flag = 1;
          int n = 0;
          int ret = 0;
          if(devided < 0)
            {
                flag = -flag;
                devided = (~devided) + 1;
            }
          if(devider < 0)
            {
                flag = -flag;
                devider = (~devider) + 1;
            }
          while(devided >= devider)
            {   
                if((devided >> (30 - n)) >= devider)  
                   {
                       ret = sum1(ret , (1 << (30 - n)));
                       devided = mins(devided,devider<<(30 - n));
                       
                   }
                n++;
            }
            if(flag == 1)
                return ret;
            else
                return -ret;  
      }
