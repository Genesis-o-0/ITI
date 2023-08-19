#include <iostream>

using namespace std;

int main()
{
    char character;
    std::cout << "Please Enter a character and I'll convert it into ASCII Value\n";
    std::cin >> character;
    std::cout << "The ASCII value of the character: "<< character << " is " <<(int)character; // Converting character into ASCII using Type Conversion (Explicit)
    return 0;
}
