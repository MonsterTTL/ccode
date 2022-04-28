#include <stdio.h>
#include  <stdlib.h>


char * strcpy_s(char * p1,char *p2)
{ 
    int i=0;
    while((*p2)!='\0')
   {
     (*p1)=(*p2);
     p1++;p2++;
      
   }
   return p1;
}



int main()
{   char arr[12];
    strcpy_s(arr,"hello");
    printf("%s",arr);


}