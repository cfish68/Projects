//File Name: struct_store.cpp
//Author: Chaim Fishman
//ID:208509349
//Project: Intro to Computer Science HW12.1
//Description: This program will be a store database.
//The program can Add items, sell items, say what the price is,
//reorder products and print products to screen.
#include <iostream>
#include <cstring>
#pragma warning (disable:4996)

using namespace std;

//struct product
struct Item
{ 
	int code;
	char name[20];
	int amt;
	int min;
	float price;
};


//checks if the item exists
//if item exists index of the item is returned
//else it returns 0.
int item_exist(Item* store, int code, int numItems);


//will check if item exists if it does will add amount
//if it does not exist will check if store has room for it
//if store has room for item, item will be added.
void addItem(Item* store, int maxItems, int& numItems);

//will output the price of item entered.
//if item does not exist will output ERROR.
void findPrice(Item* store, int numItems);

//remove amount from certain item if there is enough
//if there isnt enough ERROR will be outputed
void sold(Item* store, int numItems);

//will print to the user which items are insufficient to minimum amount
void order(Item* store, int numItems);

//will print out all of the items on display. 
void print(Item* store, int numItems);
enum cases { EXIT, ADD, FIND, SOLD, ORDER, PRINT };
int main()
{
	Item* store;
	int maxItems;
	int numItems = 0;
	int choice;
	cout << "enter max number of items: " << endl;
	cin >> maxItems;
	store = new Item[maxItems];

	do {
		cout << "enter 0-5:\n";

		cin >> choice;

		switch (choice) {
		case EXIT:	break;

		case ADD:	addItem(store, maxItems, numItems);
			break;

		case FIND: 	findPrice(store, numItems);
			break;

		case SOLD:	sold(store, numItems);
			break;

		case ORDER:	order(store, numItems);
			break;

		case PRINT: 	print(store, numItems);
			break;

		default: 	cout << "ERROR" << endl;
		}
	} while (choice != 0);
	//if you don't want the world to end............delete [] store;
	return 0;
}


int item_exist(Item* store, int code, int numItems)
{
	for (int i = 0; i < numItems; i++)
	{
		if (store[i].code == code)
			return i;
	}
	return -1;
}

void addItem(Item* store, int maxItems, int& numItems)
{
	int code, amount, minimum;
	float price;
	char name[20];
	cout << "enter code:\n"; cin >> code;
	cout << "enter name:\n"; cin >> name;
	cout << "enter amount:\n"; cin >> amount;
	cout << "enter minimum amount:\n"; cin >> minimum;
	cout << "enter price:\n"; cin >> price;
	int i = item_exist(store, code, numItems);
	//check if item is already there
	//if item does exitst function will return where it exists and increment amt.
	if (i != -1)
	{
		//if code was found and name does not match
		if ((strcmp(store[i].name, name)) != 0)
		{
			cout << "ERROR:\n";
			return;
		}
		store[i].amt+=amount;
		return;
	}
	//if item does not exist and there is no room to add.
	if (numItems == maxItems)
	{
		cout << "ERROR\n";
				return;
	}
	//if we made here in the function add a new item.
	for(int i = 0; i < numItems; i++)
		if (strcmp(store[i].name, name) == 0)
		{
			cout << "ERROR\n";
			return;
		}
	store[numItems].code = code;
	strncpy(store[numItems].name, name, 20);
	store[numItems].amt = amount;
	store[numItems].min = minimum;
	store[numItems].price = price;
	numItems++;
	return;
}

void sold(Item* store, int numItems)
{
	int code, amount;

	cout << "enter code: "; cin >> code;
	cout << "enter amount "; cin >> amount;
	int i = item_exist(store, code, numItems);
	if (i == -1)
	{
		cout << "ERROR\n";
		return;
	}
	if (store[i].amt < amount)
	{
		cout << "insufficient items\n";
		return;
	}
	
	store[i].amt -= amount;
	return;
}

void print(Item* store, int numItems)
{
	for (int i = 0; i < numItems; i++)
	{
		cout << "name: " << store[i].name << endl;
		cout << "code: " << store[i].code << endl;
		cout << "amount: " << store[i].amt << endl;
		cout << "minimum amount: " << store[i].min << endl;
	//	cout.precision(2);
	//	cout << fixed;
		cout << "price: " << store[i].price << endl;
		cout << endl;
	}
}


void findPrice(Item* store, int numItems)
{
	int code;
	cout << "enter code: "; cin >> code;
	int i = item_exist(store, code, numItems);
	if (i != -1)
	{
	//	cout.precision(2);
	//	cout << fixed;
		cout << "price: " << store[i].price << endl;
	}
	else
		cout << "ERROR\n";
	return;
	
}

void order(Item* store, int numItems)
{
	//check all the items to see if any are missing stock.
	for (int i = 0; i < numItems; i++)
	{
		if (store[i].amt < store[i].min)
		{
			cout << "item name: " << store[i].name << endl;
			cout << "code: " << store[i].code << endl;
			cout << "amount to order: " << (store[i].min - store[i].amt + 5) << endl;
			store[i].amt += (store[i].min - store[i].amt + 5);
		}
	}
}
/*
enter max number of items:
4
enter 0-5:
1
enter code:
12
enter name:
clothes
enter amount:
3
enter minimum amount:
5
enter price:
12.5
enter 0-5:

1
enter code:
13
enter name:
food
enter amount:
15
enter minimum amount:
10
enter price:
9.75
enter 0-5:


1
enter code:
14
enter name:
games
enter amount:
20
enter minimum amount:
25
enter price:
50.75
enter 0-5:

1
enter code:
15
enter name:
electric
enter amount:
20
enter minimum amount:
5
enter price:
37.90
enter 0-5:


4
item name: clothes
code: 12
amount to order: 7
item name: games
code: 14
amount to order: 10
enter 0-5:

5
name: clothes
code: 12
amount: 10
minimum amount: 5
price: 12.5

name: food
code: 13
amount: 15
minimum amount: 10
price: 9.75

name: games
code: 14
amount: 30
minimum amount: 25
price: 50.75

name: electric
code: 15
amount: 20
minimum amount: 5
price: 37.9

enter 0-5:*/