//Chaim Fishman
//disclaimer(very little comments on this) I also 
//did not like the implementation we had to do for the waiting list.
//did not make much sense to me did anyways it seems to work
//have a nice day:)
#include <iostream>
#include <queue>
#include <fstream>
#include "Family.h"
using namespace std;


enum choice { ADD = 1, DEL, UPDATE, WAITING, RISHUM, PRINT, CLASS };

void setFile(fstream& f);

void add(fstream& f);
void del(fstream& f, int num);
void update(fstream& f, int num, queue<Family>& q);
void waiting(fstream& f, queue<Family>& q);
bool rishum(fstream& f, int num, int num2);
void print(fstream& f, int id);
void inClass(fstream& f, int num);



int main()
{
	Family fam;
	queue<Family> q;
	fstream file;

	file.open("families.txt", ios::binary | ios::in | ios::out);
	if (!file)
	{
		cout << "ERROR: couldn't open file\n";
		return 0;
	}
	
	setFile(file);

	
	int choice;
	int snum;
	int cnum;
	cout << "Choices are:\n0 to exit\n1 to add a family\n2 to delete a family\n3 to update rishum to classes\n4 to update waiting to classes \n5 to check rishum for a classas\n6 to print a family\n7 to print all the families that participate in a specific class\n";
	cout << "enter 0-7:\n";
	cin >> choice;
	while (choice)
	{
		switch (choice)
		{
		case ADD://add to the file
			try { add(file); }
			catch (const char* msg) { cout << msg; }
			break;
		case DEL://delete from file
			cout << "enter number of family to delete:\n";
			cin >> snum;
			try { del(file, snum); }
			catch (const char* msg) { cout << msg; }
			break;
		case UPDATE://update the list of classes of a family
			cout << "enter number of family to update:\n";
			cin >> snum;
			try { update(file, snum, q); }
			catch (const char* msg) { cout << msg; }
			break;
		case WAITING://update the list of classes of a waiting family
			waiting(file, q);
			break;
		case RISHUM://check rishum to a specific class
			cout << "enter number of family to check rishum:\n";
			cin >> snum;
			cout << "enter number of class to check rishum:\n";
			cin >> cnum;
			try
			{
				cout << "The family is" << (rishum(file, snum, cnum) ? " " : " not ") << "taking the class\n";
			}
			catch (const char* msg) { cout << msg; }
			break;
		case PRINT://print the details of a specific family
			cout << "enter number of family to print:\n";
			cin >> snum;
			try { print(file, snum); }
			catch (const char* msg) { cout << msg; }
			break;
		case CLASS://print the details of all the families that are taking a specific class
			cout << "enter number of class to check rishum:\n";
			cin >> cnum;
			try { inClass(file, cnum); }
			catch (const char* msg) { cout << msg; }
			break;
		default:
			cout << "ERROR: invalid choice\n";

		}
		cout << "\nenter 0-7:\n";
		cin >> choice;
	}
	file.close();
	return 0;
}

void setFile(fstream& f)
{
	Family blank;
	char newline('\n');
	for (int i = 0; i < 100; i++)
	{
		f.write(reinterpret_cast<const char*>(&blank), sizeof(blank));
		f.put(newline);
	}
}

void add(fstream& f)
{
	Family fam;
	string name;
	int members;
	int phone;
	int id;
	cin >> id;
	if (id < 1 || id>100)//illegal family id
		throw "ERROR: Invalid family number\n";
	//check if id was already taken
	f.seekg((id - 1) * 41);
	f.read(reinterpret_cast<char*>  (&fam), sizeof(Family));
	if (fam.get_id() != 0)
		throw "fmaily is already in the file\n";
	cin >> name >> members >> phone;
	Family added(id, name, members, phone);
	f.seekp((id - 1) * 41);
	f.write(reinterpret_cast<const char*>(&added), sizeof(Family));

	
}

void del(fstream& f, int num)
{
	if (num < 1 || num>100)
		throw "ERROR: Invalid family number\n";
	f.seekp((num - 1) * 41);
	f.put(0);
}

void update(fstream& f, int num, queue<Family>& q)
{
	if (num < 1 || num>100)
		throw "ERROR: Invalid family number\n";
	int activity;
	cin >> activity;
	if (activity < 1 || activity > 6)
		throw "ERROR: Family is not in the file\n";
	bool act[6];
	int activity_counter = 0;
	f.seekg(35);
	for (int i = 1; i <= 100; i++)
	{
		f.seekg(((i-1)*41)+35);
		for (int j = 0; j < 6; j++)
		{
			f.read(reinterpret_cast<char*>(&act[j]), 1);
		}
		if (act[activity])
			activity_counter +=1;
	}
	Family waiting;
	f.seekg((num - 1) * 41);
	f.read(reinterpret_cast<char*>(&waiting), sizeof(Family));
	if (activity_counter >= 10)
	{
		cout << "There is no more space, family will be put on the waiting list\n";

		waiting.set_act(activity);
		q.push(waiting);
		return;
	}
	waiting.set_activity(activity);
	f.seekp((num - 1) * 41);
	f.write(reinterpret_cast<char*>(&waiting), sizeof(Family));
}

void waiting(fstream& f, queue<Family>& q)
{
	queue<Family> temp;
	char YN;
	int id;
	Family x, y;
	int activity;
	while (q.empty() == false)
	{
		x=q.front();
		activity = x.which_activity();
		bool act[6];
		int activity_counter = 0;
		for (int i = 1; i <= 100; i++)
		{
			f.seekg((i - 1), 35);
			f.read(reinterpret_cast<char*>(&act), sizeof(bool[6]));
			if (act[activity])
				activity_counter +=1;
		}
		if (activity_counter < 10)
		{
			//ask family if they would like to join activity
			cout << x.get_name() << ' ' << x.getPhone() << endl;
			cin >> YN;
			if (YN == 'Y')//updateActivity
			{
				id = x.get_id();
				f.seekg((id - 1) * 41);
				f.read(reinterpret_cast<char*>(&y), sizeof(Family));
				y.set_activity(activity);
				f.seekp((id - 1) * 41);
				f.write(reinterpret_cast<char*>(&y), sizeof(Family));
			}
		}
		else
		{
			temp.push(x);
			q.pop();
		}
	}
	while (temp.empty() == false)
	{
		x = temp.front();
		q.push(x);
		temp.pop();
	}
}

bool rishum(fstream& f, int num, int num2)
{
	if (num < 1 || num>100)
		throw "ERROR: Invalid family number\n";
	if (num2 < 1 || num2>6)
		throw "ERROR: Invalid class number\n";
	Family fam;
	f.seekg((num - 1) * 41);
	f.read(reinterpret_cast<char*>(&fam), sizeof(Family));
	if (fam.get_id() == 0)
		throw "ERROR: Family is not in the file\n";

	return fam.activity(num2);

}

void print(fstream& f, int id)
{
	if (id < 1 || id>100)
		throw "ERROR: Invalid family number\n";
	Family x;
	f.seekg((id - 1) * 41);
	f.read(reinterpret_cast<char*>  (&x), sizeof(Family));
	if (x.get_id() == 0)
		throw "ERROR: Family is not in the file\n";
	x.print();
}

void inClass(fstream& f, int num)
{
	Family x;
	for (int i = 1; i <= 100; i++)
	{
		f.seekg((i - 1) * 41);
		f.read(reinterpret_cast<char*>  (&x), sizeof(Family));
		if (x.activity(num))
			x.print();
	}
}


