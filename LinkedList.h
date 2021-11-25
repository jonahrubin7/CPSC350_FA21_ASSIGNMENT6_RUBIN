#ifndef DLINKEDLIST_H //header guards
#define DLINKEDLIST_H

#include <iostream>  //import packages
#include <exception>
using namespace std;

template <class T> //template class
class ListNode{ //create node for double linked list
public:
  ListNode();
  ListNode(T d);
  ~ListNode();
  ListNode *next;
  ListNode *prev;
  T data;
};

template <class T>
ListNode<T>::ListNode(){} //constructor

template <class T>
ListNode<T>::ListNode(T d){ //overloaded
  data = d;
  next = NULL;
  prev = NULL;
}

template <class T>
ListNode<T>::~ListNode(){ //destructor
  delete next;
  delete prev;
}

template <class T>
class DoublyLinkedList{ //linked list class
private:
  ListNode<T> *front;
  ListNode<T> *back;
  int size;
public:
  DoublyLinkedList();
  ~DoublyLinkedList();

  void insertFront(T d); //create all the methods you are going to use
  void insertBack(T d);
  T accessAtPos(int pos);
  T removeFront();
  T removeBack();
  T removeNode(T value);
  T find(T value);
  bool isEmpty();
  int getSize();
  T getFront();
};

template <class T>
DoublyLinkedList<T>::DoublyLinkedList(){ //constructor
  front = NULL;
  back = NULL;
  size = 0;
}

template <class T>
DoublyLinkedList<T>::~DoublyLinkedList(){ //destructor
  delete front;
  delete back;
}

template <class T>
void DoublyLinkedList<T>::insertFront(T d){ //insert front method
  ListNode<T> *node = new ListNode<T>(d);

  if(isEmpty()){
    back = node;
  }else{
    node->next = front;
    front->prev = node;
  }
  front = node;
  ++size;
}

template <class T>
void DoublyLinkedList<T>::insertBack(T d){ //insert node in the back method
  ListNode<T> *node = new ListNode<T>(d);

  if(isEmpty()){
    front = node;
  }else{
    node->prev = back;
    back->next = node;
  }
  back = node;
  ++size;
}

template <class T>
T DoublyLinkedList<T>::accessAtPos(int pos){
  int position = -1;
  ListNode<T> *curr = front;
  while(curr != NULL){
    ++position;
    if(position == pos){
      return curr->data;
    }
    curr = curr->next;
  }
  if(curr == NULL){
    return NULL;
  }
}

template <class T>
bool DoublyLinkedList<T>::isEmpty(){ //check if linked list is empty method
  return(size == 0);
}

template <class T>
int DoublyLinkedList<T>::getSize(){ //returns size of the list
  return size;
}

template <class T>
T DoublyLinkedList<T>::removeFront(){ //removes the front node
  if(isEmpty()){
    throw runtime_error("list is empty");
    exit(1);
  }

  ListNode<T> *temp = front;

  if(front->next == NULL){
    back = NULL;
  }else{
    //more than one node in list
    front->next->prev = NULL;
  }
  front = front->next;
  temp->next = NULL;
  temp->prev = NULL;
  T data = temp->data;
  --size;
  delete temp;
  return data;
}

template <class T>
T DoublyLinkedList<T>::removeBack(){ //removes back node
  if(isEmpty()){
    throw runtime_error("list is empty");
  }

  ListNode<T> *temp = back;
  if(back->prev == NULL){
    front = NULL;
  }else{
    back ->prev->next = NULL;
  }
  back = back ->prev;
  temp->prev = NULL;
  T data = temp->data;
  --size;
  delete temp;
  return data;
}

template <class T>
T DoublyLinkedList<T>::find(T value){ //finds a specific value in the list.
  int position = -1;
  ListNode<T> *curr = front;
  while(curr != NULL){
    ++position;
    if(curr ->data == value){
      break;
    }
    curr = curr->next;
  }
  if(curr == NULL){
    position = -1;
  }
}

template <class T>
T DoublyLinkedList<T>::removeNode(T value){ //remove specific node method
  if(isEmpty()){
    throw runtime_error("list is empty");
  }
  ListNode<T> *curr = front;
  while(curr->data != value){
    curr = curr -> next;

    if(curr == NULL){
      return -1;
    }
  }
  if(curr != front && curr != back){
    curr->prev->next = curr->next;
    curr->next->prev = curr->prev;
  }

  if(curr == front){
    front = curr->next;
    front -> prev = NULL;
  }
  if(curr == back){
    back = curr ->prev;
    back -> next = NULL;
  }

  curr->next = NULL;
  curr->prev = NULL;
  T data = curr->data;
  --size;
  delete curr;
  return data;
}

template <class T>
T DoublyLinkedList<T>::getFront(){
  T temp = front->data;
  return temp;
}

#endif
