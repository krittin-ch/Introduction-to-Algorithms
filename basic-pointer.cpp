#include <iostream>
#include <stdio.h>

void print_values(int *ptr) {
    printf("Value pointed to by ptr: %d\n", *ptr); // Dereference ptr to get the value
}

/*
    - x     : an integer variable.
    - &x    : the address of the integer variable x.
    - ptr   : a pointer variable that can store the address of an integer.
    - ptr   : now holds the address of x.
    - *ptr  : the value stored at the address ptr points to, which is the value of x.
    - ptr = &x initializes the pointer ptr with the address of x.
    - *ptr = 10 changes the value at the address pointed to by ptr, thus changing the value of x to 10.
*/

int main() {
    int x = 5;
    int *ptr1 = &x; // ptr1 holds the address of x

    int *ptr2;
    ptr2 = &x;      // ptr2 holds the address of x

    printf("Address of x: %p\n", (void*)&x);            // Print the address of x
    printf("Address stored in ptr: %p\n", (void*)ptr1); // Print the address stored in ptr
    printf("Value of x: %d\n", x);                      // Print the value of x
    
    printf("Value pointed to by ptr: %d\n", *ptr1);     // Dereference ptr to get the value
    // printf("Value pointed to by ptr: %d\n", *&x);
    print_values(&x);                                   // Pass the address of x to the function

    // std::cout << *ptr1 << std::endl;

    return 0;
}
