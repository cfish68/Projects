//File: class for Vecotr
//Author: Chaim Fishman 
//ID: 208509349
//hw 2.2 for c++ workshop
#pragma once
class Vector
{
public:
	//constructor
	Vector() : capSize(2), size(0), data(new int[2]) {};
	Vector(int s);
	//copy constructor
	Vector(const Vector& x);
	//destruct
	~Vector();

	//getter
	int getCapacity();
	int getSize();

	void assign(Vector x);
	void print();
	bool isEqual(Vector &x);
	int& at(int i);
	int strcatcat(Vector x);
	Vector strnewcat(Vector x);
	void clear();
	void delLast();
	void insert(int val);
	
private:
	int size;
	int capSize;
	int* data;

};