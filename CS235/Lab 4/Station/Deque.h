#pragma once
#include "List.h"

class Deque {
    private:
        List<int> Dequelist;
        
    public:
        Deque() {}
        ~Deque() {}
        
    void push_front(int id);
    void push_back(int id);
    void pop_front();
    void pop_back();
    int at_front();
    int at_back();
    int size();
};