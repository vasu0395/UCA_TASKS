/**
 * Program to Count Inversions in an array .
 * Compilation : gcc inc.c
 * Execution : ./a.out
 *
 * @Vasu ( 1910990395 )  , 11/8/2021
 * Assignment 7 - Sorting .
 *
 */
#include <stdio.h>
// Function To Merge Two Sorted Array
long long int merge(long long int arr[],long long  int l,long long  int m,long long  int r)
{
    long long int low=l,high=m+1;
    // create temporary array to store element into sorted order
    long long int temp[r - l + 1];
    long long int count=0;
    long long int ans=0;
    // compare both segment of array
    while(low<=m && high<=r)
    {
        if(arr[low]<=arr[high])
        {
            temp[count]=arr[low];
            low++;
            count++;
        }
        else
        {
            temp[count]=arr[high];
            ans+=(m - low + 1); // there always mid - low + 1 element between exact position.
            high++;
            count++;
        }
    }
    while(low<=m)
    {
        temp[count]=arr[low];
        low++;
        count++;
    }
    while(high<=r)
    {
        temp[count]=arr[high];
        high++;
        count++;
    }
        
    count=0;
    for(long long int i=l;i<=r;i++){
        arr[i]=temp[count++];
    }
    
    return ans;
}
// Function For Merge Sort
long long int mergeSort(long long int arr[],long long  int l,long long  int r)
{
    if(l>=r)
    return 0;
    long long int mid=(l+r)/2;
    long long int count=0;
    count+=mergeSort(arr,l,mid);
    count+=mergeSort(arr,mid+1,r);
    count+=merge(arr,l,mid,r);
    return count;
}
// Function For Inversion Count Of Array 
long long int inversion(long long int arr[],long long int n)
{
    return mergeSort(arr,0,n-1);
}

int main()
{
    long long int n;
    printf("Enter size of Array : ");
    scanf("%lld",&n);
    long long int arr[n];
    printf("Enter Elements : ");
    for(int i=0;i<n;i++)
    scanf("%lld",&arr[i]);
    printf("\nInversion Count : %lld\n",inversion(arr,n));
}

/*
 *
 * Sample input :- n = 4  Array : {8, 4 , 2, 1}
 * Sample output :- 6
 *
 * Sample input :- n = 3  Array : {3, 1 , 2}
 * Sample output :- 2
 *
*/
