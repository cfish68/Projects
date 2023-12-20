//Author: Chaim Fishman 
//ID: 208509349

#include "Shape.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "Circle.h"
#include <iostream>
using namespace std;
enum shape{Cir=1, Tri = 3, Rec = 4};
int main() {
	int i, l;
	cout << "How many shapes you would like to define?\n";
	cin >> i;
	Shape** shapes= new Shape*[i];
	for (int j = 0; j < i; j++)
	{
		cout << "Which shape will you choose ? Circle - 1, Triangular - 3, Rectangle - 4 \n";
		cin >> l;
		switch (l)
		{
		case Cir:
			cout << "Enter radius:\n";
			cin >> l;
			shapes[j] = new Circle(l);
			break;
		case Tri:
			shapes[j] = new Triangle();
			break;
		case Rec:
			shapes[j] = new Rectangle();
			break;
		default:
			cout << "invalid input\n";
			j--;
		}

	}
	for (int j = 0; j < i; j++)
		cout << "points: " << shapes[j];

	for (int j = 0; j < i; j++)
//delete will happen explicitly at the end of this program.
	return 0;

}