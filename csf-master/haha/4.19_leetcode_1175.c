#define MAX 1000000007

int numberofprime(int x);
int Is_Prime(int x);


int numPrimeArrangements(int n){
    long int number = numberofprime(n);
    long int other = (n - number);
    long int ret = 1;
    while(number - 1 > 0 && other - 1 > 0)
        {
            
            ret *= (number );
            ret *= (other );
            number--;
            other--;
            ret %= MAX;
        }
    while(number - 1 > 0)
        {
            
            ret *= (number );
            number--;
            ret %= MAX;
        }
    while(other - 1 > 0)
        {
            
            ret *= (other );
            other--;
            ret %= MAX;
        }
    
    return (ret) ;
}





int Is_Prime(int x)
{   if(x <= 1)
        return 0;
    int area = sqrt(x);
    int use ;
    for(int i = 2; i <= area; i++)
        {
            use = x % i;
            if(use == 0)
                return 0;
        }
    return 1;
}

int numberofprime(int x)
{
    int ret = 0;
    for(int i = 1;i <= x;i++)
        {
            if(Is_Prime(i))
                ret++;
        }
    return ret;
}