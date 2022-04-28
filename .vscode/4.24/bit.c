int binaryGap(int n){
    for(int i = 0;i < 31 ; i++)
        {
            if(n == (1<<i))
                return 0;
        }
    int rightest = n & ((~n) + 1) ;
    int record = 1;
    int left = 31;
    for(int i = 0;i < 31 ; i++)
        {
            if((rightest >> i) & 0x01 == 1)
                break;
            record++;
        }
    for(int i = 30;i >= 0  ; i--)
        {
            if((n >> i) & 0x01 == 1)
                break;
            left--;
        }
    return (left - record);

}