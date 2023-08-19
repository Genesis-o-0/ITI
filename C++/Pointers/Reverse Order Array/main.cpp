#include <iostream>
#include <cstring>
using namespace std;

/*

Print Elements Of character Array In Reverse Order Using Pointer

*/


int main()
{
    // Creating arrays
    char word[100];
    char wordReversed[100];

    // Prompt the user for Input
    cout << "Kindly Enter a word and i'll reverse it: ";
    cin >> word;


    // Creating pointers
    char* ptr1 = word;

    // looping till we reach null pointer
    while (*(ptr1) != '\0')
    {
        ++ptr1;
    }

    // our pointer now is pointing to the null character
    // in word, so we will return it one step back to the
    // last char
    --ptr1;


    // Looping and Copying in Reverse
    for(int i = 0; i < strlen(word); i++)
    {
        wordReversed[i] = *(ptr1);
        --ptr1;
    }

    // putting a null terminator char in the end of the
    // reversed word
    wordReversed[strlen(wordReversed) + 1] = '\0';
    cout << wordReversed;
    return 0;
}
