#include <stdio.h>
// <stdlib.h> for using malloc function.
#include <stdlib.h>
// <stdbool.h> for using bool return type.
#include <stdbool.h>

// Function to swap values of array.
void swap(void **a,int i,int j)
{
    void *t=a[i];
    a[i]=a[j];
    a[j]=t;
}

// Function to reverse array.
void reverse(void **a,int l,int h)
{
    while(l<=h)
    {
        // swap lower and higher index of array to reverse.
        swap(a,l,h);
        l++;
        h--;
    }
}

// Function to merge two sorted array.
void merge(void **a, int L, int mid, int R, void **b, int(*cmp)(void *, void *)){
    int k = L;
    int i = L;
    int j = mid+1;
    while(k<=R){
        // if lower index greater than mid simply copy content of a[j].
	if(i>mid) b[k++] = a[j++];
	// if higher index greater than R simply copy content of a[i].
	else if (j>R)  b[k++] = a[i++];
	// check for comparsion and assign value if a[i] > a[j].
	else if ((*cmp)(a[i], a[j]) > 0) b[k++] = a[j++];
	else b[k++] = a[i++];

    }
    // assign value to array a.
    for(k = L; k<=R;k++)
	a[k] = b[k];
}

// Function to merge_sort array.
void merge_sort(void **a, int L, int R, void **b, int(*cmp)(void *, void *)){
    // base case.
    if (L == R) return;
    // finding mid 
    int mid = (L+R)/2;
    // divide array into 2 halves
    // merge_sort first half [low,mid]
    merge_sort(a, L, mid, b,cmp);
    // merge_sort second half [mid+1,high]
    merge_sort(a, mid+1, R, b,cmp);
    // merge both sorted halves.
    merge(a,L,mid, R, b, cmp);
}

// Function to calculate upper_bound of x in array.
void* upper_bound(void** arr,int n,void* x)
{
    // base case if values present in array is lower than or equal x
    if(*(char *)arr[n-1]<=*(char *)x)
    {
        void *temp=(void *)malloc(sizeof(void *) * 1);
        int y=-1;
        temp=&y;
        return temp;
    }
    // implement binary search
    // finding next greater value of x.
    int low=0;
    int high=n-1;
    int ans=-1;
    // implement binary search assign low=0 and high=n-1.
    while(low<=high)
    {
        int mid=(low + high)/2;
        // if value of mid is less or equal increment low by mid + 1.
        if(*(char *)arr[mid]<=*(char *)x)
        {
            low=mid + 1;
        }
        // update value of ans and assign value of mid.
        // if value of mid is greater decrease high by mid - 1.
        else
        {
            ans=mid;
            high=mid - 1;
        }
    }
    // return value.
    return arr[ans];
}

// Function to calculate lower_bound of x in array.
void* lower_bound(void** arr,int n,void* x)
{
    // base case if values present in array[0] is lower than x
    if(*(char *)arr[n-1]<*(char *)x)
    {
        void *temp=(void *)malloc(sizeof(void *) * 1);
        int x=-1;
        temp=&x;
        return temp;
    }
    int low=0;
    int high=n-1;
    int ans=-1;
    // implement binary search
    // finding next greater or equal value of x.
    while(low<=high)
    {
        int mid=(low + high)/2;
        // if x is present in array return.
        if(*(char *)arr[mid]==*(char *)x)
        {
            return arr[mid];
        }
        // if value of mid is less increment low by mid + 1
        else if(*(char *)arr[mid]<*(char *)x)
        {
            low=mid + 1;
        }
        // update value of ans and assign value of mid.
        // if value of mid is greater decrease high by mid - 1.
        else
        {
            ans=mid;
            high=mid - 1;
        }
    }
    // return ans.
    return arr[ans];
}

// Function to return count of element x in array.
int count(void** arr,int n,void* x)
{
    // ans variable to count occurrence of x in array.
    int ans=0;
    // perform linear search and increment count.
    for(int i=0;i<n;i++)
    {
        // if value equal to x increment ans by 1.
        if(*(char *)arr[i]==*(char *)x)
        ans++;
    }
    return ans;
}

// Function to find value present or not in array.
bool find(void** arr,int l,int r,void* x)
{
    // ans variable to store count of x in array range[l,r].
    int ans=0;
    l--;
    r--;
    // perform linear search from [l,r] and increment count.
    for(int i=l;i<=r;i++)
    {
        if(*(char *)arr[i]==*(char *)x)
        ans++;
    }
    // if !ans that is x not present. 
    if(ans==0)
    return false;
    
    return true;
}

// Function to transform array i.e increment values of array by x.
void transform(void** arr , int n , void* x)
{
    // iterate and increment values by x.
    for(int i=0;i<n;i++)
    {
        *(int *)arr[i] = *(int *)arr[i] + *(int *)x;
    }
}
