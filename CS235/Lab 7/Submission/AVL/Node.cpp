#include "Node.h"
#include <algorithm>

using namespace std;

int Node::getData() const
{
	return data;
}

Node* Node::getLeftChild() const
{
	return left;
}

Node* Node::getRightChild() const
{
	return right;
}

int Node::getHeight()
{
	return height;
}

void Node::setData(int d) 
{
	data = d;
}

void Node::setLeftChild(Node* place) 
{
	left = place;
}

void Node::setRightChild(Node* place) 
{
	right = place;
}

bool Node::hasChild() 
{
	return(left != NULL || right != NULL);
}

int Node::updateHeight()
{

	int lh = -1;
	int rh = -1;

	if (left != NULL) {
		lh = left->updateHeight();
	}

	if (right != NULL) {
		rh = right->updateHeight();
	}

	return max(lh, rh) + 1;
}

bool Node::rightBalance() 
{
	this->balance = RIGHT_HEAVY;
	return true;
}

bool Node::leftBalance()
{
	this->balance = LEFT_HEAVY;
	return true;
}

bool Node::balanceBalance() 
{
	this->balance = BALANCED;
	return true;
}