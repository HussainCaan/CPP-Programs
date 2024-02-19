#include <iostream>
using namespace std;

class Shapes
{
protected:
    double width, height, length;

public:
    virtual void calculateArea() = 0;
    virtual double getArea() const = 0;
};

class TwoDShapes : public Shapes
{
public:
    TwoDShapes()
    {
        cout << "TwoDShapes constructor\n";
    }
};

class Circle : public TwoDShapes
{
    double radius, area;

public:
    Circle(double r) : radius(r){};

    void calculateArea() override
    {
        area = (radius * radius) * 3.14;
    }
    double getArea() const override
    {
        return area;
    }
};

class Square : public TwoDShapes
{
    double side, area;

public:
    Square(double side) : side(side){};

    void calculateArea() override
    {
        area = side * side;
    }

    double getArea() const override
    {
        return area;
    }
};
class Three_D_Shapes : public Shapes
{
public:
    Three_D_Shapes()
    {
        cout << "ThreeDShapes constructor\n";
    }
};
class Cube : public Three_D_Shapes
{
    double side, area;

public:
    Cube(double side) : side(side){};
    void calculateArea() override
    {
        area = (side * side) * 6;
    }
    double getArea() const
    {
        return area;
    }
};
class Pyramid : public Three_D_Shapes
{
    double side, area;

public:
    Pyramid(double side) : side(side){};
    void calculateArea() override
    {
        area = side * side * side;
    }
    double getArea() const override
    {
        return area;
    }
};
int main()
{
    TwoDShapes *TwoD_ptr[] = {new Circle(5.0), new Square(2)};
    Three_D_Shapes *threeD_ptr[] = {new Cube(4.0), new Pyramid(3)};

    for (int i = 0; i < 2; i++)
    {
        TwoD_ptr[i]->calculateArea();
        cout << "Area of 2D shapes are  " << TwoD_ptr[i]->getArea() << "\n";
        delete TwoD_ptr[i];
    }
    for (int i = 0; i < 2; i++)
    {
        threeD_ptr[i]->calculateArea();
        cout << "Area of 3D shapes are " << threeD_ptr[i]->getArea() << "\n";
        delete threeD_ptr[i];
    }

    
    return 0;
}
