#include <iostream>
#include <iomanip>


int main()
{
    int rows;
    std::cout << "Please Enter Rows Number, and i will generate the related Pascal’s Triangle: ";
    std::cin >> rows;
    std::cout << std::endl;
    for(int i = 0; i < rows; i++)
    {
        int firstCell = 1;
        for(int j = 0; j <= i; j++)
        {
            std::cout << std::setw(8)<< firstCell << std::setw(8);
            firstCell = firstCell * (i - j) / (j + 1);

        }
        std::cout << std::endl;
    }



    return 0;
}
