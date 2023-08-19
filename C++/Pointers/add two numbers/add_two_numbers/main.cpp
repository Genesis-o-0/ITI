#include <iostream>

// This is a program to add two numbers by using pointers

int main()
{
    int num1, num2, *ptr1, *ptr2, Sum = 0;
    std::cout << "Please Enter the Two numbers: \n";
    std::cin >> num1 >> num2;
    ptr1 = &num1;
    ptr2 = &num2;
    Sum = *ptr1 + *ptr2;
    std::cout << "Sum: " << Sum << std::endl;
    return 0;
}
