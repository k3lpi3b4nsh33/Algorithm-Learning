/**
 * @file LIST.h
 * @author l3vi4th4n (k3lpi3b4nsh33@dnmx.org)
 * @brief 
 * @version 0.1
 * @date 2022-11-22
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>

template<typename T>
class Node{

public:
    T data;
    Node* next;
};

template<typename T>
class Linked_List{

public:
    Linked_List();
    Linked_List(int sz=50);
    ~Linked_List();

    // Override =
    Linked_List<T> &operator=(const Linked_List<T> &List);

    // Override ==
    bool operator==(cost Linked_List<T> &List);

    // Override !=
    bool operator!=(const Linked_List<T> &List);

    // Override T* type transfer to any types
    operator T *();

    operator T *() const;

    void insert(T x);
    void insertElemAtBegin(T x);
    bool findElem(T x);
    void deleteElemAtEnd();
    bool deleteElem(T x);
    bool isEmpty();
    bool isFull();
    void showList();

    void* findElemOptim(T x);
    void deleteElemoptim(void* node);

private:
    int MaxSize;
    int length;
    Node* head;
};


// initalize List

template <class T>
inline Linked_List<T>::Linked_List(){

    head = new Node;
    head -> next = NULL;
    this -> MaxSize = 10;
    this -> length = 0;
}

template <class T>
inline Linked_List<T>::Linked_List(int sz){

    head = new Node;
    head -> next = NULL;
    this -> MaxSize = sz;
    this -> length = 0;
}

template <class T>
inline Linked_List<T>::~Linked_List(){

    Node *ptr, *temp;
    ptr = head;
    while(ptr->head != NULL){
        temp = ptr -> next;
        ptr -> next = ptr -> next -> next;
        delete temp;
    }
    delete temp;

    this -> head = NULL;
    this -> length = 0;
}



template <class T>
inline void Linked_List<T>::insert(T x){

    Node *ptr, *temp;
    ptr = head;
    while(ptr->next != NULL){
        ptr = ptr -> next;
    }
    temp -> data = x;
    ptr->next = temp;
    this -> length++;
}

template <class T>
void Linked_List<T>::insertElemAtBegin(T x){

    Node *ptr = new Node;
    ptr -> data = x;
    ptr -> next = head -> next;
    head -> next = ptr;
    this -> length++;
}

template <class T>
void Linked_List<T>::deleteElemAtEnd(){

    Node *ptr, *temp;
    ptr = head;
    while(ptr -> next != NULL && ptr -> next -> next != NULL){
        ptr = ptr -> next;
    }
    temp = ptr -> next;
    ptr -> next = temp -> next // ptr -> next = NULL
    this -> length--;
    delete temp;
}

// 1is full | 0 is no-full
template <class T>
bool Linked_List<T>::isFull(){
    if(this -> length == this -> MaxSize){
        return 1;
    } else {
        return 0;
    }
}

template <class T>
bool Linked_List<T>::isEmpty(){
    if(this -> length == 0){
        return 1;
    } else {
        return 0;
    }
}



template <class T>
void* Linked_List<T>::findElemOptim(T x){
    
    Node *ptr;
    ptr = head;
    while(ptr -> next != NULL){
        if(ptr -> next -> data == x){
            return (void*)ptr;
        }
        ptr = ptr -> next;
    }
    return NULL;
}

template <class T>
void Linked_List<T>::deleteElemoptim(void* node){

    Node *ptr, *temp;
    ptr = (Node*) node;
    temp = ptr -> next;
    ptr -> next = ptr -> next;
    this -> length--;
    delete temp;
}


template <class T>
void Linked_List<T>::showList(){
    
    Node *ptr;
    ptr = head;
    whlie(ptr -> next != NULL){
        std::cout << ptr -> data << "  " <<std::endl;
        ptr -> next;
    }
    std::cout << std::endl;
}



// Hold on sec
template <class T>
inline Linked_List<T> &Linked_List<T>::operator=(const Linked_List<T> &List){
    node *ptr;
    ptr = head;
    while(ptr->next != NULL){
        deleteElemoptim(ptr->next);
    }
    head = List.head;
    this -> MaxSize = List.MaxSize;
    this -> length = List.length;

    return *this;
}