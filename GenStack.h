#ifndef GENSTACK_H
#define GENSTACK_H // header guards

#include "LinkedList.h" //import files and packages
#include <iostream>
#include <exception>

using namespace std; //standard namespace

template <class T> //template class
class GenStack{ //creating a stack
public:
  GenStack();
  ~GenStack();
  //core functions
  void push(T data);
  T pop();
  //aux functions
  T peek(); // top()
  bool isEmpty();
  int getSize();

  int m_size;
  DoublyLinkedList<T> *link = new DoublyLinkedList<T>();
};

template <class T>
GenStack<T>::GenStack(){ //constructor
  m_size = 0;
}

template <class T>
GenStack<T>::~GenStack(){ //destructor
}

template <class T>
void GenStack<T>::push(T data){ //add something to the stack
  return link->insertBack(data);
}


template <class T>
T GenStack<T>::peek(){ /// peek method
  if(isEmpty()){
    throw runtime_error("stack is empty");
  }
  return link->back;
}

template <class T>
T GenStack<T>::pop(){ //remove and return top of stack
  if(isEmpty()){
    cout << "Sorry, rollback not available. You may only rollback up to 5 times. You have exceeded this number or have undone all possible changes made and have no more rollbacks available at this time." << endl;
  }else{
    return link->removeBack();
  }
}

template <class T>
bool GenStack<T>::isEmpty(){ //check if stack is empty
  return link->isEmpty();
}

template <class T>
int GenStack<T>::getSize(){ // get the size of the stack
  return link->getSize();
}

#endif
