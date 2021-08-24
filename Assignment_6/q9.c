/*
 * Program to Rotate List.
 * 
 * Compilation : gcc q9.c
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


struct ListNode* rotateRight(struct ListNode* head, int k){
    // Base condition. 
    if(head==NULL || k==0)
            return head;
    // countNodes -- size of linked list.
    // count -- rotation count.
    int countNodes=0, count=0;
    // create node pointer pointed to head.    
    struct ListNode *node = head;
    struct ListNode *prev, *curr, *newRoot;
    prev=curr=newRoot= head;
    // End of linked list is Null pointer.
    while(node!=NULL)
    {
        prev = node;
        node = node->next;
        countNodes++;
    }
    // make Linked list circular
    prev->next = head;  
    // count rotation needed
    count = countNodes - (k%countNodes);       
    // decrement count by 1 and placed curr pointer to its next
    // keep track of previous curr to break circular loop.
    while(count!=0)
    {
        prev = curr;
        curr = curr->next;
        count--;
    }
    // break circular loop.
    prev->next = NULL;
    // return curr pointed.
    return curr;
}
