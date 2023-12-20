#include "StackList.h"
#include <iostream>


StackList::StackList()
{};
StackList::StackList(const StackList& h) :data(h.data)
{

}
void StackList::clear()
{
	//delete data
}

bool StackList::isEmpty() const
{
	return data.isEmpty();
}
int StackList::pop()
{
	int t = data.firstElement();
	data.removeFirst();
	return t;
}
void StackList::push(int value)
{
	data.add(value);
	return;
}
int StackList::top()
{
	return data.firstElement();
}
