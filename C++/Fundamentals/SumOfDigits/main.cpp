/*
a Program to get an input from user as integer and display
the sum of all the numbers in this integer.
Ex: user input >>> 123
    Sum >>> 1+2+3 == 6
*/


#include <iostream>

int main()
{
    int userInput, quotient, remainder, sum = 0;

    // Prompt the user for input
    std::cout << "Enter a number and i will return the sum of its digits: " << '\n';
    std::cin >> userInput;
    /* Consider that the user entered 123:
    1- we know that we're using a base 10 number system
    2- so dividing 123 over 10 will result in 12 as quotient and 3 as a remainder
    3- save 3 in remainder variable (remainder = 3)
    4- take 12 and divide it by 10 (quotient = 1) and add the remainder (2) to the latest one (3)
    (remainder = remainder + 2) = 5
    5- repeating (while loop) step 2 and 3 until the quotient becomes 0 */

    quotient = userInput;

    while(quotient != 0 )
    {
        remainder = quotient % 10;
        quotient = quotient / 10;
        sum += remainder;
    }
    std::cout << "The Sum of the digits: " << sum << '\n';
    return 0;
}
