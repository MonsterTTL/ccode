#include <stdio.h>
#include <strings.h>
#include <stdlib.h>
char * longestCommonPrefix(char (* strs)[200], int strsSize);


int main()
{ char strs[][200] = {"sbbbb","sb","sbss"}; 
  char * result;
   result = longestCommonPrefix(strs, 3);
  printf("%s\n",result);



}









char * longestCommonPrefix(char (* strs)[200], int strsSize){
    int x=0,y=0;
    
    while(strs[x][y]==strs[x+1][y]&&(strs[x][y]!='\0'))
      {  x++;
         if(x==strsSize-2)
            { if(strs[x][y]!=strs[x+1][y])
                break;
             y++;
             x=0;}
      }
      
     strs[0][y]='\0';

    return strs[0];

}


