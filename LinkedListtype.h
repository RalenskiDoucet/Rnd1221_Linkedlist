#pragma once
#include "NodeType.h"
#include "LinkedListIterator.h"
#include <assert.h>
#include <iostream>

template<class Type>
class LinkListType
{
protected:
	int count;
	NodeType<Type> *first;
	NodeType<Type> *last;
public:
	//Overload the assignment 
	const LinkListType<Type>& operator=(const LinkListType<Type>& other)
	{
		if (first == other.first)
			CopyList();
		else
			return first;
	}
	//Brings  the list to an empty state
	//first = NULL, last = NULL, count = 0
	void InitializeList()
	{
		while (first != NULL)
		{
			DestroyLsit();
		}
	}

	//A function to determin if the list is empty
	// returns true if the list is empty otherwise it returns false
	bool IsEmptyList()
	{
		return first == NULL;
	}

	// A function to return the number of nodes in the list
	//
	void const Print()
	{
		NodeType<Type> *temp = first;
		while (temp != NULL)
		{
			std::cout << temp->info << std::endl;
			temp = temp->link;
		}
	}

	//function to return the length of the nodes in the list

	int Length()
	{
		return count;
	}
	//A function to delete all the nodes from the list
	void DestroyLsit()
	{
		NodeType<Type> *temp;
		while (first != NULL)
		{
			temp = first;
			first = first->link;
			delete temp;
		}
		last = NULL;
		count = 0;
	}

	// A function to return the first element of the list
	// they must exist and must not be empty
	// if the list is empty, the program terminates; otherwise, the first
	Type Front()
	{
		assert(first != NULL);
		return first->info;
	}

	//function to return the last element of the list
	// the must exist and must not be empty
	//if the list is empty, the program terminates; otherwise, the last
	//element of the list is returned
	Type Back()
	{
		assert(last != NULL);
		return last->info;
	}

	//function to determine whether searchItem is on the list
	//returns true if searchItem is in the list, otherwise the value
	//otherwise false is returned
	bool Search(const Type& other) const
	{
		NodeType<Type> *current = new NodeType<Type>;
		while (first != NULL)
		{
			current = first->link;
			if (current->info == other)
			{
				return true;
			}
			return false;
		}
	}

	//function to insert newItem at the begining of the list
	//last points of the last node in the list, and count is increased by 1
	void InsertFirst(const Type& other)
	{
		NodeType<Type> *newItem = new NodeType<Type>;

		newItem->info = other;
		newItem->link = first;
		first = newItem;

		if (count == 0)
			last = first;
		count++;
	}

	//function to insert newItem at the end of the list
	//Postcondition: last points to the new list, newItem is inserted at the end
	//of the list
	//last points of the last node in the list, and count in incremented by 1
	void InsertLast(const Type& other)
	{
		NodeType<Type> *newItem = new NodeType<Type>;

		newItem->info = other;
		last->link = newItem;
		last = newItem;
		last->link = NULL;
		if (count == 0)
			first = last;
		count++;
	}

	//function to delete deleteItem from the list
	//if found, the node containing deleteItem from the list. First
	// points to the first node, last points to the last node of the updated list,
	//and counts is decreased by 1
	void DeleteNode(const Type& other)
	{
		NodeType<Type> *current = new NodeType<Type>;
		NodeType<Type> *next = new NodeType<Type>;
		if (first->info == other)
		{
			current = first;
			first = first->link;
			delete current;
			count--;
			return;
		}
		current = first->link;
		while (current != NULL) {
			if (current->link->info == other)
			{
				NodeType<Type> *deleteNode = current->link;
				current->link = deleteNode->link;
				delete deleteNode;
				count--;
				return;
			}
			current = current->link;
		}
	}

	//function to return an iterator at the begining of the linked list
	LinkListIterator<Type> Begin()
	{
		LinkListIterator<Type> *temp;
		temp->current = first;
		return first;
	}

	//function to return an iterator at the end of the linked list
	LinkListIterator<Type> End()
	{
		LinkListIterator<Type> *temp;
		temp->current = last;
		return last;
	}

	//Default Constructor
	//Initializes the last to an empty state
	LinkListType()
	{
		first = NULL;
		last = NULL;
		count = 0;
	}

	LinkListType(const LinkListType<Type>& other)
	{
		first = NULL;
		CopyList();
	}

	//destructor
	//deletes all the nodes from the list
	~LinkListType()
	{
		delete first;
		delete last;
		count = 0;
	}
private:
	//function to make a copy of otherList
	// a copy of otherList is created and assigned to this list
	void CopyList(const LinkListType<Type>& other)
	{
		NodeType<Type>*newNode;
		NodeType<Type>*current;

		current = other.first;
		newNode = current;
		first = newNode;
		last = newNode;
		InsertFirst(current->info);
		current = current->link;
		while (current != NULL)
		{
			InsertLast(current->info);
			current = current->link;
		}
	}
}; #pragma once
