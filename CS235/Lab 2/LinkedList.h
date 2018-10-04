
#include "LinkedListInterface.h"
#include <iostream>
#include <stdexcept>
#include <sstream>
using namespace std;

template<class T>
class LinkedList : public LinkedListInterface<T>
{
    private:
    
    struct Node {
        T data;
        Node* next;
        Node(T data){this->data = data; next = NULL;}
    };
    
    Node* head;
    int num_items = 0;

    
    public:
    
    LinkedList() {
        head = NULL;
    };
    ~LinkedList() {
        clear();
    };
    
    void insertHead(T value){
        //Check for duplicate, if returns true then exit the function.
        if (duplicate(value)) {
            return;
        }
        Node* ptr = new Node(value);
        if (head == NULL) {
            head = ptr;
            ptr->next = NULL;
        }
        else {
            //if list is not empty set ptr->next to the had to insert in front
            ptr->next = head;
            head = ptr;
        }
        num_items++;
    };
    
    void insertTail(T value){
        if (duplicate(value)) {
            return;
        }
        Node* ptr = new Node(value);
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
    
    void insertAfter(T value, T insertionNode){ //FIXME convert insertionNode to int
        if (duplicate(value)) {
            return;
        }
        if (duplicate(insertionNode) == false) {
            return;
        }
        Node* current = head;
        while (current != NULL) {
            if (current->data == insertionNode) {
                Node* ptr = new Node(value);
                ptr->next = current->next;
                current->next = ptr;
            }
            current = current->next;
        }
        num_items++;
    };
    
    void remove(T value){
        //This duplicate check we want to return true so stay in if loop.
        if (duplicate(value)) {
            Node* current = head;
            Node* previous = head;
            //Get current pointer to the correct value and the prev ptr behind it
            while (current->data != value) {
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
                if (size() == 0) {
                    head = NULL;
                }
            }
        }
        else {
            return;
        }
    };
    
    void clear(){
        //Move head ptr to next node before deleting current
        while (head != NULL) {
            Node* current = head;
            head = head->next;
            delete current;
        }
        head = NULL;
        num_items = 0;
    };
    
    T at(int index){
        //Check for out of range, then loop through list with an iterator and 
        //return the value when index == iterator.
        Node* ptr = head;
        int i = 0;
        if (index < 0 || index > (size() - 1)) {
            throw std::out_of_range("At error");
        }
        else {
            while (i < index) {
                ptr = ptr->next;
                i++;
            }
            return ptr->data;
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
            ss << ptr->data << " ";
            ptr = ptr->next;
            i++;
        }
        return ss.str();
    };
    
    bool duplicate(T value) {
        Node* dup = head;
        while(dup!=NULL) {
            if (dup->data == value) {
                return true;
            }
            else {
                dup=dup->next;
            }
        }
        return false;
    };
    
};