#include "Deque.h"

void Deque::push_front(int id)
{
    Dequelist.insertHead(id);
}

void Deque::push_back(int id)
{
   Dequelist.insertTail(id);
}

void Deque::pop_front()
{
    int first = 0;
    int toremove = Dequelist.at(first);
    Dequelist.remove(toremove);
}

void Deque::pop_back()
{
    int last = (Dequelist.size() - 1);
    int toremove = Dequelist.at(last);
    Dequelist.remove(toremove);
}

int Deque::at_front()
{
    if (Dequelist.size() > 0) 
    {
        int first = 0;
        return Dequelist.at(first);
    }
    else return -1;
}

int Deque::at_back()
{
    if (Dequelist.size() > 0)
    {
        int last = (Dequelist.size() - 1);
        return Dequelist.at(last);
    }
    else return -1;
}

int Deque::size()
{
    return Dequelist.size();
}