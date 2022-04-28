#include <stdio.h>
#include <stdlib.h>






struct ListNode {
    int val;
   struct ListNode *next;
 };


int main(void)
{

}







struct ListNode* deleteMiddle(struct ListNode* head){
    struct ListNode * slow = head ;
    struct ListNode * fast = head -> next;
    struct ListNode * use ;
    while(fast  != NULL)
        {
            fast = fast -> next ;
            if (fast == NULL || fast -> next == NULL)
                break;
            fast = fast -> next;
            slow = slow -> next;
        }
    use = slow -> next;
    if(slow -> next != NULL)
     {slow -> next = slow -> next -> next;
     free(use);
     } 
     else
     {
        return NULL;
       
     }
    
    return head;
}



struct ListNode* deleteMiddle_plus(struct ListNode* head){
    if(head -> next == NULL)
        return NULL;
    struct ListNode * slow = head ;
    struct ListNode * fast = head ;
    struct ListNode * pre ;
    while(fast != NULL && fast -> next != NULL)
        {
            pre = slow;
            fast = fast -> next -> next;
            slow = slow -> next;
        }
    pre -> next = slow -> next;
    free(slow);
    return head;
}