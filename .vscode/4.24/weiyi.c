#include <stdio.h>
#include <stdlib.h>

int bitCount(int a);
long long muliti(int x1,int x2);

int main()
{    
     int test = muliti(7,8);
     printf("%d",test);

}


long long muliti(int num1, int num2)
{
	if (num1 == 0 || num2 == 0)
	{
		return 0;
	}

	int sign = 0;
	if (num1 < 0 && num2 < 0 ||
		num1 > 0 && num2 > 0)
	{   //记录结果符号
		sign = 1;
	}
	long long first  = abs((long long)num1);
	long long second = abs((long long)num2);

	if (first < second)
	{   //操作小的num2，逐位判断
		long long temp = first;
		first = second;
		second = temp;
	}
	
	//两个int相乘不能超过一个longlong的范围，防溢出
	long long ans = 0;		
	for (size_t i = 0; i < 32; i++)
	{	//从低位取值
		int isOne = (second >> i) & 0x01;
		if (isOne)
		{
			ans += first << i;
		}
	}
	
	return sign ? ans : -ans;
}


int bitCount(int a)
{
    int x = 1;
    while( a >>= 1)
        {
            x++;
        }
    return x;
}