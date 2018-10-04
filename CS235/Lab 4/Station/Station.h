#include "StationInterface.h"
#include "Stack.h"
#include "Queue.h"
#include "Deque.h"
#include "List.h"
using namespace std;

class Station : public StationInterface
{
	protected:
	int turntable;
	List<int> inventory;
	Stack mystack;
	Queue myqueue;
	Deque mydeque;

	public:
		Station(){
			turntable = -1;
		}
		 ~Station(){}

		virtual bool addToStation(int car);
		
		virtual int showCurrentCar();
		
		virtual bool removeFromStation();
		
		virtual bool addToStack();
		
		virtual bool removeFromStack();
		
		virtual int showTopOfStack();
		
		virtual int showSizeOfStack();
		
		virtual bool addToQueue();
		
		virtual bool removeFromQueue();
		
		virtual int showTopOfQueue();
		
		virtual int showSizeOfQueue();
		
		virtual bool addToDequeLeft();
		
		virtual bool addToDequeRight();
		
		virtual bool removeFromDequeLeft();
		
		virtual bool removeFromDequeRight();
		
		virtual int showTopOfDequeLeft();
		
		virtual int showTopOfDequeRight();
		
		virtual int showSizeOfDeque();
		
		virtual void removecar();
		 
};
