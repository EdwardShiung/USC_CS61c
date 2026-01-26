/*
 CS 61C C and Number Representation

 Discussion 1

In this discussion 1, I will briefly think more about the original materials, and also, I add some concepts, maybe you would love to investigate.

*/
// Before starting it, the concept of pointer is very important.

// Section - 01 - Pointer
// #include<stdio.h>

// int main() {
    
//     // Declare/define a p pointer variable (Uninitialized)
//     int *p;

//     // Address of the pointer variable itself (where p lives on the stack)
//     printf("Check out the address of p start %p\n", &p);                    // Check out the address of p start 0x16ce46b28

//     printf("Check out the address of p start in hexidecimal: %x\n", &p);    // Check out the address of p start in hexidecimal: 6ce46b28

//     // My system is 64-bit, but %x interprets the argument as a 32-bit unsigned int, so only the lower 32-bits are printed.
//     // This is undefined behavior (UB).
//     /*
//          Example: 64-bit star p int pointer:
//          00000001  6ce46b28

//          However, if you use the "32-bit unsigned int" argument, you only read the 6ce46b28.

//          In addition, %p prints a pointer using an implementation-defined format. 
//          On a 32-bit architecture, pointers are typically 32 bits; on a 64-bit architecture, they are typically 64 bits, so the output length usually differs.
         
//          The basic and real world architecture is as below:

//          CPU architecture
//           ↓
//          ABI (calling convention / pointer size)
//           ↓
//          C implementation (compiler + libc)
//           ↓
//          printf("%p") 

//          However, C language only care about the "abstract machine", not the hardware of CPU. 
//          So, ABI is that it define how data types, function calls, and memory layout work at the binary level, bridging the gap between hardware, the operating system, and compiled program.
//          Therefore, on a 64-bit architecture, the ABI define pointers to be 64 bits wide, meaning memory addressess are represented using 64-bits.
//     */

//     // The accurate way to print out the address of the pointer variable.
//     printf("Check out the address of p start %p\n", &p);                    // Check out the address of p start 0x16ce46b28

// }

// Section - 02 - Format Specifier
#include <stdio.h>


int main() {

/*
    Format specifiers describe the expected argument type, not the number of bits; the size is determined by the ABI and can be queried with sizeof.
    For example, %d and %i stand for int; %u, %x, %o stand for unsigned int; %s stand for char *; %f stand for double; %p stand for void *

    Specifier	expected argument type	    Meaning	    Example
    %d	            int	                    10-base	    signed decimal integer
    %u	            unsigned int	        10-base	    unsigned decimal integer
    %x	            unsigned int	        16-base	    hexadecimal (often for bit patterns)
    %o	            unsigned int	        8-base	    octal representation
    %f	            double	                fixed-point	floating-point number
    %c	            int	                    character	Single character
    %s	            char *	                string	    null-terminated C string
    %p	            void *	                address	    pointer (memory address)

    %zu         size_t                      base-10     object size / length (e.g. sizeof)
    %td         ptrdiff_t                   base-10     pointer difference
    %"PRIxPTR"  uintptr_t                   base-16     pointer value as an integer


    So how do we know how many bits are used?
    --> we determine the size of the corresponding type using the "sizeof" operator.

    specifier --> type contract --> sizeof(type) --> bit width (ABI define)
 
    --> In C, int is used to intended for general arithmetic values whereas size_t is a dedicated unsigned type designed to represent object sizes and lengths.
    Although they may look similar, their semantics are fundamentally different.

    */
    

    // Whenever you print the result of sizeof, use %zu.
    printf("size(void*) = %zu\n", sizeof(void*));
    printf("size(unsigned int) = %zu\n", sizeof(unsigned int));
    printf("sizeof(int) = %zu\n", sizeof(int));

}