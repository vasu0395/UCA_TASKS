/*
 * Program to implement stack using linked list.
 * 
 * Compilation : gcc q4.c
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

bool isPalindrome(struct ListNode* head){
    // Base cases.
    if(head==NULL || head->next==NULL)
        return true;
    // creating two pointer and finding middle of it.
    struct ListNode* slow=head;
    struct ListNode* fast=head;
    // find middle of linked list.
    while(fast->next!=NULL && fast->next->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    // if length of linked list is odd.
    if(fast->next==NULL)
    {
        // reverse the second half of list to check palindrome.
        struct ListNode* pre=NULL;
        struct ListNode* curr=slow->next;
        // reverse list till end
        while(curr!=NULL)
        {
            // to reverse to link. 
            // first break next link and point it to prev node.
            // then assign prev to curr.
            // curr to curr next.
            struct ListNode* ne=curr->next;
            curr->next=pre;
            pre=curr;
            curr=ne;
        }
        // make link with attached with middle of linked list.
        slow->next=pre;
        // make pointer p1 assign to head.
        // p2 to next of middle of linked list.
        struct ListNode* p1=head;
        struct ListNode* p2=slow->next;
        while(p2!=NULL)
        {
            // if not equals.
            if(p1->val != p2->val)
                return false;
            p2=p2->next;
            p1=p1->next;
        }
        // if it's palindrome.
        return true;
    }
    else{
        // if length of linked list is even.
        // reverse the second half of list to check palindrome.
        struct ListNode* pre=NULL;
        struct ListNode* curr=slow->next;
        // reverse list till end
        while(curr!=NULL)
        {
            // to reverse to link. 
            // first break next link and point it to prev node.
            // then assign prev to curr.
            // curr to curr next.
            struct ListNode* ne=curr->next;
            curr->next=pre;
            pre=curr;
            curr=ne;
        }
        // make link with attached with middle of linked list.
        slow->next=pre;
        // make pointer p1 assign to head.
        // p2 to next of middle of linked list.
        struct ListNode* p1=head;
        struct ListNode* p2=slow->next;
        while(p2!=NULL)
        {
            if(p1->val != p2->val)
                return false;
            p2=p2->next;
            p1=p1->next;
        }
        return true;
    }
}
