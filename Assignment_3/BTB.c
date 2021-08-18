/*
 *  BITS AND BYTES Assignment
 *  Compilation : gcc BTB.c
 *  Execution : ./a.out
 *
 *  @vasu , (1910990395) , 15/08/21
 *  Assignment :- Bits and Bytes.
*/
#include <stdio.h>

// Function for perform bitwise Xor .
int bitXor(int x, int y) 
{
    // Taking And (&) of x and y.
    int a = x & y;
    // Taking And (&) of (~x) and (~y).
    int b = ~x & ~y;
    // result equal to And (&) of (~a) and (~b). 
    int z = ~a & ~b;
    return z;
}  


// Function to return bth Byte.
int getByte(unsigned int a,int b)
{
    // since 1 byte have 8 bits in it.
    b=b*8;
    // first get all set bits and then right shift by bth bits.
    // After this return answer and 0xFF (255 in decimal).
    return (((a & 0x7FFFFFFF)>>b)&0xFF);
}

// Function to return sign of number.
int sign(int x)
{
    // first get last_bit i.e 31 bits (for negative number it's value -1).
    int last_bit=(x >> 31);
    // (!(!x)) is set value 0 or 1 (for any number).
    int complement_number=!(!x);
    // return or of complement_number and last_bit.
    return (complement_number | last_bit);
}

// Function to returns x with n bits starting at p inverted.
int invert(int x , int p , int n)
{
    // To set last n bits to 1 and make other bits 0.
    int answer = (~(~0 << n));
    
    // shifting the 1's group to position p by left shifting the answer by p+1-n.
    answer = answer << (p  - n);
    
    //inverting the bits using xor operator.
    return (x ^ answer);
}

// function for conditional using bitwise
int conditional(int x, int y, int z)
{  
    // (!x) + ~0 will give 0 if x is 0 else -1
    int check = ( (!x) + (~0) );
    // if checker is 0 final answer is z else answer is y
    return  ((check & (y ^ z)  ) ^ z) ;
}

// function for logicalShift
int logicalShift(unsigned int x, int n) {
	
	//arithemetic shift to n position
    int shift1 = (x >> n) ;
    // set last n bits to 00000 and remaining 111111 .
    int shift2 = ~(((1 << 31) >> n) << 1);
    //doing & set only set bits in x.
    return (shift1 & shift2);
}

// Function for Bang operation.
int Bang(int x)
{
    // 2's complement of -5 = 0000 ....0000 0000 0000 0101
    // 2's complement of 5 =  1111 ....1111 1111 1111 1011
    // using or operation set 31th bit to 1.
    int complement_number_2s=(~x + 1);
    complement_number_2s=(complement_number_2s | x);
    // since right shift perform arithmetic shift so complement_number_2s is always -1 (exception 0).
    return (complement_number_2s >> 31) + 1;
}

// Function for Bitwise and
int bitAnd(int x,int y)
{
    // one complement (~) bits of x and (&) y , then taking or (|) of it.
    int a=(~x | ~y);
    // one complement (~) bits to get result.
    int z=(~a);
    // output result.
    return z;
}


int main()
{
    // sample input test done.
    printf("BitAnd of 6 and 5 : %d\n",bitAnd(6,5));
    
    printf("BitXor of 4 and 5 : %d\n",bitXor(4,5));
    
    printf("Sign(130) = %d ,Sign(-23) = %d\n",sign(130),sign(-23));
    
    printf("GetByte(0x12345678, 1) = 0x%x\n",getByte(0x12345678, 1));
    
    printf("conditional (2, 4, 5) = %d\n",conditional(2, 4, 5));
    
    printf("bang(3) = %d , bang(0) = %d\n", Bang(3),Bang(0));
    
    printf("logicalShift(0x87654321, 4) = 0x%x\n",logicalShift(0x87654321, 4));
    
    printf("invert(10,3,3) = %d\n",invert(10,3,3));
}
