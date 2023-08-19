#include <iostream>

/*Write C++ program to copy one string to another string using
Pointers*/

using namespace std;

int main()
{
    char firstWord[100];
    char secondWord[100];

    // Creating Pointers that point to those character arrays
    // now we can deal with pointer as a character array
    char* ptr1 = firstWord;
    char* ptr2 = secondWord;

    // Prompt the user for input
    cout << "Please Enter a word: ";
    cin >> ptr1;

    // Looping and Copying
    while(*(ptr1) != '\0')
    {
        *ptr2 = *ptr1;
        ++ptr1;
        ++ptr2;
    }

    // Adding null character to the end of the
    *ptr2 = '\0';


    // Resetting the pointer to the start of the array
    ptr2 = secondWord;
    cout << ptr2;

    return 0;
}
