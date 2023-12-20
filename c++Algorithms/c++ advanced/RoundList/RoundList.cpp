#include "RoundList.h"
#include <iostream>


RoundList::RoundList() :List(){}
RoundList::RoundList(const RoundList& a) : List(a)
{
	Link* src, * trg;
	if (a.head == NULL)
		head = head;
	else
	{
		head = new Link((a.head)->value, NULL);
		src = a.head;
		trg = head;
		while (src->next != NULL)
		{
			trg->next = new Link
			((src->next)->value, NULL);
			src = src->next;
			trg = trg->next;
		}
		trg->next = head;
	}

}


RoundList::~RoundList()
{
	clear();
}
void RoundList::clear()
{
	
		// empty all elements from the List
	if (head == NULL)
		//throw   "list was empty already\n";
		return;
		Link* next = head->next;
		head->next = NULL;
		for (Link* p = next; p != head; p = next)
		{
			// delete the element pointed to by p
			next = p->next;
			p->next = NULL;
			delete p;
		}
		delete head;
		head = NULL;
	
	// mark that the List contains no elements 87. head= NULL;
}

int RoundList::search(const int& val)
{
	if (val < 0)
		return -1; //throw "illegal value entered"
	if (head == NULL)
		return -1;
	Link* itar = head;
	for (int i = 0; i < val; i++)
		itar = itar->next;
	return itar->value;
}



void RoundList::removeFirst()
{
	// make sure there is a first element
	if (head==NULL)
		//throw "the List is empty, no Elements to remove";
		return;
	if (head->next == head)
	{
		delete head;
		head = NULL;
		return;
	}
	// save pointer to the removed node
	Link* p = head;
	// reassign the first node
	head = p->next;
	p->next = NULL;
	Link* itar=head;
	while (itar->next != p)
		itar = itar->next;
	
	//make lsat point at new head
	itar->next = head;

	// recover memory used by the first element
	delete p;
}

void RoundList::addToEnd(int n)
{
	if (head == NULL)
	{
		add(n);
	}
	else
	{
		Link* x = new Link(n, head);
		Link* pt = head;
		while (pt->next != head)
			pt = pt->next;
		pt->next = x;
	}
}

void RoundList::add(int n)
{
	if (head == NULL)
	{
		//point first at itself since its the only one. 
		head = new Link(n, NULL);
		head->next = head;
	}
	//Add a new value to the front of a Linked List
	else {
		Link* last = head;
		while (last->next != head)
		{
			last = last->next;
		}
		head = new Link(n, head);
		last->next = head;
	}
	if (head == NULL)
		throw "failed in memory allocation";
}