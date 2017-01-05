#include "BallenDevLinkedList.h"

LinkedList::LinkedList()
{
  head = NULL;
  dblHead = &head;
  inOrder = false;
}

void LinkedList::add(int data)
{
  bool isDuplicate = false;
	
  //Start at the head of the list
  Node* currentNode = head;
	
  //Prime the node to insert
  Node* nodeToInsert = new Node;	
  nodeToInsert->data = data;
  nodeToInsert->next = NULL;
  
  //Determine if the head is pointing to anything
  if(!head)			
    head = nodeToInsert;			
  else
	{
	  //Traverse to the end of the list
	  while(currentNode->next)
		{
		  if(data == currentNode->data)
			isDuplicate = true;
		  
		  currentNode = currentNode->next;
		}			
	  
	  //Add the node to the list only if it is not duplicate data
	  if(!isDuplicate)
		{
		  currentNode->next = nodeToInsert;
				
		  //No longer in order if appended to end of list
		  inOrder = false;
		}			
		  else
		{
		  delete nodeToInsert;
		  std::cout << "ERROR: Duplicate data is not permitted.\n";
		}
	}
}

/*Error when having to insert new node at the beginning of the list (when there is at least one node already in the list*/
void LinkedList::insert(int data)
{
  //Determine if an insertion location is possible (prevents duplicates)
  bool isDuplicate = false;	
	
  //Create a currentNode to traverse the list
  Node* currentNode = NULL;
	
  //Create a previousNode to prevent a broken list when inserting
  Node* previousNode = NULL;
	
  //Create a new node to be inserted
  Node* nodeToInsert = new Node;
  nodeToInsert->data = data;
  nodeToInsert->next = NULL;
	
  //If head is null then insert the node at the beginning of the list
  if(!head)
    {
      head = nodeToInsert;
      inOrder = true;
    }
  //Otherwise determine where the node should be inserted by following an ascending order scheme
  else if(inOrder)
  {
      //Start at the head of the list
      currentNode = head;
      
      while(currentNode && data >= currentNode->data)
		{	
		  if(data == currentNode->data)
			 isDuplicate = true;
		  
		  previousNode = currentNode;
		  currentNode = currentNode->next;
		}	
		
      //Determine if the node to be inserted is to be inserted at the beginning of the list
      if(!isDuplicate)
		{
		  if(!previousNode)
		  {
			head = nodeToInsert;
			nodeToInsert->next = currentNode;
		  }
		  //Otherwise insert the node in another part of the list
		  else
		  {				
				previousNode->next = nodeToInsert;	
				nodeToInsert->next = currentNode;
		  }	
		}
      else
		{
		  delete nodeToInsert;
		  std::cout << "ERROR: Duplicate data is not permitted.\n";
		}
  }
  else  
	std::cout << "ERROR: List must be in order before inserting a node.\n";
  
}

/*Inserts a node into the list through the use of a double pointer*/
void LinkedList::insertDbl(int data)
{
  Node** specialNode = &head;
  
  Node* nodeToInsert = new Node;
  nodeToInsert->data = data;
  nodeToInsert->next = NULL;
  
  //Check if there are any nodes in the list
  if(head)
  {
	  while(*specialNode && data >= (*specialNode)->data)
	  {
		  
	  }
  }
  else
	  std::cout << "ERROR: No nodes in the list.\n\n";
}

void LinkedList::insertionSort()
{
	//Create a temp head to hold the place of the current head
	Node* tempHead = NULL;	
	Node* currentNode = NULL;
	Node* tempNode = NULL;
	
	if(head)
	{
		//No need to try to sort if the list is already in order
		if(!inOrder)
		{	
			tempHead = head;
			head = NULL;
			currentNode = tempHead;
			
			//Make in order to enable use of the insert method
			inOrder = true;
			
			//Traverse the list and insert each node into a newly created list while deleting the old list one node at a time
			while(currentNode)
			{
				insert(currentNode->data);
				
				tempNode = currentNode->next;
				delete currentNode;
				currentNode = tempNode;			
			}
			
			std::cout << "Successfully sorted the list using the insertion sort method.\n\n";
		}
		else
			std::cout << "List already in order.\n\n";
	}
	else
		std::cout << "No nodes in the list to sort.\n\n";
}

LinkedList::Node* LinkedList::getHead()
{
  return head;
}

void LinkedList::display()
{
  Node* currentNode = head; 
	
  //Process if head is not null
  if(head)
    {
    while(currentNode)
    {			
    std::cout << currentNode->data << "\t";			
    
    currentNode = currentNode->next;
    }
    
    std::cout << "\n\n";
    }
    else
    std::cout << "List is empty!\n\n";
}

void LinkedList::displayDbl()
{
  dblHead = &head;
  Node** specialNode = dblHead;
  
  if(*dblHead)
  {
      while(*specialNode)
      {	 
		  std::cout << (*specialNode)->data << "\t";

		  //Set the specialNode equal to the reference of the memory address of the next pointer (store the memory address of the next node pointer)
		  specialNode = &((*specialNode)->next);
      }

      std::cout << "\n\n";
  }
  else  
      std::cout << "List is empty!\n\n";
  
}

void LinkedList::displayVerbose()
{
  Node* currentNode = head;
  
  //Process if head is not null
  if(head)
  {
		while(currentNode)
		{
		  std::cout << "\nAddress: " << currentNode << "\n";
		  std::cout << "Data: " << currentNode->data << "\n";
		  std::cout << "Pointing To: " << currentNode->next << "\n";			
		  
		  currentNode = currentNode->next;
		}
  }
  else
    std::cout << "List is empty!\n\n";
}

/*Deletes a node using the standard method approach*/
void LinkedList:: deleteNode(int data)
{	
	Node* currentNode = head;
	Node* prevNode = currentNode;
	
	//Determine if the head is pointing to a node (if there are nodes in the list or not)
	if(head)
	{
		//Determine if the head is the node to delete
		if(head->data == data)
		{	
			currentNode = head->next;			
			delete head;
			head = currentNode;
		}
		//Otherwise, traverse the list to find the node to delete
		else
		{
			while(currentNode && currentNode->data != data)
			{
				prevNode = currentNode;
				currentNode = currentNode->next;
			}
			
			if(currentNode)
			{
				prevNode->next = currentNode->next;
				delete currentNode;
				
				std::cout << "Deleted node with " << data << " as it's data.\n\n";
			}
			else
				std::cout << "ERROR: Unable to find the node with " << data << " as it's data.\n\n";
		}	
	}
	else
		std::cout << "ERROR: No nodes in the list to delete.\n\n";
}

/*Deletes a node by using a double pointer*/
void LinkedList:: deleteNodeDbl(int data)
{
	Node** specialNode = dblHead;
	Node* nodeToDelete = NULL;
	
	while(*specialNode && (*specialNode)->data != data)		
		specialNode = &((*specialNode)->next);
	
	if(*specialNode)
	{
		nodeToDelete = *specialNode;
		*specialNode = nodeToDelete->next;
		nodeToDelete->next = NULL;		
	}
	else
		std::cout << "ERROR: Unable to find the node with " << data << " as it's data.\n\n";
}

LinkedList::~LinkedList()
{
  //Start at the head
  Node* currentNode = head;
  Node* tempNode = NULL;
  
  int numNodes = 0;
  
  //Traverse the list and delete each node
  while(currentNode)
    {
      //Delete each node through the use of a temp node ptr
      tempNode = currentNode->next;
      
      delete currentNode;
      std::cout << "Node " << ++numNodes << " deleted\n";
      
      currentNode = tempNode;
    }
  
  std::cout << "Memory released.\n";
}
