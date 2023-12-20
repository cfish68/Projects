#include "Point.h"

Point::Point(int X, int Y) :x(X), y(Y)
{ }
Point::Point(const Point& p)
{
	x = p.getX();
	y = p.getY();
}
void Point::print()
{
	std::cout << '(' << x << ',' << y << ")\n";
}
bool Point::operator==(Point b)
{
	if (b.x == x && b.y == y)
		return true;
	return false;
}
std::istream& operator>>(std::istream& in, Point& pt)
{
	char x;
	in >> x >> pt.x >> x >> pt.y >> x;
	return in;
}
std::ostream& operator<<(std::ostream& out, Point pt)
{
	out << '(' << pt.x << ',' << pt.y << ')';
	return out;
}
Point Point::operator=(Point b)
{
	x = b.x;
	y = b.y;
	return *this;
}