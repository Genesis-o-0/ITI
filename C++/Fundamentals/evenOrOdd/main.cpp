/*
    A program to check if a given integer is odd or even.
*/
#include <iostream>


int main()
{
    int userInput;
    std::cout << "Please Enter a number to check if it Even: " << '\n';
    // Prompt the user for an input
    std::cin >> userInput;
    if (userInput % 2 == 0)
    {
        std::cout << userInput << " is Even number!" << '\n';
    }
    else
    {
        std::cout << userInput << " is Odd number!" << '\n';
    }
    return 0;
}
