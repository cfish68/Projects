#pragma once
#pragma once
#include "QueueVector.h"
#include <iostream>
using namespace std;

//-----------------------------------
//  class Tree (Binary Trees)
// process nodes in Pre/In/Post  order
//-----------------------------------
template <class T>
class Tree
{
protected:
	//--------------------------------------------------------
	//  inner class Node
	//      a single Node from a binary tree
	//--------------------------------------------------------
	class Node
	{
	public:
		Node* left;
		Node* right;
		T value;
		Node(T val) : value(val), left(NULL), right(NULL) {}
		Node(T val, Node* l, Node* r) : value(val), left(l), right(r) {}
		Node* operator=(Node* n) {
			value = n.value;
			left = n.left;
			right = n.right;
		}
	};		//end of Node class

	//data member of tree
	
	Node* root;
public:
	
	Tree() { root = NULL; }	 // initialize tree
	~Tree();
	int isEmpty() const;
	void clear() { clear(root); root = NULL; }
	void preOrder() { preOrder(root); }
	void inOrder() { inOrder(root); }
	void postOrder() { postOrder(root); }

	virtual void process(T val) { cout << val << " "; }
	virtual void add(T val) = 0;
	virtual bool search(T val) = 0;
	virtual void remove(T val) = 0;


	int height();
	int heightHelper(Node* root);
	void reflect();
	void reflectHelper(Node* root);
	void breadthScan();


private:
	//private function for not give acsses to user
	void  clear(Node* current);
	void  preOrder(Node* current);
	void  inOrder(Node* current);
	void  postOrder(Node* current);

};







//----------------------------------------------------------
//  class Tree implementation
//----------------------------------------------------------
template <class T>
Tree<T>::~Tree() // deallocate tree
{
	if (root != NULL)
		clear(root);
}
template <class T>
void Tree<T>::clear(Node* current)
{
	if (current)
	{    // Release memory associated with children
		if (current->left)
			clear(current->left);
		if (current->right)
			clear(current->right);
		delete current;
	}
}

template <class T>
int Tree<T>::isEmpty() const
{
	return  root == NULL;
}

// preOrder processing of tree rooted at current
template <class T>
void Tree<T>::preOrder(Node* current)
{    // visit Node, left child, right child
	if (current)
	{   // process current Node
		process(current->value);
		// then visit children
		preOrder(current->left);
		preOrder(current->right);
	}
}

// inOrder processing of tree rooted at current
template <class T>
void Tree<T>::inOrder(Node* current)
{    // visit left child, Node, right child
	if (current)
	{
		inOrder(current->left);
		process(current->value);
		inOrder(current->right);
	}
}

// postOrder processing of tree rooted at current
template <class T>
void Tree<T>::postOrder(Node* current)
{    // visit left child, right child, node
	if (current)
	{
		postOrder(current->left);
		postOrder(current->right);
		process(current->value);
	}
}


template <class T>
int Tree<T>::height()
{
	return heightHelper(root);
}
template <class T>
int Tree<T>::heightHelper(Node* root)
{
	if (root == NULL)
		return -1;
	if (left == NULL && right == NULL)
		return 0;
	int l = heightHelper(root->left);
	int r = heightHelper(root->right);
	if (l > r)
		return l+1;
	return r+1;
}
template <class T>
void Tree<T>::reflect()
{
	reflectHelper(root);
}

template <class T>
void Tree<T>::reflectHelper(Node* root)
{
	if (!root)
		return;
	reflectHelper(root->left);
	reflectHelper(root->right);
	Node* temp = root->left;
	root->left = root->right;
	root->right = temp;
	return;

}

template <class T>
void Tree<T>::breadthScan()
{
	QueueVector<Node*> Q(100);
	if (root != NULL)
		Q.enqueue(root);
	while (Q.isEmpty() != true)
	{
		Node* x = Q.dequeue();
		process(x->value);
		if (x->left != NULL)
			Q.enqueue((x->left));
		if (x->right != NULL)
			Q.enqueue((x->right));
	}
}