/*
    This is a program to check if a number taken from user
    is negative or positive
*/
#include <iostream>



int main()
{
    int userInput;
    // Prompt the user for Input
    std::cout << "Please Enter a number and i will check if it is positive or negative: "<< '\n';
    std::cin >> userInput;

    // Check for value of 0
    if (userInput == 0)
    {
        std::cout << "Zero is neither positive nor negative." << '\n';
    }
    else
    {
        if (userInput > 0) // Check for positive value
        {
            std::cout << userInput << " is positive number";
        }
        else // Check for negative value
        {
            std::cout << userInput << " is negative number";
        }
    }
    return 0;
}
