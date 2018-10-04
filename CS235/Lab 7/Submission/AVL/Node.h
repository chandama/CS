#pragma once
#include "NodeInterface.h"
#include <iostream>

class Node : public NodeInterface {
friend class AVL;
public:
	enum balance_type { LEFT_HEAVY = -1, BALANCED = 0, RIGHT_HEAVY = +1 };

	balance_type balance;

	Node()
	{
		data = 0;
		right = NULL;
		left = NULL;
		height = -1;
		balance = BALANCED;
	}

	Node(int d, int h) 
	{
		data = d;
		left = NULL;
		right = NULL;
		height = h;
		balance = BALANCED;
	}
	~Node() 
	{
		left = NULL;
		right = NULL;
	}

	int getData() const;

	Node* getLeftChild() const;
	Node* getRightChild() const;
	void setData(int d);
	void setLeftChild(Node* place);
	void setRightChild(Node* place);
	bool hasChild();

	bool rightBalance();
	bool leftBalance();
	bool balanceBalance();

	int updateHeight();

	int getHeight();
protected:
	int data;
	Node * left;
	Node * right;
	int height;
};