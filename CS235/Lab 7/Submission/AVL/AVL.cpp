#include "AVL.h"
#include <string>
#include <cstdlib>
#include <iostream>

using namespace std;

Node * AVL::getRootNode() const
{
	return root;
}

bool AVL::add(int data) 
{
	if (this->contains(data) == true)
	{
		return false;
	}

	if (this->getRootNode() == NULL)
	{
		this->root = new Node(data, 0);
		return true;
	}
	else 
	{

		if (this->getRootNode()->getData() == data)
		{ 
			return false;
		}
		else
		{
			if (add(data, this->getRootNode(), 0)) 
			{
				this->root = balance(this->getRootNode());
				return true;
			}
		}
	}
}

bool AVL::add(int data, Node* place, int height) 
{
	if (data > place->getData())
	{

		if (place->getRightChild() == NULL)
		{
			place->setRightChild(new Node(data, height + 1));

			if (place->balance == Node::BALANCED)
			{
				return place->rightBalance();
			}
			else if (place->balance == Node::LEFT_HEAVY) 
			{
				return place->balanceBalance();
			}
			return true;

		}
		else if (place->getRightChild()->getData() == data)
		{
			return false;
		}
		else 
		{
			return add(data, place->getRightChild(), height + 1);
		}
	}
	else 
	{

		if (place->getLeftChild() == NULL) 
		{
			place->setLeftChild(new Node(data, height + 1));

			if (place->balance == Node::BALANCED)
			{
				return place->leftBalance();
			}
			else if (place->balance == Node::RIGHT_HEAVY) 
			{
				return place->balanceBalance();
			}
			return true;
		}
		else if (place->getLeftChild()->getData() == data) 
		{
			return false;
		}
		else 
		{
			return add(data, place->getLeftChild(), height + 1);
		}
	}
}

bool AVL::remove(int data) 
{
	if (this->root == NULL || this->contains(data) == false)
	{
		return false;
	}
	else
	{
		if (data == this->root->getData() && this->root->getLeftChild() == NULL && this->root->getRightChild() == NULL)
		{

			delete this->root;
			this->root = NULL;
			return true;
		}
		else 
		{
			this->root = remove(data, this->getRootNode());
		}
		this->root = balance(this->getRootNode());
		return true;
	}
}

Node * AVL::remove(int data, Node* place) 
{
	if (data < place->getData()) 
	{
		place->left = remove(data, place->getLeftChild());
		return place;
	}
	else if (data > place->getData())
	{
		place->right = remove(data, place->getRightChild());
		return place;

	}
	else 
	{
		if (place->getLeftChild() == NULL && place->getRightChild() == NULL) 
		{
			delete place;
			place = NULL;
		}
		else if (place->getLeftChild() != NULL)
		{
			place->left = replace_parent(place, place->left);
		}
		else if (place->getRightChild() != NULL)
		{
			Node* temp = place->right;
			delete place;
			place = NULL;
			return temp;
		}

		return place;
	}
}

Node * AVL::replace_parent(Node * old, Node * place) 
{
	if (place->getRightChild() != NULL) 
	{
		place->right = replace_parent(old, place->getRightChild());
		return place;
	}
	else 
	{
		old->setData(place->getData());
		Node* tmp = place->getLeftChild();
		delete place;
		place = NULL;
		return tmp;
	}
}

bool AVL::contains(int data) 
{
	return contains(data, this->getRootNode());
}

bool AVL::contains(int data, Node * place)
{

	if (place == NULL)
	{
		return false;
	}

	if (data == place->getData())
	{
		return true;
	}
	else if (data < place->getData()) 
	{
		return contains(data, place->getLeftChild());
	}
	else
	{
		return contains(data, place->getRightChild());
	}
}

void AVL::clear()
{

	if (this->root != NULL) 
	{
		if (root->left)
		{
			deleteNode(this->getRootNode()->getLeftChild());
		}

		if (root->right) 
		{
			deleteNode(this->getRootNode()->getRightChild());
		}

		delete this->root;
		this->root = NULL;
	}
}

void AVL::deleteNode(Node * place)
{
	if (place->getLeftChild() != NULL)
	{
		deleteNode(place->getLeftChild());
	}

	if (place->getRightChild() != NULL)
	{
		deleteNode(place->getRightChild());
	}

	delete place;
	place = NULL;
}


