//Author: Chaim Fishman
//ID:208509349
//c++ hw 3.3



#include "String.h"
#include <iostream>
#include <cstring>
using namespace std;
#pragma warning(disable : 4996)

//constructors
String::String() 
{
	string = new char[1];
	string[0] = '\0';
}//set to empty
String::String(char* str){
	int len = 1 + strlen(str);
	string = new char[len];
	strcpy(string, str);
	return;
}

//copy construct
String::String(const String& str){
	int len = 1 + strlen(str.string);
	string = new char[len];
	strcpy(string, str.string);
	return;
}
//move
//String::String(String&& str){
//	delete[]string;
//	string = str.string;
//	str.string=NULL;
//	return;
//}

//delete
String::~String() {
	delete[]string;
}

//print
void String::print()
{
	cout << string;
}
//operator =
String String::operator=(const String str)
{
	strcpy(string, str.string);
	return *this;
}
//comparison operators
bool String::operator<(const String str)const
{
	char* mystring = string;
	char* otherstring = str.string;
	//go through both strings untill either one or both are equall \0 and at the same time if they are both equal.
	while (*mystring != '\0' && *otherstring != '\0' && *mystring == *otherstring)
	{
		mystring++;
		otherstring++;
	}
	//at this point either both strings are equal becuase in both they are at the end
	//or one string is bigger then the other. regardless of the length or strings...
	if (*mystring < *otherstring)
		return true;
	return false;
}

bool String::operator>(const String str)const
{
	char* mystring = string;
	char* otherstring = str.string;
	//go through both strings untill either one or both are equall \0 and at the same time if they are both equal.
	while (*mystring != '\0' && *otherstring != '\0' && *mystring == *otherstring)
	{
		mystring++;
		otherstring++;
	}
	//at this point either both strings are equal becuase in both they are at the end
	//or one string is bigger then the other. regardless of the length or strings...
	if (*mystring > *otherstring)
		return true;
	return false;
}
bool String::operator<=(const String str)const
{
	char* mystring = string;
	char* otherstring = str.string;
	//go through both strings untill either one or both are equall \0 and at the same time if they are both equal.
	while (*mystring != '\0' && *otherstring != '\0' && *mystring == *otherstring)
	{
		mystring++;
		otherstring++;
	}
	//at this point either both strings are equal becuase in both they are at the end
	//or one string is bigger then the other. regardless of the length or strings...
	if (*mystring == '\0' && *otherstring == '\0')
		return true;
	if (*mystring < *otherstring)
		return true;
	return false;
}
bool String::operator>=(const String str)const
{
	char* mystring = string;
	char* otherstring = str.string;
	//go through both strings untill either one or both are equall \0 and at the same time if they are both equal.
	while (*mystring != '\0' && *otherstring != '\0' && *mystring == *otherstring)
	{
		mystring++;
		otherstring++;
	}
	//at this point either both strings are equal becuase in both they are at the end
	//or one string is bigger then the other. regardless of the length or strings...
	if (*mystring == '\0' && *otherstring == '\0')
		return true;
	if (*mystring > *otherstring)
		return true;
	return false;
}
bool String::operator!=(const String str)const
{
	char* mystring = string;
	char* otherstring = str.string;
	//go through both strings untill either one or both are equall \0 and at the same time if they are both equal.
	while (*mystring != '\0' && *otherstring != '\0' && *mystring == *otherstring)
	{
		mystring++;
		otherstring++;
	}
	//if reached this point and they are both still equal return false as they are equal
	if (*mystring == *otherstring)
		return false;
	return true;
}
//subscript operator
char* String::operator[](int sub)
{
	if (string == NULL)
	{
		cout << "ERROR\n";
		return NULL;
	}
	if (strlen(string) - 1 < sub)
	{
		cout << "ERROR\n";
		return NULL;
	}
	return (string + sub);
}
String String::insert(int index, const String str)const
{
	String n;
	if (index > strlen(string))
	{
		cout << "ERROR\n";
		n.string = NULL;
		return n;
	}
	int len = strlen(string) + strlen(str.string) + 1;
	delete[] n.string;
	n.string = new char[len];
	strncpy(n.string, string, index);
	strncpy(n.string + index, str.string, strlen(str.string));
	strncpy(n.string + index + strlen(str.string), string + index, strlen(string + index));
	n.string[len - 1] = '\0';
	cout << n.string << '\n';
	return n;
}
