/*
 CS 61C C and Number Representation

 Discussion 1

In this discussion 1, I will briefly think more about the original materials, and also, I add some concepts, maybe you would love to investigate.

*/


//================================================================================================================================================================================

// Before starting it, the concept of pointer is very important.

// Section - 01 - Pointer (*p: Tells compiler that variable p is address of an int; &: address operator)
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

//     return 0;

// }


//================================================================================================================================================================================

// Section - 02 - Format Specifier
// #include <stdio.h>


// int main() {

// /*
//     Format specifiers describe the expected argument type, not the number of bits; the size is determined by the ABI and can be queried with sizeof.
//     For example, %d and %i stand for int; %u, %x, %o stand for unsigned int; %s stand for char *; %f stand for double; %p stand for void *

//     Specifier	expected argument type	    Meaning	    Example
//     %d	            int	                    10-base	    signed decimal integer
//     %u	            unsigned int	        10-base	    unsigned decimal integer
//     %x	            unsigned int	        16-base	    hexadecimal (often for bit patterns)
//     %o	            unsigned int	        8-base	    octal representation
//     %f	            double	                fixed-point	floating-point number
//     %c	            int	                    character	Single character
//     %s	            char *	                string	    null-terminated C string
//     %p	            void *	                address	    pointer (memory address)

//     %zu         size_t                      base-10     object size / length (e.g. sizeof)
//     %td         ptrdiff_t                   base-10     pointer difference
//     %"PRIxPTR"  uintptr_t                   base-16     pointer value as an integer


//     So how do we know how many bits are used?
//     --> we determine the size of the corresponding type using the "sizeof" operator.

//     specifier --> type contract --> sizeof(type) --> bit width (ABI define)
 
//     --> In C, int is used to intended for general arithmetic values whereas size_t is a dedicated unsigned type designed to represent object sizes and lengths.
//     Although they may look similar, their semantics are fundamentally different.

//     */
    

//     // Whenever you print the result of sizeof, use %zu.
//     printf("size(void*) = %zu\n", sizeof(void*));
//     printf("size(unsigned int) = %zu\n", sizeof(unsigned int));
//     printf("sizeof(int) = %zu\n", sizeof(int));

//     return 0;

// }


//================================================================================================================================================================================

// // Section - 03 - Pointer (*: The start used in two ways: Declaration and Dereference)
// #include <stdio.h>

// int main() {

//     int num = 3;
//     int *p = &num;  // Tell complier to assign address of num to p

//     // print the address of pointer variable 
//     printf("Address of Pointer Variable: %p\n", &p);                    // Address of Pointer Variable: 0x16d05eb20
//     // print the address of num
//     printf("Address of number: %p\n", &num);                            // Address of number: 0x16d05eb2c

//     // print the stored address in pointer variable p
//     printf("Stored address: %p\n", p);                                  // Stored address: 0x16d05eb2c

//     // print the number from pointer variable p
//     printf("Gets value pointed to by p: %d\n", *p);                     // Gets value pointed to by p: 3

//     printf("================================================\n");

//     // We know that * operator can be declaration and dereference operator. 
//     // What we want to know is when we do dereference, the stored address will changed?
//     // In addition, will that affect the num variable?

//     // Changed value pointed to by p
//     *p = 5;

//     // print the address of pointer value
//     printf("Address of Pointer Variable: %p\n", &p);                    // Address of Pointer Variable: 0x16d05eb20

//     // print the stored address in pointer variable p
//     printf("Stored address: %p\n", p);                                  // Stored address: 0x16d05eb2c

//     // print the value pointed by p
//     printf("Gets the new value pointed to by p: %d\n", *p);             // Gets the new value pointed to by p: 5

//     // print the address of original num variable
//     printf("print the num variable: %p\n", &num);                       // print the num varialbe: 0x16d05eb2c

//     // print the value of original num variable
//     printf("print the value of original num variable: %d\n", num);      // print the value of original num variable: 5


//     /*
//         Dereferencing (*p) accesses the object stored at the address inside p.
//         The pointer p (the address value) does not change. 
//         Writing through the pointer (e.g. *p = 5) modifies the original variable (num) because p points to nums.
//     */

//     return 0;

// }

//================================================================================================================================================================================


/*
1 Pre-Check: Introduction to C: 
This section is designed as a conceptual check for you to determine if you conceptually
understand and have any misconceptions about this topic. Please answer true/false to the following questions, and include an explanation:
*/


// 1.1 The correct way of declaring a character array is char[] array.
// -> False

// #include <stdio.h>

// int main() {

//     // In C, an array must have a known size at compile time, unless it's initialized.

//     // The answer from USC cs61c is below, but actually, it's not completed correct, 
//     // which means the declaration doesn't have the "block scope", "no initializer", and "hard to read for some compilers".
//     // char array[];

//     // 1st: add block scope when declaration

//     char array_01[10];

//     // 2nd: initialize the array
//     char array_02[] = "hello";

//     return 0;

// }



// 1.2 True or False: C is a pass-by-value language.
// True

/*
    C is strickly call-by-value. What looks like call-by-reference is actually call-by-value of an address.
*/



