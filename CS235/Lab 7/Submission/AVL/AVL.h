#pragma once
#include <string>
#include "Node.h"
#include "AVLInterface.h"

using namespace std;

class AVL : public AVLInterface {
public:


	AVL()
	{
		root = NULL;
	}
	~AVL() 
	{
		clear();
	}
	Node * getRootNode() const;
	bool add(int data);
	bool add(int data, Node *place, int height);
	bool remove(int data);
	Node * remove(int data, Node * place);
	Node * replace_parent(Node* place1, Node * place2);
	bool contains(int data);
	bool contains(int data, Node * place);

	Node* balance(Node * place);

	void deleteNode(Node * place);
	void clear();

	Node * rebalance_left(Node* place);
	Node * rebalance_right(Node*& place);

	Node * rotate_right(Node* place);
	Node * rotate_left(Node*& place);

protected:
	Node * root;
};