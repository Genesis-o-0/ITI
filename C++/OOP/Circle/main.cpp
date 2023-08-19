#include <iostream>
using namespace std;

/*
Write a C++ program to implement a class called Circle that has private member variables for radius. Include member functions to calculate the circle's area and circumference.
*/

class Circle
{
private:
    // Data members
    double radius;
    const double PI = 3.14159265359;

public:

    //setter
    void setRadius(double _radius)
    {
        radius = _radius;
    }

    // Getter
    //Area
    double getArea()
    {
        cout << endl;
        cout << "The area of the circle is: ";
        return (PI * (radius * radius));
    }
    //circumference
    double getCircum()
    {
        cout << endl;
        cout << "The circumference of the circle is: ";
        return (2 * PI * radius);
    }
};



int main()
{
    Circle c1;
    c1.setRadius(3);
    cout << c1.getArea();
    cout << c1.getCircum();


    return 0;
}
