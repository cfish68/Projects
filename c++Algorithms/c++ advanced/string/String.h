//Author: Chaim Fishman
//ID:208509349
//c++ hw 3.3


#pragma once
class String {
public:
	//constructors
	String();//set to null
	String(char* str);

	//copy construct
	String(const String &str);
	//move
//	String(String &&str);
	
	//delete
	~String();



	//print
	void print();
	//= operator
	String operator=(const String str);
	//comparison operators
	bool operator<(const String str)const;
	bool operator>(const String str)const;
	bool operator<=(const String str)const;
	bool operator>=(const String str)const;
	bool operator!=(const String str)const;
	//subscript operator
	char* operator[](int sub);

	String insert(int index, const String str)const;
private:
	char* string;
};