//Chaim Fishman
//208509349
#pragma once
#include <iostream>
using namespace std;
class List
{
public:
	//--------------------------------------------
		// inner class link
		// a single element for the linked List
		//--------------------------------------------
	class Link
	{
	public:
		// constructor
		Link(int linkValue, Link* nextPtr);
		Link(const Link&);
		// data areas
		int value;
		Link* next;
		void Print();
	}; //end of class Link
public:
	// constructors
	List();
	List(const List&);
	~List();
	// operations
	void insert(int value);
	int firstElement() const;
	bool search(const int& value) const;
	bool isEmpty() const;
	void removeFirst();
	void clear();
	void remove(int key);

	List operator=(List l);
	friend istream& operator>>(istream& is, List& l);
	friend ostream& operator<<(ostream& os, List l);

private:
	// data field
	Link* head;
};

//------------------------------------------------
// class Link implementation
//------------------------------------------------
List::Link::Link(int val, Link* nxt) : value(val), next(nxt) {}
List::Link::Link(const Link& source) : value(source.value), next(source.next) {}
//--------------------------------------------
	// class List implementation
	//-------------------------------------------- 
List::List() : head(NULL) {};

// no further initialization

List::List(const List& l)
{
	Link* src, * trg;
	if (l.head == NULL)
		head = NULL;
	else
	{
		head = new Link((l.head)->value, NULL);
		src = l.head;
		trg = head;
		while (src->next != NULL)
		{
			trg->next = new Link
			((src->next)->value, NULL);
			src = src->next;
			trg = trg->next;
		}
	}
}

//deep copy
List List::operator=(List l)

{
	Link* src, * trg;
	if (l.head == NULL)
		head = NULL;
	else
	{
		head = new Link((l.head)->value, NULL);
		src = l.head;
		trg = head;
		while (src->next != NULL)
		{
			trg->next = new Link
			((src->next)->value, NULL);
			src = src->next;
			trg = trg->next;
		}
	}
	return *this;
}



List::~List()
{
	clear();
}
void List::clear()
{
	// empty all elements from the List
	Link* next;
	for (Link* p = head; p != NULL; p = next)
	{
		// delete the element pointed to by p
		next = p->next;
		p->next = NULL;
		delete p;
	}
	// mark that the List contains no elements 87. head= nullptr;
}
bool List::isEmpty() const
{
	// test to see if the List is empty
		// List is empty if the pointer to the head
		// Link is null
	return head == NULL;
}
void List::insert(int val)
{
	//case empty list
	//Add a new value to the front of a Linked List
	if (head == NULL) {
		head = new Link(val, NULL);
	}
	else if (head->value <= val)
		head = new Link(val, head);
	else//if not empty
	{
		Link* itar = head;
		while (itar->next != NULL && itar->next->value > val)
		{
			itar = itar->next;
		}
		Link* add = new Link(val, itar->next);
		itar->next = add;
	}
	if (head == NULL)
		throw "failed in memory allocation";
}
int List::firstElement() const
{
	// return first value in List
	if (isEmpty())
		throw "the List is empty, no first Element";
	return head->value;
}
bool List::search(const int& val) const
{
	// loop to test each element
	for (Link* p = head; p != NULL; p = p->next)
		if (val == p->value)
			return true;
	// not found
	return false;
}
void List::removeFirst()
{
	// make sure there is a first element
	if (isEmpty())
		throw "the List is empty, no Elements to remove";
	// save pointer to the removed node
	Link* p = head;
	// reassign the first node
	head = p->next;
	p->next = NULL;
	// recover memory used by the first element
	delete p;
}

//print list
ostream& operator<<(ostream& out, List lst)
{
	lst.head->Print();
	return out;
}
void List::Link::Print()
{
	Link* itar = this;      //may need to skip this line.
	while (itar != NULL)
	{
		cout << itar->value << ' ';
		itar = itar->next;
	}
	cout << endl;
	return;
}

istream& operator>>(istream& is, List& l)
{
	int x, y;
	is >> x;
	l.insert(x);
	is >> y;
	while (y < x)
	{
		l.insert(y);
		x = y;
		is >> y;
	}
	return is;

}

void List::remove(int key)
{
	Link* itar = head;
	//case empty
	if (itar == NULL)
		throw "value not found\n";
	//case1
	if (itar->value == key)//uf the head holds the value.
		//in general head shouldnt be containng value not sure why the hw implemetation does it this way.
	{
		Link* temp = itar;
		head = itar->next;
		delete temp;
		return;
	}
	while (itar->next != NULL && itar->next->value != key)
	{
		itar = itar->next;
	}
	if (itar->next == NULL)
		throw "value not found\n";
	if (itar->next->value == key)
	{
		Link* temp = itar->next;
		itar->next = temp->next;
		delete temp;
		return;
	}


}