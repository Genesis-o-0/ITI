#include <iostream>

// This is a program to swap Two variables
void swap_two(int* ptr1, int* ptr2);


int main()
{
    int a = 50, b = 40;
    int* ptr1 = &a;
    int* ptr2 = &b;
    swap_two(ptr1, ptr2);

    return 0;
}


// Swap function with pointers as arguments
void swap_two(int* ptr1, int* ptr2)
{
    // We need another variable to hold one of the two values and make
    // the swap
    int temp;
    // Printing a message to the users before the swap
    std::cout << "Numbers before swap: \n";
    std::cout << "Number 1: " << *ptr1 << '\n';
    std::cout << "Number 2: " << *ptr2 << '\n';

    temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
    // Printing a message to the users before the swap
    std::cout << "Numbers after swap: \n";
    std::cout << "Number 1: " << *ptr1 << '\n';
    std::cout << "Number 2: " << *ptr2 << '\n';
}
