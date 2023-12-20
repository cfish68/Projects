#include "QueueStack.h"
#include <iostream>

QueueStack::QueueStack()
{}

void QueueStack::clear()
{

}
int QueueStack::dequeue()
{
	return data1.pop();
}
void QueueStack::enqueue(int value)
{
	StackList helper;
	while (!data1.isEmpty())
	{
		helper.push(data1.pop());
	}
	data1.push(value);
	while(!helper.isEmpty())
	data1.push(helper.pop());
}
int QueueStack::front()
{
	return data1.top();
}
bool QueueStack::isEmpty() const
{
	return data1.isEmpty();
}
