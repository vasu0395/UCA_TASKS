/*
 * Program to return the node from where cycle begins, if cycle exists, in the singly linked list.
 * 
 * Compilation : gcc q10.c
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
struct ListNode *detectCycle(struct ListNode *head) {
    // create two pointer named slow pointer and fast pointer
    // initally pointed to head
    struct ListNode *slow=head;
    struct ListNode *fast=head;
        
    // base cases when list is an empty or have single element
    if(head==NULL || head->next==NULL)
        return NULL;
    
    // tortoise hare algorithm i.e moving slow by 1 step
    // fast by 2 steps
    while(fast!=NULL && fast->next!=NULL)
    {   
        slow=slow->next;
        fast=fast->next->next;
        
        // if slow pointer equal to fast pointer
        // then it's sure that there is a cycle in linked list.
        if(slow==fast)
        {
            slow = head;
            // cycle detect 
			while(slow != fast)
            {
				slow = slow -> next;
				fast = fast -> next;
			}
			return slow;
        }
    }
    
    // if no cycle detect
    return NULL;
}
