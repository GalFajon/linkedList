#include "LinkedList.h"

template<class T>
LinkedList<T>::LinkedList(){
    this->start = 0;
}

template<class T>
void LinkedList<T>::push(T newelement){
   element* tmp = new element;
    tmp->value  = newelement;
    tmp->prev = 0;
    tmp->next = start;
    if(start !=  0)
       start->prev = tmp ;
    start = tmp;
}

template<class T>
void LinkedList<T>::pop(){
element *tmp = start;
while(start!=0){
start=tmp->prev;
delete tmp;
}
}

template<class T>
void LinkedList<T>::pop(T element_to_pop) {
    element *tmp=start;
    if (start == 0) return;
    while(tmp!=0) {
        if (tmp->value == element_to_pop) {
            if (start->value == element_to_pop)
                start = tmp->next;

            if (tmp->next != 0)
                (tmp->next)->prev = tmp->prev;

            if (tmp->prev != 0)
                (tmp->prev)->next = tmp->next;

            delete tmp;
            return;
        }
        else return;
        tmp=tmp->next;
    };
}

//UNUSED, my project never required it.
/*template<class T>
void LinkedList<T>::pop(unsigned short index) {
    element* tmp = start;
    for (int i=0;i<index;i++){
       tmp=tmp->next;
    };
    delete tmp;
}*/

template<class T>
T LinkedList<T>::find(int index){
    element *tmp=start;
    int i=0;
while(tmp!=0 && i<index) {
 tmp=tmp->next;
 i++;
}
if (tmp != 0)
 return tmp->value;
}

template<class T>
T LinkedList<T>::call(){
element *tmp=start;
return tmp->value;
}

template<class T>
T LinkedList<T>::call(T value){
    element *tmp=start;
    while(tmp!=0) {
        if (tmp->value == value) {
        return tmp->value;
        }
        tmp=tmp->next;
    }
};

template<class T>
bool LinkedList<T>::checkforvalue(T check_for_value){
    element *tmp=start;
    while(tmp!=0) {
        if (tmp->value == check_for_value) {
        return true;
        }
        tmp=tmp->next;
    }
    return false;
};

template<class T>
int LinkedList<T>::length(){
    int i=0;
    element *tmp=start;
    while (tmp!=0) {
        i++;
        tmp=tmp->next;
    }
    return i;
}


//template class LinkedList<int>; <- add class templates here
