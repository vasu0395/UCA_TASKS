/*
 *  BITS AND BYTES Assignment
 *  Compilation : gcc BT.c
 *  Execution : ./a.out
 *
 *  @vasu , (1910990395) , 15/08/21
 *  Assignment :- Bits and Bytes.
 *
 *  Special mentioned :- This code based on fact that to convert from one base to another base 
 *  Best idea is to first convert it into decimal and then tho given base .
 * 
 *
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
int power(int x,int y)
{
    int res = 1;
    while (y > 0) {
        // If y is odd, multiply x with result
        if (y & 1)
            res = res * x;
 
        // y must be even now
        y = y >> 1; // y = y/2
        x = x * x; // Change x to x^2
    }
    return res;
}
void fun()
{
    // string name (32 base)
    char name[1000];
    scanf("%s",name);
    // create array for 64 base
    char mpl[66];
    
    // map element for 64 base
    for(int i=0;i<26;i++)
    mpl[i]=(char)('A' + i);
    
    int count=0;
    
    for(int i=26;i<52;i++)
    mpl[i]=(char)('a' + count++);
    
    count=0;
    
    for(int i=52;i<62;i++)
    mpl[i]=(char)('a' + count++);
    
    mpl[62]='+';
    mpl[63]='/';
    
    // convert 32 base to decimal base.
    long long int ans=0;
    int t=0;
    for(int i=strlen(name)-1;i>=0;i--)
    {
        // first finding its value in 32 base
        if(name[i]>='A' && name[i]<='Z')
        {
            ans+=(power(32,t))*((int)(name[i] - 'A'));
        }
        else
        {
            ans+=(power(32,t))*((int)(name[i] - '2' + 26));
        }
        t++;
    }
    
    //printf("%lld\n",ans);
    
    // temp string for 
    char temp[100];
    int low=0;
    // convert decimal to 64 base
    while(ans!=0)
    {
        int rem=ans%64;
        temp[low++]=mpl[rem];
        ans/=64;
    }
    temp[low]='\0';
    printf("%s",temp);
    
}
signed main() {
	int t=1;
	//cin>>t;
	while(t--)
	{
	    printf("Enter Base_32 input ");
	    fun();
	}
	return 0;
}
