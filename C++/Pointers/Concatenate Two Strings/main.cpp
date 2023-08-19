#include <iostream>

using namespace std;


/*

Concatenate Two Strings In C++ Using Pointers


*/



int main()
{
    // Two words mean two arrays of characters
    char firstWord[100];
    char secondWord[100];

    // Prompt the user to enter a word
    cout << "Kindly Enter First Word: ";
    cin >> firstWord;
    cout << "Kindly Enter Second Word: ";
    cin >> secondWord;

    // Creating pointers
    char* ptr1 = firstWord;
    char* ptr2 = secondWord;

    // Searching first word till we reach the null terminator
    while (*ptr1 != '\0')
    {
        ++ptr1;
    }

    // Assigning every character in secondName to firstName
    // till we find the null character
    while (*ptr2 != '\0')
    {
        *ptr1 = *ptr2;
        ++ptr1;
        ++ptr2;
    }
    // Adding null character at the end of the firstName
    *ptr1 = '\0';
    // resetting the pointer to the start of the array
    ptr1 = firstWord;
    cout << ptr1;

    return 0;
}
