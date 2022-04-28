#include <stdio.h>
#include <stdlib.h>

int divide(int a, int b);

int main()
{
    int test = divide(999,333);
    printf("%d" , test);
}


int divide(int a, int b){
    if(a==0 || b==0)
        return 0;
    int flag = 1;
    long long int first = a,second = b;
    if(first <= (int)(0x80000000) && abs(second) == 1)
        {
            if(second==1)
                return ((int)(0x80000000));
            else 
                return ((int)(0x7fffffff));
        }
    if(first < 0)
        {
            first = (~first) + 1;
            flag = -flag;
        }
    if(second < 0)
        {
            second = (~second) + 1;
            flag = -flag;
        }
    //first = a; second = b;
    if(first < second)
        return 0;
    long int bitsum = 1;
    int firstbit = 0;
    while(bitsum <= first)
        {
            bitsum <<= 1; 
            firstbit ++;
        }
    long long int ans = 0,reminder = 0;
    while(firstbit--)
        {
            bitsum >>= 1;
            reminder <<= 1;
            reminder |= (first >> firstbit)&0x01;
            if(reminder >= second)
                {
                    reminder -= second;
                    ans |= bitsum;
                }

        }
    if(flag == 1)
        return ans;
    else
        return -ans;
    
    

}