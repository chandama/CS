/*FIRST IN FIRST OUT*/

#pragma once
#include "List.h"

class Queue {
    private:
        List<int> Queuelist;
    
    public:
        Queue() {}
        ~Queue() {}
        
    void push(int id);
    void pop();
    int top();
    int size();
};