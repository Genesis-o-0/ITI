#include <iostream>

// this is a program to find the length of a Null-terminated character array

int main()
{
    // this is an array of characters, deal with it based on this concept (array)
    char someText[80];
    char* charptr;
    int length = 0;

    // Prompting the user for input
    std::cout << "Please Enter any text: ";
    std::cin >> someText;
    charptr = someText;

    // we'll loop and count till we find the null character which means that this is the end
    // of the text
    while(*(charptr + length) != '\0')
    {
        length++;
    }
    std::cout << "Length of the Text is: " << length << std::endl;
    std::cout << "The pointer is at: " << (void*)charptr <<std::endl;
    std::cout << "The array first element address is at: " << &someText<<std::endl;


    return 0;
}

