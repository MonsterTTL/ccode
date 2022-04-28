#include <stdio.h>
#include <stdlib.h>

int solution1(int N ,int start,int aim ,int step);
int process1(int cur,int rest,int aim,int N);
int solution2(int N ,int start,int aim ,int step);
int process2(int cur,int rest,int aim,int N,int **dp);


//机器人走路，一次走一步，一共有多少种走法；
int main()
{   
    int test = solution2(7,2,4,4);//solution1(7,2,4,8);
    printf("%d \n",test);
    //ss();


}
// void ss(void)
// {
//     int arr[5][6];
//     for(int i = 0;i < 5;i++)
//         for(int x = 0 ; x < 6; x++)
//             printf("%d ",arr[i][x]);
// }

int solution1(int N ,int start,int aim ,int step)
{
    return  process1(start,step,aim,N);
}

int process1(int cur,int rest,int aim,int N)
{
    if(rest < 1)
        if (cur == aim)
            return 1;
        else
            return 0;
    if(cur == 1)
        {
            return process1(cur+1,rest-1,aim,N);
        }
    else if(cur == N)
        {
            return process1(cur-1,rest-1,aim,N);
        }
    return process1(cur-1,rest-1,aim,N) + process1(cur+1,rest-1,aim,N);
}

int solution2(int N ,int start,int aim ,int step)
{
   int ** dp = (int **)malloc(sizeof(int)*(N+1)*(step+1));//[N+1][step+1] ;
   printf("yes");
   for(int i = 0;i < N+1 ;i++)
        for(int x = 0; x < step +1;x++) 
            dp[i][x] = -1;  //dp[i][x] == -1 ,说明之前没算过
    
    return process2(start,step,aim,N,dp);
    
}

int process2(int cur,int rest,int aim,int N,int **dp)
{
    if(dp[cur][rest] != -1)
        return dp[cur][rest] ;
    int cns = 0;
    if(rest < 1)
        cns = (cur == aim ? 1 : 0);
    if(cur == 1)
        cns = process2(cur+1,rest-1,aim,N,dp);
    else if(cur == N)
        cns = process2(cur-1,rest-1,aim,N,dp);
    else
        cns = process2(cur-1,rest-1,aim,N,dp)+process2(cur+1,rest-1,aim,N,dp);  //分享一张表
    dp[cur][rest] = cns;
    return cns ;
    
    // if(rest < 1)
    //     if (cur == aim)
    //         return 1;
    //     else
    //         return 0;
    // if(cur == 1)
    //     {
    //         return process1(cur+1,rest-1,aim,N);
    //     }
    // else if(cur == N)
    //     {
    //         return process1(cur-1,rest-1,aim,N);
    //     }
    // return process1(cur-1,rest-1,aim,N) + process1(cur+1,rest-1,aim,N);
}


