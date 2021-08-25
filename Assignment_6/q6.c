/*
 * Program for Remove Nth Node From End of List.
 * 
 * Compilation : gcc q6.c
 * Execution : ./a.out
 *
 * @vasu , (1910990395) , 23/08/21 .
 * Assignment_6
 */


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode *slow=head;
    struct ListNode *fast=head;
        
    // Base cases when list is empty or contain 1 element.
    if(head==NULL || head->next==NULL)
        return NULL;
        
    // First cover n distance with fast pointer.
    while(fast!=NULL && n)
    {
        fast=fast->next;
        n--;
    }
        
    // Now moving both pointer by single step.
    // After this fast pointer point to end(last) element.
    while(fast!=NULL && slow!=NULL)
    {
        fast=fast->next;
        slow=slow->next;
    }
        
    // check if it's not a last element
    // if not simply copy data of next
    // now place slow->next to slow->next->next to skip link. 
    if(slow->next!=NULL){
        slow->val=slow->next->val;
        slow->next=slow->next->next;
    }
    else
    {
        // if we have to delete last element
        struct ListNode *temp=head;
        // travel linkedlist and make last NULL.
        while(temp->next!=slow)
        {
            temp=temp->next;
        }
        temp->next=NULL;
    }
    // return head.
    return head;
}
