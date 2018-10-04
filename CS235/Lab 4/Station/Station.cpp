#include "Station.h"
#include <string>
#include <ctype.h>


bool Station::addToStation(int car)
{
    if (car <= 0) 
    {
        cout << "ID can't be a negative number." << endl;
        return false;
    }
    if (turntable == -1) 
    {
        if (!inventory.duplicate(car))
        {
            turntable = car;
            return true;
        }
        else
        {
            cout << "Car ID already exists.\n";
            return false;
        }
    }
    else {
        cout << "Turntable is currently full, please empty turntable first." << endl;
        return false;
    }
}

int Station::showCurrentCar()
{
    return turntable;
}

bool Station::removeFromStation()
{
    if (turntable != -1) 
    {
        turntable = -1;
        return true;
    }
    else
    {
        cout << "Station already empty\n";
        return false;
    }
}

bool Station::addToStack()
{
    if (mystack.size() < 5) {
        if (turntable != -1) {
            mystack.push(turntable);
            inventory.insertHead(turntable);
            turntable = -1;
            return true;
        }
        else
        {
            cout << "Turntable empty try again.\n";
            return false;
        }
    }
    else
    {
        cout << "Stack is full. Try another container.\n";
        return false;
    }
}

bool Station::removeFromStack()
{
    if (turntable == -1)
    {
        if(mystack.size() > 0)
        {
            cout << "Removing from stack: "<< mystack.top()<<endl;
            turntable = mystack.top();
            mystack.pop();
            return true;
        }
        else
        {
            cout << "Stack is empty\n";
            return false;
        }
    }
    else
    {
        cout << "Turntable full, try again\n";
        return false;
    }
}

int Station::showTopOfStack()
{
    //cout << "showTopOfStack "<<mystack.top()<<endl;
    return(mystack.top());
}

int Station::showSizeOfStack()
{
    return(mystack.size());
}

bool Station::addToQueue()
{
    if (myqueue.size() < 5) 
    {
        if (turntable != -1)
        {
            myqueue.push(turntable);
            inventory.insertHead(turntable);
            turntable = -1;
            return true;
        }
        else return false;
    }
    else 
    {
        cout << "Queue is full, try another container\n";
        return false;
    }
}

bool Station::removeFromQueue()
{
    //cout << "removeFromQueue "<<endl;
    if (turntable == -1)
    {
        if(myqueue.size() > 0)
        {
            cout << "Removing from queue: "<<myqueue.top()<<endl;
            turntable = myqueue.top();
            myqueue.pop();
            return true;
        }
        else return false;
    }
    else return false;

}

int Station::showTopOfQueue()
{
    //cout << "showTopOfQueue "<<endl;
    return(myqueue.top());
}

int Station::showSizeOfQueue()
{
    //cout << "showSizeOfQueue "<<endl;
    return(myqueue.size());
}

bool Station::addToDequeLeft()
{
    //cout << "addToDequeLeft "<<endl;
    if (mydeque.size() < 5) 
    {
        if (turntable != -1)
        {
            mydeque.push_front(turntable);
            inventory.insertHead(turntable);
            turntable = -1;
            return true;
        }
        else return false;
    }
    else
    {
        cout << "Deque full, try another container\n";
        return false;
    }
}

bool Station::addToDequeRight()
{
    //cout << "addToDequeRight "<<endl;
    if (mydeque.size() < 5) 
    {
        if (turntable != -1)
        {
            mydeque.push_back(turntable);
            inventory.insertHead(turntable);
            turntable = -1;
            return true;
        }
        else return false;
    }
    else
    {
        cout << "Deque full, try another container\n";
        return false;
    }
}

bool Station::removeFromDequeLeft()
{
    //cout << "removeFromDequeLeft "<<endl;
    if (turntable == -1)
    {
        if (mydeque.size() > 0)
        {
            cout << "Removing from Deque left: " << endl;
            turntable = mydeque.at_front();
            mydeque.pop_front();
            return true;
        }
        else return false;
    }
    else return false;
}

bool Station::removeFromDequeRight()
{
   // cout << "removeFromDequeRight "<<endl;
   if (turntable == -1) 
   {
       if (mydeque.size() > 0)
       {
            cout << "Removing from Deque right: " << endl;
            turntable = mydeque.at_back();
            mydeque.pop_back();
            return true;
       }
       else return false;
   }
   else return false;
}

int Station::showTopOfDequeLeft()
{
    //cout << "showTopOfDequeLeft"<<endl;
    return(mydeque.at_front());
}

int Station::showTopOfDequeRight()
{
   //cout <<"showTopOfDequeRight"<<endl;
   return(mydeque.at_back());
}

int Station::showSizeOfDeque()
{
    return(mydeque.size());
}

void Station::removecar()
{
    string toremove = "";
    cout << "What car ID do you want to remove? ";
    cin >> toremove;
    if (isdigit(toremove[0])){
        int digitID = stoi(toremove);
        if (inventory.duplicate(digitID))
        {
            if (digitID == mystack.top()){
                removeFromStack();
            }
            else if (digitID == myqueue.top()){
                removeFromQueue();
            }
            else if (digitID == mydeque.at_front()){
                removeFromDequeLeft();
            }
            else if (digitID == mydeque.at_back()){
                removeFromDequeRight();
            }
            else {
                cout << "Car not accessible!\n";
            }
        }
        else {
            cout << "Car not found\n";
        }
    }
    else {
        cout << "Not a positive integer\n";
    }
}