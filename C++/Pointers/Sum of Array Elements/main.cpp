#include <iostream>
// This is a program to sum array elements using pointers


int main()
{
    int nums[5];
    int Sum = 0;
    int* ptr;
    std::cout << "Enter a five numbers: \n";
    // we need 5 numbers so we'll prompt the user 5 times
    for(int i = 0; i < 5; i++)
    {
        std::cin >> nums[i];
    }
    ptr = nums;

    // Looping through array and summing its elements using pointers
    for(int i = 0; i < 5; i++)
    {
        Sum += *(ptr + i);
    }

    std::cout << "Sum: " << Sum << std::endl;
    return 0;
}
