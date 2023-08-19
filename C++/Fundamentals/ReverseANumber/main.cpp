/*
    This is a program to reverse a number taken from User
*/

#include <iostream>


int main()
{
    int userInput, quotient, remainder;
    std::cout << "Give me a Number and i'll reverse it: " << '\n';
    std::cin >> userInput;
    /*
    # Logic
    1 - using base 10 number system, when we divide a number by 10 (12 / 10) we get 1 as
    a quotient and 2 as remainder
    2- so the remainder from the right will be printed to the left (reversed)
    Ex
    -------------------
    1 - 456 / 10 >>>>>>> quotient (45), remainder (6)
    2 - 6 will be printed instantly to the console an
    3- repeating steps 1 and 2 and printing to the console every time
    4 - result 654
    */
    quotient = userInput;
    std::cout << "You Entered: " << userInput<< '\n';
    std::cout << "The Reverse number is: ";
    while(quotient != 0)
    {
        remainder = quotient % 10;
        std::cout << remainder;
        quotient = quotient / 10;
    }
    std::cout << '\n';

}
