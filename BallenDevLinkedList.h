#ifndef BALLENDEVLINKEDLIST_H_
#define BALLENDEVLINKEDLIST_H_

/*GOAL: To traverse a linked list using a double pointer.*/

#include <iostream>

class LinkedList
{
private:
  struct Node
  {
    int data;
    Node* next;
  };
  
  Node* head;
  Node** dblHead;
  
  bool inOrder;

public:
  LinkedList();
  
  Node* getHead();
  
  void add(int data);
  
  void insert(int data);

  void insertDbl(int data);
  
  void insertionSort();
  
  void display();

  void displayDbl();
  
  void displayVerbose();

  void deleteNode(int data);

  void deleteNodeDbl(int data);  
  
  ~LinkedList();
};

#endif /*BALLENDEVLINKEDLIST_H_*/
