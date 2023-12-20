#include <iostream>
#include <list>
#include <algorithm>
#include "Book.h"
using namespace std;


int main()
{
	list<Book> lst;
	Book x;
	char choice;
	do
	{
		cout << "enter a-e:\n";
		cin >> choice;
		if (choice == 'a')
		{
			cout << "enter a book\n";
			
			cin >> x;
			lst.push_back(x);
		}
		if (choice == 'b')
		{
		    cout << "enter a book\n";
			cin >> x;
			lst.remove(x);
		}
		if (choice == 'c')
		{
		    cout << "enter a book\n";
			cin >> x;
			list<Book>::iterator it = find(lst.begin(), lst.end(), x);
			if (it != lst.end())
				cout << "exist\n";
			else cout << "not exist\n";
		}
		if (choice == 'd')
		{
			lst.sort();
			list<Book>::iterator it;
			for (it = lst.begin(); it != lst.end(); it++)
				cout << *it << endl;
			
		}


	} while (choice != 'e');
		return 0;

}