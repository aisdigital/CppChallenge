#include <string>
#include <iostream>

class Shape {
public:
    Shape() {}
    virtual ~Shape() 
    {
        std::cout << "Shape detructor" << std::endl;
    }

    virtual float calculateArea() = 0;
};