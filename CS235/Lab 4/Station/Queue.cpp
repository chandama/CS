#include "Queue.h"

void Queue::push(int id)
{
  cout << "Car added to queue" << endl;
  Queuelist.insertHead(id);
}

void Queue::pop() 
{
  int last = (Queuelist.size() - 1);
  int toremove = Queuelist.at(last);
  Queuelist.remove(toremove);
}

int Queue::top() 
{
  if (Queuelist.size() > 0) {
    int last = (Queuelist.size() - 1);
    return Queuelist.at(last);
  }
  else return -1;
}

int Queue::size() 
{
  return Queuelist.size();
}