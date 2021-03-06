#ifndef BST_H
#define BST_H
#include <iostream>

using namespace std;

template <class T>
class TreeNode{
public:
  TreeNode(); //constructor
  TreeNode(int key, T value); // overloaded tree node
  virtual ~TreeNode(); // abstract class
  int key;
  T value;
  TreeNode<T> *left; //create pointers for left and right
  TreeNode<T> *right;
};

template <class T>
TreeNode<T>::TreeNode(){ //create tree node
  left = NULL;
  right = NULL;
  key = 0;
  value = NULL;
}

template <class T>
TreeNode<T>::TreeNode(int k, T v){ //overloaded
  left = NULL;
  right = NULL;
  key = k;
  value = v;
}

template <class T>
TreeNode<T>::~TreeNode(){
  left = NULL;
  right = NULL;
}


template <class T>
class BST{  //create bst class
public:
  BST();
  virtual ~BST();
  void insert(int key, T value); //create method that will be used
  bool contains(int key);
  T find(int key);
  bool deleteNode(int k);
  bool isEmpty();

  T*getMin();
  T*getMax();
  TreeNode<T> *getSuccessor(TreeNode<T> *d); //node we will delete
  void printNode();
  void recPrint(TreeNode<T> *node);
  TreeNode<T> *getRoot();
private:
  TreeNode<T> *root; //root node
};


template <class T>
BST<T>::BST(){ //constructor
  root = NULL;
}

template <class T>
BST<T>::~BST(){ //destructor
  //do some research
}

template <class T>
void BST<T>::recPrint(TreeNode<T> *node){ //method to print the tree
    if(node == NULL){
      return;
    }
  recPrint(node->left);
  //prints all of the info for every type person in ascending order
  T studentOrFaculty = node->value;
  cout << endl;
  studentOrFaculty.print();
  recPrint(node->right);
}

template <class T>
//this function prints the entire Tree
void BST<T>::printNode(){
  recPrint(root);
}

template <class T>
bool BST<T>::isEmpty(){ //check if node is empty
  return (root == NULL);
}

template <class T>
T* BST<T>::getMin(){ //gets the smallest node
  if(isEmpty()){
    return NULL;
  }
  TreeNode<T> *current = root;
  while(current->left != NULL){
    current = current->left;
  }
  return &(current->key);
}

template <class T>
T* BST<T>::getMax(){ //gets the biggest node
  if(isEmpty()){
    return NULL;
  }
  TreeNode<T> *current = root;
  while(current->right != NULL){
    current = current->right;
  }
  return &(current->key);
}



template <class T>
void BST<T>::insert(int key, T value){ //inserts node into tree
  TreeNode<T> *node = new TreeNode<T>(key, value);
  if(isEmpty()){
    root = node;
  }else{
    TreeNode<T> *current = root;
    TreeNode<T> *parent = NULL;

    while(true){
      parent = current;

      if(node->key < current->key){
        current = current->left;
        if(current == NULL){
          //found insertion point
          parent->left = node;
          break;
        }
      }else{
        current = current -> right;
        if(current == NULL){
          parent->right = node;
          break;
        }
      }
    }
  }
}

template <class T>
bool BST<T>::contains(int key){ //checks if key is in tree
  if(isEmpty()){
    return false;
  }

  TreeNode<T> *current = root;

  while(current->key != key){
    if(key < current ->key){
      current = current ->left;
    }else{
      current = current->right;
    }
    if(current  == NULL){
      return false;
    }
  }
  return true;
}


template <class T>
bool BST<T>::deleteNode(int k){ //deletes node from tree
  if(isEmpty()){
    return false;
  }

  TreeNode<T> *current = root;
  TreeNode<T> *parent = root;
  bool isLeft = true;

  while(current->key != k){
    parent = current;

    if(k < current->key){
      isLeft = true;
      current =current ->left;
    }else{
      isLeft = false;
      current = current->right;
    }
    if(current == NULL){
      return false;
    }
  }

  //we found the node/value, now lets proceed to delete
  // no children, node to be delated is leaf
  if(current->left == NULL && current->right == NULL){
    if(current == root){
      root = NULL;
    }
    else if(isLeft == true){
      parent->left = NULL;
    }
    else{
      parent->right = NULL;
    }
  }

  //one child
  else if(current->right == NULL){
    //node to be deleted has a left child  (no right)
    if(current == root){
      root = current -> left;
    }
    else if(isLeft){
      parent->left = current->left;
    }
    else{
      parent->right = current->left;
    }
  }
  else if(current->left == NULL){
    //node to be delete has a right child (no left)
    if(current == root){
      root = current -> right;
    }
    else if(isLeft){
      parent->left = current->right;
    }
    else{
      parent->right = current->right;
    }
  }
  else{
    //node has two children
    TreeNode<T> *successor = getSuccessor(current);

    if(current == root){
      root = successor;
    }
    else if(isLeft){
      parent->left = successor;
    }
    else{
      parent->right = successor;
    }

    successor->left = current->left;
    current->left = NULL;
    current->right = NULL;
  }
  delete current;
  return true;
}

template<class T>
TreeNode<T>* BST<T>::getSuccessor(TreeNode<T> *d){ //method that returns successor to a deleted node
  TreeNode<T> *sp = d;
  TreeNode<T> *successor = d;
  TreeNode<T> *current = d->right;

  while(current != NULL){
    sp = successor;
    successor = current;
    current = current->left;
  }
  //we found successor but we need to check if the successor is a descendant of the right child
  if(successor != d-> right){
    sp->left = successor->right;
    successor->right = d->right;
  }
  return successor;
}


template <class T>
T BST<T>::find(int key){ // returns specified node

  TreeNode<T> *current = root;

  while(current->key != key){
    if(key < current ->key){
      current = current ->left;
    }else{
      current = current->right;
    }
    if(current  == NULL){
      return current->value;
    }
  }
  return current->value;
}


template <class T>
TreeNode<T>* BST<T>::getRoot(){ //returns root node
  return root;
}


#endif
