#include <string.h>
#include <stdio.h>

int main (void)
{
    char a = 'A';
    char * result;
    result = strchr("aeiouAEIOU",a);
    if( result != NULL)
        printf("yes");
    else 
    {
        printf("no");
    }
    

}

void reverseString(char* s, int sSize){
    int cot = sSize >> 1;
    int c2;
    for(int i = 0; i < cot ; i++)
        {
            c2 = (sSize - 1 -i);
            s[i] = s[i] ^ s[c2];
            s[c2] = s[i] ^ s[c2];
            s[i] = s[c2] ^ s[i];
        }
    return ;

}