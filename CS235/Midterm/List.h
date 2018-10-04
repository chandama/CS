
#pragma once
#include "LinkedListInterface.h"
#include <iostream>
#include <stdexcept>
#include <sstream>
using namespace std;

class List : public LinkedListInterface
{
    private:
    
    struct Node { 
        string type;
        int card_number;
        Node* next;
        Node* prev;
        Node(int card_number, string type){
            this->card_number = card_number;
            this->type = type;
            next = NULL;
            prev = NULL;
        }

    };
    
    
    Node* head;


    public:
    
    List() {
        head = NULL;
        int num_items = 0;
    };
    ~List() {
        clear();
    };
    
    void insertHead(int value, string card){
        //Check for duplicate, if returns true then exit the function.
        /*if (duplicate(value, card)) {
            return;
        }*/
        Node* ptr = new Node(value, card);
        if (head == NULL) {
            num_items = 0;
            head = ptr;
            ptr->next = NULL;
            ptr->prev = NULL;
           // cout << head->type << " " << head->card_number << " ";
        }
        else {
            //if list is not empty set ptr->next to the head to insert in front
            ptr->next = head;
            ptr->prev = NULL;
            head->prev = ptr;
            head = ptr;
           // cout << head->type << " " << head->card_number << " ";           
        }
        num_items++;
        cout << num_items;
    };
    
    void insertTail(int value, string card){
        /*if (duplicate(value, card)) {
            return;
        }*/
        Node* ptr = new Node(value, card);
        Node* temp = head;
        if (head == NULL) {
            head = ptr;
            ptr->next = NULL;
        }
        else {
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = ptr;
            ptr->next = NULL; //ALready in constructor so this isn't needed
        }
        num_items++;
    };
    
    void insertAfter(int value, int insertionNode, string card){ //FIXME convert insertionNode to int
        /*if (duplicate(value, card)) {
            return;
        }
        if (duplicate(insertionNode, card) == false) {
            return;
        }*/
        Node* current = head;
        while (current != NULL) {
            if (current->card_number == insertionNode) {
                Node* ptr = new Node(value, card);
                ptr->next = current->next;
                current->next = ptr;
            }
            current = current->next;
        }
        num_items++;
    };
    
    void remove(int value){
        //This duplicate check we want to return true so stay in if loop.

        Node* current = head;
        Node* previous = head;
        //Get current pointer to the correct value and the prev ptr behind it
        while (current->card_number != value) {
            previous = current;
            current = current->next;
        }
        //If current is head, delete
        if (current == head) {
            head = current->next;
            delete current;
            num_items--;
            if (num_items == 0) {
                head = NULL;
            }
        }
        else {
            previous->next = current->next;
            delete current;
            num_items--;
        }


    };
    
    void clear(){
        //Move head ptr to next node before deleting current
        while (head != NULL) {
            Node* current = head;
            head = head->next;
            delete current;
        }
        num_items = 0;
    };
    
    int int_at(int index){
        //Check for out of range, then loop through list with an iterator and 
        //return the value when index == iterator.
        Node* ptr = head;
        int i = 0;
        cout << num_items;
        if (index < 0 || index > (num_items - 1)) {
            throw std::out_of_range("At error");
        }
        else {
            while (i < index) {
                ptr = ptr->next;
                i++;
            }
            return ptr->card_number;
        }
    };
    
    string st_at(int index){
        //Check for out of range, then loop through list with an iterator and 
        //return the value when index == iterator.
        Node* ptr = head;
        int i = 0;
        if (index < 0 || index > (num_items - 1)) {
            throw std::out_of_range("At error");
        }
        else {
            while (i < index) {
                ptr = ptr->next;
                i++;
            }
            return ptr->type;
        }
    };
    
    int size() {
        return(num_items);
    };
    
    string toString(){
        //Put everything in a string
        //Create a stringstrem and add everything to it then return the string
		ostringstream ss;
		int i = 0;
		Node* ptr = head;
        while (i < num_items) {
            ss << ptr->type << " " << ptr->card_number << ", ";
            ptr = ptr->next;
            i++;
        }

        string str = ss.str();
        str.pop_back();
        str.pop_back();
        return str;
    };
    
    int numitems() {
        return num_items;
    }
    //Need later to check for matches
    bool duplicate(int value, string card) {
        /*Node* dup = head;
        while(dup!=NULL) {
            if (dup->card_number == value) {
                return true;
            }
            else {
                dup=dup->next;
            }
        }
        return false;*/
    };
    void shuffleList() {
        
    }
};