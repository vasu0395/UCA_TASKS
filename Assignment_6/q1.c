/*
 * Program to implement stack using linked list.
 * 
 * Compilation : gcc q1.c
 * Execution : ./a.out
 *
 * @vasu , (1910990395) , 23/08/21 .
 * Assignment_6
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
// create stack using linked list
struct ListNode {
    int data;
    struct ListNode* next;
};
// function for check if stack is empty or not
bool is_empty(struct ListNode *head)
{
    printf("Is stack empty ? ");
    // if head pointed to NULL means no elements in stack
    if(head==NULL)
    return true;
    else
    return false;
}
// function for return peek element of stack
int peek(struct ListNode *head)
{
    // base condition if stack is empty
    if(head==NULL)
    return -1;
    return head->data;
}
// function for pop element of stacks
int pop(struct ListNode **head)
{
    // creating pointer t pointed to head 
    struct ListNode *t=*head;
    // base condition if stack is empty
    if(t==NULL)
    return -1;
    
    // if only 1 element into stack
    if(t->next==NULL)
    {
        int x=t->data;
        printf("%d Pop from stack\n",x);
        *head=NULL;
        // free to remove memory allocated
        free(t);
        return x;
    }
    
    int val=t->data;
    t=*head;
    // increment next pointer using new_head pointer
    struct ListNode *new_head=*head;
    new_head=new_head->next;
    *head=new_head;
    
    t->next=NULL;
    free(t);
    
    printf("%d Pop from stack\n",val);
    return val;
}
// function for push element into stack
void push(struct ListNode **head,int val)
{
    printf("%d Push into stack\n",val);
    // create new node using malloc function
    struct ListNode *temp=(struct ListNode *)malloc(sizeof(struct ListNode));
    // assign data to node
    temp->data=val;
    temp->next=NULL;
    
    if(head!=NULL)
    temp->next=*head;
    
    // assign temp node to head
    *head=temp;
}
// function to print stack data
void print(struct ListNode **head)
{
    printf("Elements of LinkList :\n");
    struct ListNode* t=*head;
    while(t!=NULL)
    {
        printf("%d\n",t->data);
        t=t->next;
    }
}
int main() {
    struct ListNode *node=NULL;
    push(&node,5);
    push(&node,6);
    push(&node,7);
    push(&node,8);
    
    print(&node);
    
    pop(&node);
    pop(&node);
    
    printf("Peek Element is %d\n",peek(node));
    if(is_empty(node))
    printf("YES\n");
    else
    printf("NO\n");
    
    pop(&node);
    pop(&node);
    
    if(is_empty(node))
    printf("YES\n");
    else
    printf("NO\n");
    
    return 0;
}
