//File: vector.cpp for Vector.h
//Author: Chaim Fishman 
//ID: 208509349
//hw 2.2 for c++ workshop

#include "Vector.h"
#include <iostream>
using namespace std;

Vector::Vector(int s)
{
	capSize = s;
	size = 0;
	data = new int[s];
}
//copy constructor
void Vector::assign(Vector x)
{
	delete[] data;
	capSize = x.capSize;
	size = x.size;
	data = new int[capSize];
	for (int i = 0; i < size; i++)
	{
		data[i] = x.data[i];
	}
	
}
Vector::Vector(const Vector& x)
{
//	delete[] data;
	capSize = x.capSize;
	size = x.size;
	data = new int[capSize];
	for (int i = 0; i < size; i++)
	{
		data[i] = x.data[i];
	}
}
//delete method
Vector::~Vector()
{
	delete[] data;
}
//getters
int Vector::getCapacity() { return capSize; }
int Vector::getSize() { return size; }

//pass to a vector to print out values on screen
void Vector::print()
{
	cout << "capacity: " << capSize << " size: " << size << " values:";
	for (int i = 0; i < size; i++)
	{
		cout << ' ' << data[i] << ' ';
	}
	cout << endl;
}

//parameter taken in  is a vector. a
//return true if vector assigned to and vector passed in are equal.
bool Vector::isEqual(Vector& x)
{
	//if they have different amount of values
	if (size != x.size) return false;
	//check if the values are the same
	for (int i = 0; i < size; i++) if(data[i] != x.data[i]) return false;
	//if we got to this point the vectors are equal.
	return true;
}

int& Vector::at(int i)
{
	if (i < 0 || i >= size)
	{
		cout << "ERROR\n";
		i = 0;
	}
	return data[i];
}

int Vector::strcatcat(Vector x)
{
	//check if sizes match
	if (size != x.size) return -1;
	int t = 0;
	for (int i = 0; i < size; i++)
	{
		t += (data[i] * x.data[i]);
	}
	return t;
}
Vector Vector::strnewcat(Vector x)
{
	Vector n(capSize + x.capSize);
	n.size = size + x.size;
	//copy elements from first vector
	for (int i = 0; i < size; i++) 
	{ 
		n.data[i] = data[i]; 
	}
	//copy elements from second vector
	for (int i = size, j = 0; i < size + x.size; i++, j++)
	{ 
		n.data[i] = x.data[j];
	}
	return n;
}

//im not sure if this is meant to delete the dynamically allocated array.
//so i'm going to just make it size 0
void Vector::clear()
{
	size = 0;
	return;
}
//again not sure whats inteded here so im just going to make size 1 less
void Vector::delLast()
{
	if (size == 0)
	{
		cout << "ERROR\n";
		return;
	}
	size--;
	return;
}

void Vector::insert(int val)
{
	//make sure there's room for it
	if (size == capSize) 
	{
		Vector n(size);
		delete[] n.data;
		n.data = new int[size];
		for (int i = 0; i < size; i++) {
			n.data[i] = data[i];
		}
		delete[] data;
		capSize = (2 * capSize);
		data = new int[capSize];
		for (int i = 0; i < size; i++) 
		{
			data[i] = n.data[i]; 
		}
	
	}
	data[size] = val;
	size++;
	return;
}