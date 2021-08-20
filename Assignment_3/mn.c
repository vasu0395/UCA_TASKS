/**
 * Program for print n numbers in Fibonacci series that are even.  
 * Compilation : gcc ms.c
 * Execution : ./a.out
 *
 * @vasu ( 1910990395 )  , 20/8/2021
 * Assignment_8
 *
 */
#include <stdio.h>
#include <string.h>
// since every third numbers is even.
// Function for print nth even numbers.
long long int Fibonacci_even(int n)
{
    // base case
    if(n==0)
    return 0;
    // First even Fibonacci number is 2. 
    if(n==1)
    return 2;
    
    // We know (for every third number) Fn = 4Fn-3 + Fn-6.
    // Fibonacci_even[3] = 4 * Fibonacci_even[2] + Fibonacci_even[1];
    return ((4 * Fibonacci_even(n-1)) + Fibonacci_even(n-2));
}
int main()
{
    printf("Starting 30 Fibonacci numbers \n");
    for(int i=1;i<=30;i++)
    printf("%lld\n",Fibonacci_even(i));
    return 0;
}

