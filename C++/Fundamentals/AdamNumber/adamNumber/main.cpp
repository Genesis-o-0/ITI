/*
    This program checks for Adam Number

    Adam number?!
    A number when squared, reversed, its root is found and is reversed again is equal to the    original number

*/



#include <iostream>
#include <math.h>


int main()
{
    int userInput, quotient1, remainder1, revSquaredNum = 0, squaredNum, squareRootRevNum, revNum = 0, quotient2, remainder2;
    std::cout << "Give me a number, and i'll tell you either it is an Adam Number or not: " << '\n';
    std::cin >> userInput;
    std::cout << "You Entered: " << userInput << '\n';
    squaredNum = userInput * userInput;
    std::cout << "The Number squared: " << squaredNum << '\n';
    quotient1 = squaredNum;
    while(quotient1 != 0)
    {
        remainder1 = quotient1 % 10;
        revSquaredNum = revSquaredNum * 10 + remainder1;
        quotient1 = quotient1 / 10;
    }
    std::cout << "The Reverse of the squared number: " << revSquaredNum << '\n';
    squareRootRevNum = sqrt(revSquaredNum);
    std::cout << "The square root of The Reverse of the squared number: " << squareRootRevNum << '\n';
    while(squareRootRevNum != 0)
    {
       remainder2 = squareRootRevNum % 10;
       revNum = revNum * 10 + remainder2;
       squareRootRevNum = squareRootRevNum / 10;
    }
    std::cout << "The reversed number: " <<revNum << '\n';
    if(revNum == userInput) {
        std::cout << userInput << " Is an Adam Number" << '\n';
    }
    else
    {
        std::cout << userInput << " Is not and Adam Number" << '\n';
    }
    return 0;
}
