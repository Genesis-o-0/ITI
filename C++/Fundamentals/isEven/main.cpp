/*
    this is a small program to check either the user input
    is Even or not!
*/
#include <iostream>


int main()
{
    // Variable that will hold the user input for checking
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
        std::cout << userInput << " is Not Even!" << '\n';
    }
}
