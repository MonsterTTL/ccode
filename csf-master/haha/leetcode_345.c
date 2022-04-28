#include <stdio.h>
#include <stdlib.h>



#define yuanyin "aeiouAEIOU"


char * reverseVowels(char * s){
    int end = strlen(s) - 1;
    int start = 0;
    //char * use;
    while(start < end)
        {
            if(strchr(yuanyin,s[start]) == NULL)
                {
                    start++;
                }
            else if(strchr(yuanyin,s[end]) == NULL)
                {
                    end--;
                }
            else
                {
                    s[start] = s[start] ^ s[end];
                    s[end] = s[end] ^ s[start];
                    s[start] = s[start] ^ s[end];
                    start++; end--;
                }
            
        }
    return s;

}


