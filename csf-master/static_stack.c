#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct static_stack{
    int data[MAX];
    int cur ;
}STACK;

typedef enum Stack_Status{
    Stack_OK = 1,
    Stack_Error = 0
}STACK_STATUS;


STACK * stack_init(void);
int stack_pop(STACK * temp);
int stack_push(STACK * temp,int number);
void stack_showalldata(STACK * temp);
int stack_delete(STACK * temp);
int stack_length(STACK * temp);

int main(void)
{
    STACK * use = stack_init();
    char test[MAX] = {"([])({})"} ;
    char * temp = test;
    int flag = 0;
    while(*temp != '\0')
    {
        switch(*temp)
        {
            case '(' :stack_push(use,'(');break;
            case '{' :stack_push(use,'{');break;
            case '[' :stack_push(use,'[');break;
            case ')' : if(stack_pop(use) != '(')
                        {
                            flag = 1;
                        }
                        break;
            case '}' : if(stack_pop(use) != '{')
                        {
                            flag = 1;
                        }
                        break;
            case ']' : if(stack_pop(use) != '[')
                        {
                            flag = 1;
                        }
                        break;
        }

        temp++;
    }
    if(flag == 1)
        printf("false");
    else
        printf("true");
  
    return 0;
}

STACK * stack_init(void)
{
    STACK * ret = (STACK *)(malloc(sizeof(STACK)));
    ret -> cur = -1;
    return ret;
}

int stack_pop(STACK * temp)
{
    if(temp -> cur <= -1)
        return -9999;
    int ret = temp -> data[temp -> cur] ;
    temp -> cur --;
    return ret ;
}

int stack_push(STACK * temp,int number)
{
    if(temp -> cur >= MAX)
        return -1;
    temp -> cur++;
    temp -> data[temp -> cur] = number;
    return 1;
}

int stack_delete(STACK * temp)
{
    free(temp);
    return 1;
}

void stack_showalldata(STACK * temp)
{
    while(temp -> cur >= 0)
        {
            printf("%d ",temp -> data[temp -> cur]);
            temp -> cur--;
        }
    printf("\n");
    return ;
}

int stack_length(STACK * temp)
{
    return (temp -> cur + 1) ;
}
