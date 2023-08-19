#include <iostream>

using namespace std;

/*
Write a C++ program to create a class called Rectangle that has private member variables for length and width. Implement member functions to calculate the rectangle's area and perimeter.

*/
class Rectangle
{
private:
    double width;
    double length;
public:
    // Constructors
    Rectangle()
    {
        width = 0;
        length = 0;
        cout << "Rectangle has width of 0 and height of 0" << endl;
    }
    Rectangle(double _width, double _length)
    {
        width = _width;
        length = _length;
    }
    // setter
    void setWidth(double _width)
    {
        width = _width;
    }
    void setLength(double _length)
    {
        length = _length;
    }

    // getter
    double getWidth()
    {
        return width;
    }
    double getLength()
    {
        return length;
    }
    double getArea()
    {
        return width * length;
    }
    double getPerimeter()
    {
        return 2 * (length + width);
    }

};

int main()
{
    Rectangle rec;
    rec.setLength(5);
    rec.setWidth(5);
    cout << rec.getArea() << endl;
    cout << rec.getPerimeter();

    return 0;
}
