#include "LinkedList.h"
#include<iostream>
#include<QString>
#include<QDate>
#include<fstream>
#include<QMessageBox>
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

/*template<class T> //POGLEJ ČE JE BOLJ ČASOVNO UČINKOVITO, REINTEGRIRAJ IN ZBRIŠI NA VREDNOST VEZANO VERZIJO
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


template <> void LinkedList<std::string>::save(std::string pot) {
    std::fstream save;
    try {
       save.open(pot,std::ios::out);
    } catch (std::ios::failure e) {
        QMessageBox warning;
        warning.setText("Napaka pri shranjevanju." + QString::fromStdString(e.what()));
        warning.exec();
        return;
    }

    int listlength = this->length();
    for (int i=0;i<listlength;i++) {
        save << this->find(i) << std::endl;
    }
    save.close();
};

template <> void LinkedList<std::string>::load(std::string pot) {
    std::fstream load;
    try {
       load.open(pot,std::ios::in);
    } catch (std::ios::failure e) {
        QMessageBox warning;
        warning.setText("Napaka pri shranjevanju." + QString::fromStdString(e.what()));
        warning.exec();
        return;
    }
    std::string temp;
    while (std::getline(load,temp)) this->push(temp);
    load.close();
}

template <> void LinkedList<QString>::save(std::string pot) {
    std::fstream save;
    try {
       save.open(pot,std::ios::out);
    } catch (std::ios::failure e) {
        QMessageBox warning;
        warning.setText("Napaka pri shranjevanju." + QString::fromStdString(e.what()));
        warning.exec();
        return;
    }
    int listlength = this->length();
    for (int i=0;i<listlength;i++) {
        save << this->find(i).toStdString() << std::endl;
    }
    save.close();
};

template <> void LinkedList<QString>::load(std::string pot) {
    std::fstream load;
    try {
       load.open(pot,std::ios::in);
    } catch (std::ios::failure e) {
        QMessageBox warning;
        warning.setText("Napaka pri shranjevanju." + QString::fromStdString(e.what()));
        warning.exec();
        return;
    }
    std::string temp;
    while (std::getline(load,temp)) {this->push(QString::fromStdString(temp));
    }
    load.close();
}


template class LinkedList<int>;
template class LinkedList<std::string>;
template class LinkedList<QString>;
template class LinkedList<QDate>;
