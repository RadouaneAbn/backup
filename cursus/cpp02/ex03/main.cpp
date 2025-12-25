#include "Fixed.hpp"

#include <iostream>
#include "Point.hpp"

bool bsp(const Point a, const Point b, const Point c, const Point point);

void testPoint(const Point& a, const Point& b, const Point& c, const Point& point, std::string title) {
    std::cout << title << " (" << point.getX().toFloat() << ", " << point.getY().toFloat() << "): ";
    if (bsp(a, b, c, point))
        std::cout << "Inside\n";
    else
        std::cout << "Outside\n";
}

int main() {
    /* The triangle */
    Point a(0.0f, 0.0f);
    Point b(5.0f, 0.0f);
    Point c(2.5f, 5.0f);

    /* Test points */
    Point insidePoint(2.5f, 2.0f);
    Point outsidePoint(5.0f, 5.0f);
    Point edgePoint(2.5f, 5.0f);
    Point vertexPoint(0.0f, 0.0f);
    Point edgeMidPoint(2.5f, 0.0f);
    Point farOutside(10.0f, 10.0f);

    testPoint(a, b, c, insidePoint, "Inside Point");
    testPoint(a, b, c, outsidePoint, "Outside Point");
    testPoint(a, b, c, edgePoint, "Edge Point");
    testPoint(a, b, c, vertexPoint, "Vertex Point");
    testPoint(a, b, c, edgeMidPoint, "Edge Mid Point");
    testPoint(a, b, c, farOutside, "Far Outside Point");

    return (0);
}