//================================================================================================================================================================================
/*
2 Pass-by-who?

2.1 The following functions may contain logic or syntax errors. Find and correct them.

*/

/*
(a) Returns the sum of all the elements in summands.
int sum(int *summands) {
    int sum = 0;
    for (int i = 0; i < sizeof(summands); i++)
    sum += *(summands + i);
    return sum;
}

ANS:

When the array passes to the function, the array will decay to pointers.

The error is that sizeof(summands) returns the size of pointer, not the number of elements in the array.
*/



// Solution 1: Add another parameter for size by using int Array Size.
// #include <stdio.h>

// int main(){
    
//     int numberArr[10] = {1,2,3,4,5,6,7,8,9,0};

//     int arrlength = sizeof(numberArr) / sizeof(numberArr[0]);

//     int sum(int *summands, int arraySize){
//         int sum = 0;

//         for(int i = 0; i < arraySize; i++) {
//             sum += *(summands + i);
//         }

//         return sum;
//     }

//     int results = sum(numberArr, arrlength);

//     printf("Get the result of sum: %d\n", results);         // Get the result of sum: 45

//     return 0;
// }


// Solution 2: Instead using the "int" standing for the size, using the "size_t" type is more accurate than first one!
// #include <stdio.h>

// int main(){
    
//     int numberArr[10] = {1,2,3,4,5,6,7,8,9,0};

//     int arrlength = sizeof(numberArr) / sizeof(numberArr[0]);

//     int sum(int *summands, size_t n){
//         int sum = 0;

//         for(int i = 0; i < n; i++) {
//             sum += *(summands + i);
//         }

//         return sum;
//     }

//     int results = sum(numberArr, arrlength);

//     printf("Get the result of sum: %d\n", results);         // Get the result of sum: 45

//     return 0;
// }


// Solution 3 (X) --> Not a correct answer.
// #include <stdio.h>

// int main(){
    
//     int numberArr[10] = {1,2,3,4,5,6,7,8,9,0};

//     int sum(int *summands){
//         int sum = 0;

//         // Please don't count the length by using "sizeof(summands)/sizeof(summands[0]".
//         // The reason is when you pass the array to the function, the array will become pointer, 
//         // which means that the "sizeof(summands)" will be calculated as 8 bytes based on my 64-bit architecture.
//         // also, sizeof(summands[0]) == sizeof(1) == sizeof(int) will be calcuated to 4 bytes
//         // Therefore, the loop will go through until index == 2, which means you get the sum to 3.
//         for(int i = 0; i < sizeof(summands)/sizeof(summands[0]); i++) {
//             sum += *(summands + i);
//         }

//         return sum;
//     }

//     int results = sum(numberArr);

//     printf("Get the result of sum: %d\n", results);         // Get the result of sum: 3

//     return 0;
// }


/*

(b) Increments all of the letters in the string which is stored at the front of an array of arbitrary length, n >= strlen(string). Does not modify any other
parts of the array’s memory.

void increment(char *string, int n) {
    for (int i = 0; i < n; i++)
    *(string + i)++;
}


--> The biggest problem in this code is the limitation in the for-loop. The question said that we don't need to traverse all the elements in the string.

*/

// Here is the wrong answer for demonstration.

// Solution_01
// #include <stdio.h>

// // In C, you can't define the function in another function. So, you have to define the function outside of main.

// void increment(char *string){

//     // [1st Error]: The biggest mistake is here: *(string + i) != "0"
//     // The "*(string + i)" is char, which means a pointer; the "0" is a string.
//     // --> You can't compare a string with char, so you should revise "0" to '0'.
//     for(int i = 0; *(string + i) != '\0'; i++){

//         // [2nd Error]: lvalue required as increment operand
//         // --> lvalue == locator value == left-hand value == addressable storage, which could be assigned (stored) a value, get the address
//         // --> rvalue == right-hand value == temporary value, which means there is no place to store value, just be calculated.
//         // The reason why it happened is that the level of the "++" operation is higher than the "dereference operator"
//         // so, if you so the " (string + i)++ " first, there is no place to store the temporary value.
//         // *(string + i)++;
        
        
//         // [How to solve?]
//         // add "( )"
//         (*(string + i))++;
//     }
// }

// int main() {
    
//     char sequenceString[] = "abc";

//     increment(sequenceString);
    
//     printf("Get the results of sequenceString: %s", sequenceString);

//     return 0;
// }


// [Extended Pointer Discussion]:
// In C, array indexing is defined in terms of pointer arithmetic. 
// --> Above solution, in for-loop, string[i] is exactly same as *(string + i).
// Let's try to give more example here.

#include<stdio.h>

int main() {
    
    char arr[] = "abc";

    char *p = arr;

    // Print first letter "c", we have three different way to print it:

    // 1st: Easy way to print it out.
    printf("1st: %c\n", arr[2]);
    
    // 2nd: Using the pointer to print first letter
    printf("2nd: %c\n", *(p + 2));

    // 3rd: or, we could write like this:
    printf("3rd: %c\n", p[2]);


    return 0;
}


