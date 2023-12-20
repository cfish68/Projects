#include <iostream>
using namespace std;

#include "Date.h"

enum choice{Enterdate=1, PreAdd, PostAdd, ADD, Greater, Less, Equal, Exit = -1};
int main(){
	int m, d, y, x;
	char t;
	cout << "enter a date\n";
	cin >> m >> t >> d >> t >> y;
	Date one(m, d, y);
	one.print();
	while (1)
	{
		cout << "Enter an action code:\n";

		cin >> x;
		switch (x) {
		case Enterdate:
			cout << "Enter a date\n";
			cin >> m >> t >> d >> t >> y;
			one.setDate(m, d, y);
			one.print();
			break;
		case PreAdd:
			(++one).print();
			break;
		case PostAdd:
			(one++).print();
			break;
		case ADD:
			cout << "Enter # days\n";
			cin >> d;
			(one += d).print();
			break;
		case Greater:
			cout << "Enter a date\n";
			cin >> m >> t >> d >> t >> y;
			(one > Date(m, d, y)) ? cout << ">: true\n" : cout << ">: false\n";
			break;
		case Less:
			cout << "Enter a date\n";
			cin >> m >> t >> d >> t >> y;
			(one < Date(m, d, y)) ? cout << "<: true\n" : cout << "<: false\n";
			break;
		case Equal:
			cout << "Enter a date\n";
			cin >> m >> t >> d >> t >> y;
			(one == Date(m, d, y)) ? cout << "==: true\n" : cout << "==: false\n";
			break;
		case Exit:
			return 0;
		}
	}
}
/*
enter a date
10/11996
/1996
10/1/1996
What do you want to do
4
Enter # days
360
10/1/1997
What do you want to do
2
11/1/1997
What do you want to do
3
11/1/1997
What do you want to do
4
Enter # days
3
15/1/1997
What do you want to do
5
Enter a date
10/30/1996
>: trueWhat do you want to do*/