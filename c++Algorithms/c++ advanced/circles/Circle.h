//File: Circles
//Author: Chaim Fishman
//ID: 208509349
//This is the file containing the class for a circle
#pragma once
//sturcture for point to be used by point in a circle
class point
{
public:
	point() :x(0), y(0) {};
	int g_x();
	int g_y();
	point(int m, int n);
private:
	int x, y;
};
class Circle
{
public:
	//constructors
	Circle() :center(0,0), rad(0), circumference(0), ar(0){};
	void circle(int m, int n, int r);
	float area();
	float cir();
	//getters/setters
	point getCenter();
	int get_rad();
	float get_ar();
	float get_cir();
	int g_x();
	int g_y();

private:
	point center;
	int rad;
	float ar;
	float circumference;
};