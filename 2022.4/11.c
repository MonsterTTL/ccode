#include<stdio.h>

char * test(void)
{
   static char std[10]="hello!";
    
    
    printf("%s",std);
    return std;

}



int main()
{char * temp;
  temp= test();
  temp[1]='a';
  test();
  printf("\"\"");
  return 0;
}
