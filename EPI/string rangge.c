#include <stdio.h>
#include <strings.h>
#define MAX 50

int main(void)
{   char letter[5][MAX];
    char linshi[MAX];
    char linshi2[MAX];
    for(int i=0;i<5;i++)
     scanf("%s",letter[i]);
    
    for(int i=0;i<5;i++)
     {strcpy(linshi,letter[i]) ;
          for(int z=i;z<5;z++)
       {    
           if(strcmp(linshi,letter[z])>0) 
           { strcpy(linshi2,linshi);
             strcpy(linshi,letter[z]);
             strcpy(letter[z],linshi2); 

           }

       }
       strcpy(letter[i],linshi);
     }  
    for(int i=0;i<5;i++)
     {
         puts(letter[i]);
     }
    


   
}