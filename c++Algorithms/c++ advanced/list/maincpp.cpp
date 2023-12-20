//Author: Chaim Fishman
//208509349
#include <iostream>
#include "List.h"
using namespace std;
List merge(List one, List two)
{
	List merged(one);
	merged.insert_list(two);
	return merged;
}
List makeSet(List a)
{
	a.remove_doubles();
	return a;
}
List reverse(List& a)
{
	a.reverse_list();
	return a;
}
int main()
{
	List lst1, lst2, mergedList;

	cout << "enter sorted values for the first list:" << endl;
	cin >> lst1;
	cout << "enter sorted values for the second list:" << endl;
	cin >> lst2;

	mergedList = merge(lst1, lst2);
	cout << "the new merged list: " << mergedList << endl;

	mergedList = makeSet(mergedList);
	cout << "the new merged set: " << mergedList << endl;

	mergedList = reverse(mergedList);
	cout << "the new merged reverse: " << mergedList << endl;


	return 0;
}

