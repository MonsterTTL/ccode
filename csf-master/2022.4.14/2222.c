#include <stdio.h>

int main()
{
    char * str[]={"This","is","Xiyou","Moblie"};
    printf("\n%s\n", *str+1);
    char **p =str+1;
    str[0]=(*p++)+2;
    str[1]=*(p+1);
    printf("%s\n",str[0]);
    printf("%s\n",str[1]);
    
    


    return 0;
}