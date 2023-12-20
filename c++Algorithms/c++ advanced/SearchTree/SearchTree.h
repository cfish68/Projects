#pragma once
#pragma once
#include "Tree.h"
#include <iostream>
using namespace std;

template<class T>
class SearchTree : public Tree<T>
{

public:
	void add(T value);
	bool  search(T value)
	{
		return search(Tree<T>::root, value);
	}
	void remove(T val);
	void deleteNode(typename Tree<T>::Node* current, T val);
	T successor(T val);
	T sHelper(typename Tree<T>::Node* head, T val);
	void deleteDuplicates();
	


private:
	void add(typename Tree<T>::Node* current, T val);
	bool  search(typename Tree<T>::Node* current, T val);
};

template <class T>
void SearchTree<T>::add(T val)
{
	// add value to binary search tree 
	if (!Tree<T>::root)
	{
		Tree<T>::root = new typename Tree<T>::Node(val);
		return;
	}
	add(Tree<T>::root, val);
}

template<class T>
inline void SearchTree<T>::remove(T val)
{
	deleteNode(Tree<T>::root, val);
}

template<class T>
inline void SearchTree<T>::deleteNode(typename Tree<T>::Node* current, T val)
{
	if (!current)
		return;
	if (current->value == val)
	{
		if(current->right!=NULL)
		{
			if (current->right->left == NULL && current->left->right == NULL)
			{
				current->value = current->right->value;
				delete current->right;
				current->right = NULL;
			}
			T s = successor(val);
			deleteNode(current, s);
			current->value = s;
			return;
		}
	}
	
	if (current->left != NULL) {
		if (current->left->value == val)
		{
			
			if (current->left->left == NULL&&current->left->right==NULL)
			{
				delete current->left;
				current->left = NULL;
				return;
			}
			else if (current->left->left == NULL)
			{
				typename Tree<T>::Node* temp = current->left;
				current->left = current->left->right;
				delete temp;
				return;
			}
			else if (current->left->right == NULL)
			{
				typename Tree<T>::Node* temp = current->left;
				current->left = current->left->left;
				delete temp;
				return;
			}
			else {
				T s = successor(val);
				deleteNode(current, s);
				current->left->value = s;
				return;
			}
		}
	}
	if (current->right != NULL) {
		if (current->right->value == val)
		{

			if (current->right->left == NULL && current->right->right == NULL)
			{
				delete current->right;
				current->right = NULL;
				return;
			}
			else if (current->right->left == NULL)
			{
				typename Tree<T>::Node* temp = current->right;
				current->right = current->right->right;
				delete temp;
				return;
			}
			else if (current->right->right == NULL)
			{
				typename Tree<T>::Node* temp = current->right;
				current->right = current->right->left;
				delete temp;
				return;
			}
			else {
				T s = successor(val);
				deleteNode(current, s);
				current->left->value = s;
				return;
			}
		}
	}

	 if (val < current->value)
		deleteNode(current->left, val);
	else deleteNode(current->right, val);
	
}

template<class T>
inline T SearchTree<T>::successor(T val)
{
	return sHelper(Tree<T>::root, val);
}

template<class T>
inline T SearchTree<T>::sHelper(typename Tree<T>::Node* current, T val)
{
	if (!current)
		return NULL;
	typename Tree<T>::Node* temp = current;
	if (temp->value == val)
	{
	    if (temp->right == NULL && temp->left == NULL)
			throw "no successor\n";
		//find the successor
		temp = temp->right;
		
		while (temp->left)
			temp = temp->left;
		return temp->value;
	}
	if (current->value > val)
	{
		 return sHelper(current->left, val);
	}
	return sHelper(current->right, val);
	
}




template <class T>
void SearchTree<T>::add(typename Tree<T>::Node* current, T val)
{
	if (current->value < val)

		if (!current->right)
		{
			current->right = new typename Tree<T>::Node(val);
			return;
		}
		else add(current->right, val);
	else

		if (!current->left)
		{
			current->left = new typename Tree<T>::Node(val);
			return;
		}
		else add(current->left, val);
}

template <class T>
bool SearchTree<T>::search(typename Tree<T>::Node* current, T val)
{
	// see if argument value occurs in tree
	if (!current)
		return false;	// not found
	if (current->value == val)
		return true;
	if (current->value < val)
		return search(current->right, val);
	else
		return search(current->left, val);
}

template<class T>
inline void SearchTree<T>::deleteDuplicates()
{
	typename QueueVector<typename Tree<T>::Node*>::QueueVector Q(100);
	T arr[100];
	int i = 0;
	if (Tree<T>::root != NULL)
		Q.enqueue(Tree<T>::root);
	while (Q.isEmpty() != true)
	{
		typename Tree<T>::Node* x = Q.dequeue();
		arr[i++] = x->value;
		if (x->left != NULL)
			Q.enqueue((x->left));
		if (x->right != NULL)
			Q.enqueue((x->right));
	}
	for (i = i - 1; i > 0; i--)
	{
		if (arr[i] = arr[i - 1])
		{
			deleteNode(Tree<T>::root, arr[i]);
		}
	}


}
