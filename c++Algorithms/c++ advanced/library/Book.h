#pragma once
#include <iostream>

class Book {
public:
	Book();
	Book(int i, std::string a="", std::string b=""): id(0), author(a), book_name(b){}
	bool operator<(const Book& x)const;
	bool operator>(const Book& x)const;
	bool operator<=(const Book& x)const;
	bool operator>=(const Book& x)const;
	bool operator==(const Book& x)const;
	bool operator!=(const Book& x)const;
	friend std::ostream& operator<<(std::ostream& out, const Book& x);
	friend std::istream&operator>>(std::istream& in, Book& x);
private:
	int id;
	std::string author;
	std::string book_name;
};