Node* AVL::balance(Node * place)
{
	//uses recursion to go from the leaves to the root 
	//functions below will be called as the stack is popped
	int lh;
	int rh;
	if (place->left && place->left->hasChild()) 
	{
		place->left = balance(place->left);
	}

	if (place->right && place->right->hasChild()) 
	{
		place->right = balance(place->right);
	}
	if (!place->left)
	{
		lh = -1;
	}
	else 
	{
		lh = place->left->updateHeight();
	}

	if (!place->right) 
	{
		rh = -1;
	}
	else
	{
		rh = place->right->updateHeight();
	}

	if (lh - rh > 1)
	{
		return rebalance_left(place);
	}

	if (rh - lh > 1) 
	{
		return rebalance_right(place);
	}

	if (lh - rh == 1 && place->leftBalance())
	{
		return place;
	}

	if (rh - lh == 1 && place->rightBalance())
	{
		return place;
	}

	if (rh - lh == 0 && place->balanceBalance())
	{
		return place;
	}

	return place;
}

Node * AVL::rebalance_left(Node* place) 
{
	Node* local_root = dynamic_cast<Node*>(place);

	Node* left_child = dynamic_cast<Node*>(place->getLeftChild());
	if (left_child->balance == Node::RIGHT_HEAVY) 
	{
		Node* left_right_child = dynamic_cast<Node*>(left_child->getRightChild());
		if (left_right_child->balance == Node::LEFT_HEAVY)
		{
			left_child->balance = Node::BALANCED;
			left_right_child->balance = Node::BALANCED;
			local_root->balance = Node::RIGHT_HEAVY;
		}
		else if (left_right_child->balance == Node::BALANCED)
		{
			left_child->balance = Node::BALANCED;
			left_right_child->balance = Node::BALANCED;
			local_root->balance = Node::BALANCED;
		}
		else 
		{
			left_child->balance = Node::LEFT_HEAVY;
			left_right_child->balance = Node::BALANCED;
			local_root->balance = Node::BALANCED;
		}
		place->left = rotate_left(place->left);
	}
	else 
	{
		/*
		* In this case the left child (the new root) and the local root (new
		* right child) will both be balanced after the rotation
		*/
		left_child->balance = Node::BALANCED;
		local_root->balance = Node::BALANCED;
	}
	place = rotate_right(place);
	return place;
}

Node * AVL::rebalance_right(Node*& place)
{
	Node* local_root = dynamic_cast<Node*>(place);
	Node* right_child = dynamic_cast<Node*>(place->getRightChild());

	if (right_child->balance == Node::LEFT_HEAVY)
	{
		Node* right_left_child = dynamic_cast<Node*>(right_child->getLeftChild());
		if (right_left_child->balance == Node::RIGHT_HEAVY) 
		{
			right_child->balance = Node::BALANCED;
			right_left_child->balance = Node::BALANCED;
			local_root->balance = Node::LEFT_HEAVY;
		}
		else if (right_left_child->balance == Node::BALANCED)
		{
			right_child->balance = Node::BALANCED;
			right_left_child->balance = Node::BALANCED;
			local_root->balance = Node::BALANCED;
		}
		else
		{
			right_child->balance = Node::RIGHT_HEAVY;
			right_left_child->balance = Node::BALANCED;
			local_root->balance = Node::BALANCED;
		}

		place->right = rotate_right(place->right);
	}
	else 
	{
		right_child->balance = Node::BALANCED;
		local_root->balance = Node::BALANCED;
	}
	place = rotate_left(place);
	return place;
}

Node * AVL::rotate_right(Node* place) 
{
	int dat = place->getData();
	Node* temp = place->getLeftChild();
	place->left = temp->getRightChild();
	temp->right = place;
	place = temp;
	if (this->getRootNode()->getData() == dat)
	{
		this->root = place;
	}
	return temp;
}

Node * AVL::rotate_left(Node*& place) 
{
	int dat = place->getData();
	Node* temp = place->getRightChild();
	place->right = temp->getLeftChild();
	temp->left = place;

	if (this->getRootNode()->getData() == dat)
	{
		this->root = temp;
	}

	return temp;
}