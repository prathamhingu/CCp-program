/* Programmer : Hingu Pratham
   Date : 04 April, 2025
   Aim : To calculate and display the areas of multiple circles using object-oriented programming in C++
*/

#include <iostream>
#include <vector>

using namespace std;

// Base class for a shape
class Shape
{
protected:
    double radius;
public:
    Shape(double r = 0.0) : radius(r) {}
    void setRadius(double r)
    {
        radius = r;
    }
    double getRadius() const
    {
        return radius;
    }
};

// Derived class for a Circle
class Circle : public Shape
{
public:
    Circle(double r = 0.0) : Shape(r) {}

    double area()
    {
        return 3.14 * radius * radius;
    }

    void displayArea() const
    {
        cout << "Circle with radius " << radius << " has area: " << 3.14 * radius * radius << endl;
    }
};

// Approach 1: Dynamic collection using vector
void handleCirclesDynamically()
{
    vector<Circle> circles;
    circles.push_back(Circle(3.0));
    circles.push_back(Circle(4.5));
    circles.push_back(Circle(2.2));

    cout << "--- Dynamic Collection ---\n";
    for (auto& c : circles)
    {
        c.displayArea();
    }
}

// Approach 2: Static collection using array
void handleCirclesStatically()
{
    const int SIZE = 3;
    Circle circles[SIZE] = { Circle(1.0), Circle(2.0), Circle(3.0) };

    cout << "\n--- Static Collection ---\n";
    for (int i = 0; i < SIZE; ++i)
    {
        circles[i].displayArea();
    }
}

int main()
{
    handleCirclesDynamically();
    handleCirclesStatically();

    cout<<endl;
    cout<<"Hingu Pratham : 24CE039"<<endl;

    return 0;
}
