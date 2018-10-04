//YOU MAY NOT MODIFY THIS DOCUMENT
#pragma once
#include <string>

using namespace std;

class LinkedListInterface
{

public:

	LinkedListInterface(void) {};
	virtual ~LinkedListInterface(void) {};

	virtual void insertHead(int value, string card) = 0;

	virtual void insertTail(int value, string card) = 0;

	virtual void insertAfter(int value, int insertionNode, string card) = 0;

	virtual void remove(int value) = 0;

	virtual void clear() = 0;

	virtual int int_at(int index) = 0;
	
	virtual string st_at(int index) = 0;

	virtual int size() = 0;

	virtual string toString() = 0;
	
	virtual int numitems() = 0;

};
