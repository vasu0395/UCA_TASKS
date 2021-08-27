/*
 * Program to implement Deque using Doubly Linked List in C.
 * Compilation : gcc q3.c
 * Execution : ./a.out
 *
 * @vasu ( 1910990395 )  , 23/8/2021
 * Assignment_6 
 *
 */


/*
 * Runtime Complexities of created Functions :
 * push_front()        -> O(1).
 * push_rear()         -> O(1).
 * pop_front()         -> O(1).
 * pop_rear()          -> O(1).
 * peek_front()        -> O(1).
 * peek_rear()         -> O(1).
 * is_empty()          -> O(1).
 * is_present()        -> O(size) as we need to traverse the Linked List to check.
*/


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// struct for deque.
struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
};

// head and tail pointer to provide insert and delete from both end.
struct Node *head;
struct Node *tail;

// Function to initailize deque.
void initailize()
{
    head=NULL;
    tail=NULL;
}

// Function to push_front.
void push_front(int x)
{
    // create temp node using malloc Function.
    struct Node* temp=(struct Node *)malloc(sizeof(struct Node));
    // assign data to temp node.
    temp->data=x;
    temp->next=NULL;
    temp->prev=NULL;
    
    // if it's First Node to insert.
    if(head == NULL)
    {
        // assign head to temp.
        // assign tail to temp
        head = temp;
        tail = temp;
        head->next = NULL;
        head->prev = NULL;
    }
    else
    {
        // assign temp->next to head
        // head->prev  to temp to make link.
        temp->next = head;
        head->prev = temp;
        temp->prev = NULL;
        // assign head to temp.
        head = temp;
    }
    
}

// Function for push_back.
void push_back(int x)
{
    // create temp Node using malloc Function.
    struct Node* temp=(struct Node *)malloc(sizeof(struct Node));
    // assign data to temp node.
    temp->data=x;
    temp->next=NULL;
    temp->prev=tail;
    
    if(tail == NULL)
    {
        // assign head to temp.
        // assign tail to temp
        head = temp;
        tail = temp;
        head->next = NULL;
        head->prev = NULL;
    }
    else
    {
        // add to last of deque.
        tail->next = temp;
        temp->prev = tail;
        temp->next = NULL;
        
        // assign tail to tail->next.
        tail = tail->next;
    }
    
}
// Function for peek_front().
int peek_front()
{
    // if deque is empty.
    if(head==NULL)
    return -1;
    
    return head->data;
}

// Function for peek_back().
int peek_back()
{
    // if deque is empty.
    if(tail==NULL)
    return -1;
    
    return tail->data;
}

// Function to pop_front();
int pop_front()
{
    // base case if deque empty.
    if(head==NULL)
    return -1;
    
    struct Node *temp=head;
    int x=temp->data;
    if(head != NULL)
    {
         head->prev=NULL;
    }
    head=head->next;
    if(head==NULL)
    {
        tail=NULL;
        head=NULL;
    }
    // free memory.
    free(temp);
    
    return x;
}
int pop_back()
{
    // Base case deque empty.
    if(tail==NULL)
    return -1;
    
    struct Node *temp=tail;
    int x=temp->data;
    
    if(tail==head)
    {
        tail=NULL;
        head=NULL;
    }
    else{
    tail = tail->prev;
    // if not last element.
    if(tail != NULL)
    {
        tail->next = NULL;
    }
    }
    // free memory.
    free(temp);
    return x;
}
// Function to check element present or not.
bool present(int x)
{
    // traversal deque and check present or not.
    struct Node *t=head;
    while(t!=NULL)
    {
        // if present.
        if(t->data==x)
        return true;
        t=t->next;
    }
    return false;
}
bool is_empty()
{
    if(head==NULL && tail==NULL)
        return true;
    
    return false;
}
int main() {
    
    initailize();
    push_front(5);
    push_front(6);
    push_front(7);
    push_back(8);
	
    struct Node *t=head;
    printf("linked List :->  ");
    while(t!=NULL)
    {
	printf("%d-->",t->data);
	t=t->next;
    }
    printf("null");
    printf("\n");
	
    pop_front();
    t=head;
    printf("After pop_front linked List :->  ");
    while(t!=NULL)
    {
	 printf("%d-->",t->data);
	 t=t->next;
    }
    printf("null");
    printf("\n");
	
    printf("peek_back() = %d\n",peek_back());
    printf("Peek_front() = %d\n",peek_front());
	
    pop_back();
 	
    t=head;
    printf("After pop_back linked List :->  ");
    while(t!=NULL)
    {
	printf("%d-->",t->data);
	t=t->next;
    }
    printf("null");
    printf("\n");
	
    if(present(6))
	printf("Yes , 6 is present\n");
    else
	printf("No , 6 is not present\n");
	
    pop_back();
    t=head;
    printf("After pop_back linked List :->  ");
    while(t!=NULL)
    {
	 printf("%d-->",t->data);
	 t=t->next;
    }
    printf("null");
    printf("\n");
	
    if(is_empty())
    {
	printf("Yes, deque is empty\n");
    }
    else
    {
	printf("No, deque is not empty\n");
    }
	
    pop_back();
	
    t=head;
    printf("After pop_back linked List :->  ");
    while(t!=NULL)
    {
	 printf("%d-->",t->data);
	 t=t->next;
    }
    printf("null");
    printf("\n");
	
    if(is_empty())
    {
	printf("Yes, deque is empty\n");
    }
    else
    {
	printf("No, deque is not empty\n");
    }
	
    return 0;
}
