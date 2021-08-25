/*
 * Program for Reverse Linked List II.
 * 
 * Compilation : gcc q7.c
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


struct ListNode* reverseBetween(struct ListNode* head, int m, int n){
    // Base case
    if (head == NULL) {
        return NULL;
    }

    // Move the two pointers until they reach the proper starting point
    // in the list.
    struct ListNode *cur = head, *prev = NULL;
    while (m > 1) {
        prev = cur;
        cur = cur->next;
        m--;
        n--;
    }
        
    // The two pointers that will fix the final connections.
    // Tail pointer help in maintain remain half of linked list after reverse done.
    struct ListNode *con = prev, *tail = cur;

    // Iteratively reverse the nodes until n becomes 0.
    struct ListNode *third = NULL;
    while (n > 0) {
        third = cur->next;
        cur->next = prev;
        prev = cur;
        cur = third;
        n--;
    }
  
    // if reversing is not from head then con pointed to other element.
    // else simply assign prev to head. 
    if (con != NULL) {
        con->next = prev;
    } else {
        head = prev;
    }
    
    // attached reamining part of list.
    tail->next = cur;
    return head;
        
}
