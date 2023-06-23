#include "shape.hpp"

class Rectangle : public Shape {
public:
    Rectangle(int w, int h);
    Rectangle();
    ~Rectangle();

    float calculateArea();
private:
    int width;
    int height;
};