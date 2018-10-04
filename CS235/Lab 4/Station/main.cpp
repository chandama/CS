#include "Station.h"
int main()
{
    Station mystation;
    int carID;
    int choice_num = 0;
    string choices[] = {
        "1. Add a car to the station",
        "2. Remove a car from the station",
        "3. Add a car from the station to a storage facility",
        "4. Remove a car from a storage facility and add it to the station",
        "5. Display the cars currently accessible in the station and storage facilities",
        "6. Quit"
    };
    const int NUM_CHOICES = 6;
    
    string storage[4] = {
        "1. Add a car to the stack",
        "2. Add a car to the queue",
        "3. Add a car to the dequeue left",
        "4. Add a car to the dequeue right"
    };
    /*string outstorage[4] = {
        "1. Remove a car from the stack",
        "2. Remove a car from the queue",
        "3. Remove a car from the dequeue left",
        "4. Remove a car from the dequeue right"
    };*/
    const int NUM_STORAGE = 4;
  // Perform all operations selected by user.
  while (choice_num < NUM_CHOICES) {
    // Select the next operation.
    cout << "Select an operation on the station\n";
    for (int i = 0; i < NUM_CHOICES; i++) {
      cout << choices[i] << endl;
    }
    cin >> choice_num;
    switch (choice_num) {
        case 1:
            cout << "Enter the ID of the car\n";
            cin >> carID;
            if(mystation.addToStation(carID)) {
              cout << "addToStation was successful"<<endl;
            };
            break;
        case 2:
            if(mystation.removeFromStation()) {
              cout << "removeFromStation was successful"<<endl;
            };
            break;
        case 3:
            // Add a car from the station to a storage facility
             
            int storage_num;
            
            for (int i = 0; i < NUM_STORAGE; i++) {
                cout << storage[i] << endl;
            }
            
            cin >> storage_num;
            
            switch(storage_num) {
                case 1:
                    mystation.addToStack();
                    break;
                case 2:
                    mystation.addToQueue();
                    break;
                case 3:
                    mystation.addToDequeLeft();
                    break;
                case 4:
                    mystation.addToDequeRight();
                    break;
                default:
                    break;
            }
            
            break;
                    // Add a car from the station to a storage facility
        case 4:    
            mystation.removecar();
        case 5:
            cout << "Station: "<< mystation.showCurrentCar() << endl;
            cout << "Stack: " << mystation.showTopOfStack() << endl;
            cout << "Queue: " << mystation.showTopOfQueue() << endl;
            cout << "Deque: " << mystation.showTopOfDequeLeft()
                << ", " << mystation.showTopOfDequeRight() << endl;
           // mystation.showTopOfStack();
            break;
        case 6:
          cout << "CHOO CHOO CIAO!!!!\n";
          cout << "o        o      o    o   o   o   oo  oo  oo  oo}\n";
          cout << "o     o  oo  ooo  oo  ooo ooo  ooo ooo ooo oooooo}\n";
          cout << "             oo  oo   oo  oo  ooo ooo ooo oooo ooooo}\n";
          cout << "                   o    o   o   oo  oo  oo  oooo oooooo}\n";
          cout << "                                  o   o   o   ooo  oo ooooo}\n";
          cout << "                                                       o ooo}\n";
          cout << "                          _________            \\|/         ++\n";
          cout << "              ___________ |_______|______/-\\___|-|_^_/-\\___||_n\n";
          cout << "       n_____/    OOO    \\_ |[][] |----------------------|----|\\\n";
          cout << "       |          (_)      ||     |______________________|_|| ||P\n";
          cout << "       |          ZOO      | -----/====+______|| _---====--||- /\n";
          cout << "      q|===================|_|=_/o====+|=====[__]o====+|==[__]-p\n";
          cout << "_______________(_)(_)______(_)(_)_____\\__/_\\__/_\\__/__\\__/_\\__/_(_)____\n";
          cout << "____\n";
            return(0);
        default:
            cout << "Invalid selection\n";
            break;
    } // End switch
  } // End while.
  return(0);
}