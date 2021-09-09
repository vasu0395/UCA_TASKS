#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "hashmap.h"

// Implement Hash_map Data structure using open addressing and linear probing.
// By default Hash_map SIZE 200.
#define SIZE 200

bool flag=true;
// varible to keep map_element_count

int map_element_count=0;
// Hash_map structure having 3 information key , data and count_of_occurrence.

struct Hash_map{
    int key;
    void* data;
    int count_of_occurrence;
};

// creating an Hash_map_array of struct type.
struct Hash_map* Hash_map_array[SIZE];

void initalize_hashmap(int choice)
{
    if(choice==1)
    {
        flag=true;
        printf("Hashmap of (INT , INT) created .\n");
    }
    else
    {
        flag=false;
        printf("Hashmap of (INT , CHAR) created .\n");
    }
}
// Function to return Hash_index ( O(1) Time complexity ).
int Hash_index(int val)
{
    return (val + SIZE)%SIZE;
}

// Function to return maximum size of Hash_map_array.
void Max_Element_store()
{
    printf("Map_default_size is %d\n",SIZE);
}

// Function to return current element count in Hash_map_array.
void Map_Size()
{
    printf("Map_Element_count is %d\n",map_element_count);
}

// Function to find key present or not in Hash_map_array ( O(SIZE) Time complexity in Worst ).
struct Hash_map * serach(int key,int call)
{
    // Finding Hash_index corresponding to key.
    int Hash_insert_index=Hash_index(key);
    
    // if Hash_map_array[Hash_insert_index] is not NULL.
    // keep checking untill we found empty (NULL) Node .
    while(Hash_map_array[Hash_insert_index]!=NULL)
    {
        // if value is find then key corresponding to Hash_map_array[Hash_insert_index] == key. 
        if(Hash_map_array[Hash_insert_index]->key == key)
        {
            if(!call)
            printf("%d Key present in Hash_map\n",key);
            // return Hash_map Node corresponding to Hash_map_array[Hash_insert_index].
            return Hash_map_array[Hash_insert_index];
        }
         // increment Hash_insert_index by 1.
        Hash_insert_index++;
        // Finding new Hash_insert_index using modulus operation.
        Hash_insert_index=(Hash_insert_index + SIZE)%SIZE;
    }
    if(!call)
    printf("%d Key not present in Hash_map\n",key);
    
    // if Hash_map_array[Hash_insert_index]== NULL i.e value Not present. 
    return NULL;
}


// Function to update data corresponding to key.
void update(int key,void* value)
{
    bool character_present=false;
    if(flag)
    {
        if(*(char*)(value)>='a' && *(char*)(value)<='z')
        {
            printf("Error Found : Expected value of type 'INT' found 'CHAR' (%d ,' %c ') is not updated .\n",key,*(char*)value);
            return;
        }
        if(*(char*)(value)>='A' && *(char*)(value)<='Z')
        {
            printf("Error Found : Expected value of type 'INT' found 'CHAR' (%d ,' %c ') is not updated .\n",key,*(char*)value);
            return;
        }
    }
    else
    {
        if(*(char*)(value)>='a' && *(char*)(value)<='z')
        {
            character_present=true;
        }
        if(*(char*)(value)>='A' && *(char*)(value)<='Z')
        {
            character_present=true;
        }
        if(*(char*)(value)>='0' && *(char*)(value)<='9')
        {
            character_present=true;
        }
    }
    
    if(!flag && !character_present)
    {
        printf("Error Found : Expected value of type 'CHAR' found 'INT' (%d , %d ) is not updated .\n",key,*(int*)value);
        return;
    }
    // first check weather key present in Hash_map_array or not.
    struct Hash_map* temp=serach(key,1);
    // if Not present , then insert into Hash_map_array.
    if(temp==NULL)
    {
        // insert key and value to Hash_map_array.
        insert(key,value);
    }
    else
    {
        // update data corresponding to key.
        temp->data=value;
        // increment count_of_occurrence by 1.
        temp->count_of_occurrence+=1;
        if(flag)
        printf("(%d , %d) updated in Hash_map\n",temp->key,*(int*)temp->data);
        else
        printf("(%d ,' %c ') updated in Hash_map\n",temp->key,*(char*)temp->data);
    }
    return;
}

