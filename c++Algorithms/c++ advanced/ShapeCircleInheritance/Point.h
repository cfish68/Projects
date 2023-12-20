#pragma once
#include <iostream>
class Point
{
private:
	int x;
	int y;
public:
	//default constructor
	Point(int X = 0, int Y = 0);
	//copy constructor
	Point(const Point& p);
	int getX() const { return x; }
	int getY() const { return y; }
	void print();
	bool operator==(Point b);
	Point operator=(Point b);
	friend std::istream& operator>>(std::istream& in, Point& pt);
	friend std::ostream& operator<<(std::ostream& out, Point pt);
};