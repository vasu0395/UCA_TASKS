/**
 * Program for Find Mth smallest number.
 * Compilation : gcc ms.c
 * Execution : ./a.out
 *
 * @vasu ( 1910990395 )  , 20/8/2021
 * Assignment_8
 *
 */
#include <stdio.h>
// Function for swap elements
void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
// Function which splits array into two halves.
int partion(int arr[],int n,int low,int high,int ind)
{
    // First half for smaller and equal elements of pivot elements.
    // second half for greater elements than pivot elements
    int i=low,j=low;
    while(i<=high)
    {
        if(arr[i]<=arr[ind])
        {
            swap(&arr[i],&arr[j]);
            i++;
            j++;
        }
        else
        i++;
    }
    return (j-1);
}
// Function for quick sort
void qSort(int arr[],int n,int low,int high,int k)
{
    if(low>=high)
    return;
    
    // first select pivot and divide array into halves.
    int pi=partion(arr,n,low,high,high);
    // recursive calls for boths halves
    qSort(arr,n,low,pi-1,k);
    qSort(arr,n,pi+1,high,k);
}
int main()
{
    int n,k;
    printf("Enter N and K ");
    scanf("%d %d",&n,&k);
    int arr[n];
    printf("Enter Elements of Array ");
    for(int i=0;i<n;i++)
    scanf("%d",&arr[i]);
    qSort(arr,n,0,n-1,k);
    // printing kth smallest element.
    printf("%dth smallest element %d\n",k,arr[k-1]);
    return 0;
}