// Function to insert Key into Hashmap using open addressing ( O(1) average & O(map_element_count) Worst ).
void insert(int key,void* data)
{
    struct Hash_map *check_exit=serach(key,1);
    if(check_exit!=NULL)
    {
        update(key,data);
        return;
    }
    
    bool character_present=false;
    if(flag)
    {
        if(*(char*)(data)>='a' && *(char*)(data)<='z')
        {
            printf("Error Found : Expected value of type 'INT' found 'CHAR' (%d ,' %c ') is not inserted .\n",key,*(char*)data);
            return;
        }
        if(*(char*)(data)>='A' && *(char*)(data)<='Z')
        {
            printf("Error Found : Expected value of type 'INT' found 'CHAR' (%d ,' %c ') is not inserted .\n",key,*(char*)data);
            return;
        }
        if(*(char*)(data)>='0' && *(char*)(data)<='9')
        {
            printf("Error Found : Expected value of type 'INT' found 'CHAR' (%d ,' %c ') is not inserted .\n",key,*(char*)data);
            return;
        }
    }
    else
    {
        if(*(char*)(data)>='a' && *(char*)(data)<='z')
        {
            character_present=true;
        }
        if(*(char*)(data)>='A' && *(char*)(data)<='Z')
        {
            character_present=true;
        }
        if(*(char*)(data)>='0' && *(char*)(data)<='9')
        {
            character_present=true;
        }
    }
    
    if(!flag && !character_present)
    {
        printf("Error Found : Expected value of type 'CHAR' found 'INT' (%d , %d ) is not inserted .\n",key,*(int*)data);
        return;
    }
    
    // creating a struct Node using malloc Function.
    struct Hash_map* temp=(struct Hash_map*)malloc(sizeof(struct Hash_map));
    // assign key , data and count_of_occurrence to Node. 
    temp->key=key;
    temp->data=data;
    temp->count_of_occurrence=1;
    // Finding Hash_index corresponding to key.
    int Hash_insert_index=Hash_index(key);
    
    // increment Hash_insert_index untill there is a NULL corresponding to Hash_insert_index.
    // if delete operation perform prior then key corresponding to Hash_insert_index is -1.
    while(Hash_map_array[Hash_insert_index]!=NULL && Hash_map_array[Hash_insert_index]->key!=-1)
    {
        // increment Hash_insert_index by 1.
        Hash_insert_index++;
        // Finding new Hash_insert_index using modulus operation.
        Hash_insert_index=(Hash_insert_index + SIZE)%SIZE;
    }
    // assign value to Hash_map_array.
    Hash_map_array[Hash_insert_index]=temp;
    // increment map_element_count by 1.
    map_element_count++;
    
    if(flag)
    printf("(%d , %d) inserted in Hash_map\n",key,*(int*)data);
    else
    printf("(%d ,' %c ') inserted in Hash_map\n",key,*(char*)data);
}

// Function to clear Hash_map_array. ( O(N) Time complexity. ).
void clear()
{
    // iterate over Hash_map_array.
    for(int i=0;i<SIZE;i++)
    {
        // if Hash_map_array[i] is not NULL.
        if(Hash_map_array[i]!=NULL)
        {
            struct Hash_map *temp=Hash_map_array[i];
            free(temp);
            // Assign NULL to Hash_map_array.
            Hash_map_array[i]=NULL;
        }
    }
    map_element_count=0;
    printf("Hashmap clear successfully \n");
    return;
}

// Function to erase key in Hash_map.
void erase(int key)
{
    // first check weather key present in Hash_map_array or not.
    struct Hash_map* temp=serach(key,1);
    // if Not present , then print warning for user.
    if(temp==NULL)
    {
        printf("%d Key Not present in Hash_map_array\n",key);
    }
    else
    {
        printf("%d Key erase from Hash_map_array\n",key);
        // mark key to -1.
        temp->key=-1;
        // mark count_of_occurrence to 0.
        temp->count_of_occurrence=0;
        map_element_count--;
    }
    return;
}

// Function to check weather Hash_map_array is empty or Not ( O(1) Time complexity ).
void empty()
{
    // if map_element_count is 0, return true.
    if(map_element_count == 0)
    printf("Yes, Hash_map is empty\n");
    
    // else if Hash_map_array contain element.
    printf("No, Hash_map is not empty\n");
}

void display() {
   int i = 0;
   for(i = 0; i<SIZE; i++) {
	
      if(flag && Hash_map_array[i] != NULL && Hash_map_array[i]->key!=-1)
         printf("(%d,%d)\n",Hash_map_array[i]->key,*(int*)Hash_map_array[i]->data);
    
      if(!flag && Hash_map_array[i] != NULL && Hash_map_array[i]->key!=-1)
         printf("(%d,'%c')\n",Hash_map_array[i]->key,*(char*)Hash_map_array[i]->data);
   }
	
   printf("\n");
}
