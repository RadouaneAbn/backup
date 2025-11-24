#include "Fixed.hpp"


/* NOTIC: Move this operator to Fixed.cpp */
std::ostream& operator<<(std::ostream &out, const Fixed &value) {
    out << value.toFloat();
    return out;
}

#include <iostream>
#include "Point.hpp" // Assuming your Point and Fixed classes are defined here

bool bsp(const Point a, const Point b, const Point c, const Point point);

int main() {
    // Define triangle vertices
    Point a(0.0f, 0.0f);
    Point b(5.0f, 0.0f);
    Point c(2.5f, 5.0f);

    // Test points
    Point insidePoint(2.5f, 2.0f);
    Point outsidePoint(5.0f, 5.0f);
    Point edgePoint(2.5f, 0.0f);

    // Check points
    std::cout << "Inside Point: ";
    if (bsp(a, b, c, insidePoint))
        std::cout << "Inside\n";
    else
        std::cout << "Outside\n";

    std::cout << "Outside Point: ";
    if (bsp(a, b, c, outsidePoint))
        std::cout << "Inside\n";
    else
        std::cout << "Outside\n";

    std::cout << "Edge Point: ";
    if (bsp(a, b, c, edgePoint))
        std::cout << "Inside\n";
    else
        std::cout << "Outside\n";

    return 0;
}

