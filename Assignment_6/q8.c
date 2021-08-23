/*
 * Program for Merge Two Sorted Lists.
 * 
 * Compilation : gcc q8.c
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


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    // recursive implement merge two sorted list
    
    // if first list becomes empty return second list
    if (l1 == NULL) return l2;
    // if second list becomes empty return first list
    if (l2 == NULL) return l1;
    
    // if value of first list pointer lesser than value of second list pointer
    // attached remaining lists with next of first pointer
    if (l1->val < l2->val)
    {
        l1->next = mergeTwoLists(l1->next, l2);
        return l1;
    }
    // if value of first list pointer greater than or equal to value of second list     
    // attached remaining lists with next of second pointer
    else
    {
        l2->next = mergeTwoLists(l1, l2->next);
        return l2;
    }
}
