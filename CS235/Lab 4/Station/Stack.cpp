#include "Stack.h"

void Stack::push(int id){
  cout << "Car added to stack" << endl;
  Stacklist.insertHead(id);
}

void Stack::pop() {
  int first = 0;
  int toremove = Stacklist.at(first);
  Stacklist.remove(toremove);
}

int Stack::top() {
  if (Stacklist.size() > 0) 
  {
    int first = 0;
    return Stacklist.at(first);
  }
  else return -1;
}

int Stack::size() {
  return Stacklist.size();
}