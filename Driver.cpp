#include <iostream>

#include "BallenDevLinkedList.h"

using namespace std;

/* int data1 = 21;
   int data2 = 56;
	
   int* previous = &data1;
   int* next = &data2;	
   
   //Can a double pointer point to more than one thing at a time??
   int** doublePtr = &previous;	
   *doublePtr = next;
   
   cout << "previous is located at: " << &previous << endl;
   cout << "next is located at: " << &next << "\n\n";
	
   cout << "previous is pointing to: " << previous << endl;
   cout << "next is pointing to: " << next << "\n\n";
	
   cout << "doublePtr is pointing to: " << doublePtr << endl;
   cout << "doublePtr is also pointing to: " << *doublePtr << "\n\n"; 
*/

enum Choices
{
	ADD_NODE = 1, 
	INSERTION_SORT, 
	INSERT_NODE, 
	DISPLAY_NORMAL, 
	DISPLAY_VERBOSE, 
	DISPLAY_P2P, 
	DELETE_NODE,
	DELETE_NODE_DBL,
	EXIT
};

void mainMenu();
void displayMenu(LinkedList& list);
void renderChoice(int choice, LinkedList& list);

int main(int argc, char** argv)
{	
  LinkedList testList;
	
  int choice = 0; 
  
  do
  {
	  do
	  {
		  mainMenu();
		  cin >> choice;
		  
		  if(choice <= 0 || choice > EXIT)
			  cout << "\nERROR: Invalid menu option.\n\n";
		  else
			  renderChoice(choice, testList);
	  }
	  while(choice  > 0 && choice < EXIT);
	  
	  if(choice == EXIT)
		  cout << "\nExiting...\n\n";
  }
  while(choice != EXIT);
	
  return 0;
}

void mainMenu()
{
	cout << "\n****************BallenDevLinkedList****************\n";
	cout << ADD_NODE << " - Add Node\n";
	cout << INSERTION_SORT << " - Insertion Sort\n";
	cout << INSERT_NODE << " - Insert Node\n";
	cout << DISPLAY_NORMAL << " - Display List (Normal)\n";
	cout << DISPLAY_VERBOSE << " - Display List (Verbose)\n";
	cout << DISPLAY_P2P << " - Display List (P2P)\n";
	cout << DELETE_NODE << " - Delete Node (Normal)\n";
	cout << DELETE_NODE_DBL << " - Delete Node (P2P)\n";
	cout << EXIT << " - Exit\n\n";	
	
	cout << "Enter Choice: ";
}

void renderChoice(int choice, LinkedList& list)
{
	int input = 0;
	
	switch(choice)
	{
		case ADD_NODE:
			cout << "\nEnter data to add to list: ";
			cin >> input;
			
			list.add(input);
			
			break;
			
		case INSERTION_SORT:
			cout << "Sorting...\n";
			list.insertionSort();
			break;
			
		case INSERT_NODE:
			cout << "\nEnter data to insert into the list: ";
			cin >> input;
			
			list.insert(input);
		
			break;
			
		case DISPLAY_NORMAL:
			cout << "\nYour list: ";
			list.display();
			break;
			
		case DISPLAY_VERBOSE:
			cout << "\nYour list: \n";
			list.displayVerbose();
			break;
			
		case DISPLAY_P2P:
			cout << "\nYour list: ";
			list.displayDbl();
			break;
			
		case DELETE_NODE:
			cout << "\nEnter data of the node to be deleted: ";
			cin >> input;
			
			list.deleteNode(input);
			
			break;
			
		case DELETE_NODE_DBL:
			cout << "\nEnter data of the node to be deleted: ";
			cin >> input;
			
			list.deleteNodeDbl(input);
			
			break;
			
		default:
			break;
	}
}