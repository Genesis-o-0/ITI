#include <iostream>
#include <ctype.h>

using namespace std;

int main()
{
    char character;
    std::cout << "Please Enter a Character and i will recognize its type: ";
    std::cin >> character;
    if(isdigit(character))
    {
        std::cout << "you entered a Digit: " << character << '\n';
    }
    else
    {
        if(isalpha(character))
        {
            if (character == 'a' || character == 'A' || character == 'o' || character == 'O' || character == 'e' || character == 'E' || character == 'i' || character == 'I' || character == 'u' || character == 'U')
        {
            std::cout << "You Entered a Vowel: " << character << '\n';
        }
        else
        {
            std::cout << "You Entered a consonant: " << character << '\n';
        }
        }
        else
        {
            std::cout << "You Entered a Special character " << character << '\n';
        }
    }


    return 0;
}
