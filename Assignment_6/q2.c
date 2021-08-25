/*
 * Program to implement Queue using Linked List in C.
 * Compilation : gcc q2.c
 * Execution : ./a.out
 *
 * @Vasu ( 1910990395 )  , 23/8/2021
 * Assignment_6
 *
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// create a Node having data and next pointer.
struct Node{
  int data;
  struct Node* next;
};

// head and tail pointer to control linked list operation.
struct Node *head;
struct Node *tail;

// Function to initialize queue.
void initialize_queue()
{
    // initialize head and tail with NULL.
    head = NULL;
    tail = NULL;
}

// Function to check queue is empty or not  O(1) time.
bool is_empty()
{
    // if head is NULL i.e queue is empty.
    if(head==NULL)
    return true;
    else
    return false;
}

// Function to return peek Element of queue O(1) time.
int peek()
{
    // Base case 
    if(head==NULL)
    return -1;
    
    return head->data;
}

// Function to enqueue Element in queue O(1) time.
void enqueue(int val)
{
    // create a newNode of Node type using malloc function.
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    // Base condition when list is empty 
    if(head == NULL)
    {
        // both head and tail point to newNode.
        head = newNode;
        tail = newNode;
    }
    
    else
    {
        // simply add to end of linked list using tail node.
        tail->next = newNode;
        tail = tail->next;
    }
    
    printf("%d Enqueue\n",val);
}

// Function to dequeue Element of queue O(1) time.
int dequeue()
{
    // Base case
    if(head==NULL)
    {
        return -1;
    }
    
    // Store head node to temporary Node
    // move head pointer
    struct Node *temp = head;
    int val = head->data;
    head = head->next;
    // free memory
    free(temp);
    
    printf("%d dequeue\n",val);
    
    return val;
}

void print()
{
    struct Node* node=head;
    while(node!=NULL)
    {
        printf("%d\n",node->data);
        node=node -> next;
    }
}

int main() {
    initialize_queue();
    
    enqueue(5);
    enqueue(6);
    enqueue(7);
    enqueue(8);
    
    dequeue();
    
    printf("Peek Element %d\n",peek());
    
    dequeue();
    
    printf("Is Empty Queue ? ");
    if(is_empty())
    printf("YES\n");
    else
    printf("NO\n");
   
    dequeue();
    dequeue();
    
    printf("Is Empty Queue ? ");
    if(is_empty())
    printf("YES\n");
    else
    printf("NO\n");
	
    return 0;
}
