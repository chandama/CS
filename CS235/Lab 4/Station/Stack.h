#pragma once
#include "List.h"

class Stack {
    private:
      // Data fields
      List<int> Stacklist;
    	
  public:
    // Constructor and member functions
    Stack() {}
    ~Stack() {}
    void push(int id);
    void pop();
    int top();
    int size();
}; // End class stack

