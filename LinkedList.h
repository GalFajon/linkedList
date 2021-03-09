#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include<string>

template<class T>

class LinkedList{
private:

struct element {
T value; 
element *next; 
element *prev;
};

//konec, začetek
element *start=0;

public:
LinkedList();
void push(T newelement); //adds an element
void pop(); //deletes the most recent element
void pop(T element_to_pop); //deletes an element based on it's contents
bool checkforvalue(T value_to_check); //checks if a value inside the list actually exists
int length(); //describes length
T find(int index); //finds an element based on index
T call(); //returns the value of the most recent element
T call(T value); //returns a value based on the searched value, mainly intended for error checking
};

#endif // LINKEDLIST_H
