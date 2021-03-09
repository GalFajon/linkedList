#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include<string>

template<class T>

class LinkedList{
private:
//osnovni element
struct element {
T value; //vrednost
element *next; //pointer na naslednjo vrednost |ni copy paste, samo internacionalna koda :P
element *prev;
};

//konec, začetek
element *start=0;

public:
LinkedList();
void push(T newelement); //doda element
void pop(); //zbriše najbolj nedavni element | just in case
void pop(T element_to_pop); //zbriše element glede na vsebino
bool checkforvalue(T value_to_check); //pogleda če vrednost dejansko obstaja
//void pop(int index);
int length();
T find(int index); //najde element po vrstnem redu glede na indeks | just in case
T call(); //vrne vrednost najbolj nedavnega elementa, getter uglavnem ampak call zveni bl vojašk
T call(T value); //vrne vrednost glede na iskano vsebino, večinoma za error checking
void save(std::string pot);
void load(std::string pot);
};

#endif // LINKEDLIST_H
