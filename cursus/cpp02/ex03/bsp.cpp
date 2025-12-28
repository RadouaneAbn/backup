#include "Point.hpp"
#include <cmath>

bool bsp( Point const a, Point const b, Point const c, Point const point) {
    /**
     * cross products to determine the position of the point relative to the triangle
     * AB * AP = (Bx - Ax)(Py - Ay) - (By - Ay)(Px - Ax)
     * BC * BP = (Cx - Bx)(Py - by) - (Cy - By)(Px - Bx)
     * CA * CP = (Ax - Cx)(Py - Cy) - (Ay - Cy)(Px - Cx)
     */

    Fixed d1(((b.getX() - a.getX()) * (point.getY() - a.getY())) - ((b.getY() - a.getY()) * (point.getX() - a.getX())));
    Fixed d2(((c.getX() - b.getX()) * (point.getY() - b.getY())) - ((c.getY() - b.getY()) * (point.getX() - b.getX())));
    Fixed d3(((a.getX() - c.getX()) * (point.getY() - c.getY())) - ((a.getY() - c.getY()) * (point.getX() - c.getX())));

    bool allNegative = (d1 < 0) && (d2 < 0) && (d3 < 0);
    bool allPositive = (d1 > 0) && (d2 > 0) && (d3 > 0);

    return (allNegative || allPositive);
}   