/*
 * Program to Remove Duplicates from Sorted List II.
 * 
 * Compilation : gcc q5.c
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


struct ListNode* deleteDuplicates(struct ListNode* head){
    // create an empty array of size 202 (constrain [-100  , 100]).
    // initialize it with 0.
    int arr[202]={0};
    // create a pointer node temp pointed to head.
    struct ListNode *temp=head;
    // traversal to linked list and mark count of number of times
    // particular number occured (Hashing) .
    while(temp!=NULL)
    {
        int data=temp->val;
        data+=100;
        arr[data]++;
        temp=temp->next;
    }
    
    // creating a demy node
    struct ListNode *demy=(struct ListNode *)malloc(sizeof(struct ListNode));
    demy->val=0;
    demy->next=NULL;
    // creating a pointer prev pointed to demy node
    struct ListNode *prev=demy;
    
    // traversal to linkedlist if value is unique add it into result.
    while(head!=NULL)
    {
        // if value occurs only 1 time , add it into list
        if(arr[head->val + 100]==1)
        {
            struct ListNode *t=(struct ListNode *)malloc(sizeof(struct ListNode));
            t->val=head->val;
            t->next=NULL;
            // prev pointer help in mainting linked list track.
            prev->next=t;
            prev=prev->next;
        }
        head=head->next;
    }
    // return demy next
    return demy->next;
}
