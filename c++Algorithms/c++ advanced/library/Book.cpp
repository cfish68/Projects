#include "Book.h"

Book::Book()
{
	id = 0;
	author = "";
	book_name = "";
}

bool Book::operator<(const Book& x)const
{
	int comp = author.compare(x.author);
	if (comp == 0) {
		int comp2 = book_name.compare(x.book_name);
		if (comp2 < 0)
			return true;
		return false;
	}
	if (comp < 0)
		return true;
	return false;
}

bool Book::operator>(const Book& x)const
{
	int comp = author.compare(x.author);
	if (comp == 0) {
		int comp2 = book_name.compare(x.book_name);
		if (comp2 > 0)
			return true;
		return false;
	}
	if (comp > 0)
		return true;
	return false;
}

bool Book::operator<=(const Book& x)const
{
	int comp = author.compare(x.author);
	if (comp == 0) {
		int comp2 = book_name.compare(x.book_name);
		if (comp2 <= 0)
			return true;
		return false;
	}
	if (comp <= 0)
		return true;
	return false;
}

bool Book::operator>=(const Book& x)const
{
	int comp = author.compare(x.author);
	if (comp == 0) {
		int comp2 = book_name.compare(x.book_name);
		if (comp2 >= 0)
			return true;
		return false;
	}
	if (comp >= 0)
		return true;
	return false;
}

bool Book::operator==(const Book& x)const
{
	int comp = author.compare(x.author);
	if (comp == 0) {
		int comp2 = book_name.compare(x.book_name);
		if (comp2 == 0)
			return true;
		return false;
	}
	return false;
}

bool Book::operator!=(const Book& x)const
{
	int comp = author.compare(x.author);
	if (comp == 0) {
		int comp2 = book_name.compare(x.book_name);
		if (comp2 == 0)
			return false;
	}
	return true;
}

std::ostream& operator<<(std::ostream& out, const Book& x)
{
	out << x.id << ' ' << x.author << ' ' << x.book_name;
	return out;
}

std::istream& operator>>(std::istream& in, Book& x)
{
	in >> x.id >> x.author >> x.book_name;
	return in;
}
