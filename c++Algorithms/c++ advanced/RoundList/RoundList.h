#pragma once
#include"List.h"

class RoundList : public List
{
public:
	RoundList();
	RoundList(const RoundList&);
	~RoundList();

	int search(const int& val);

	void removeFirst();
	void clear();
	void addToEnd(int n);
	void add(int n);
};