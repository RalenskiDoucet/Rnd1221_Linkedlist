#include <iostream>
#include "LinkedListtype.h"
#include <assert.h>
int main()
{
	LinkListType<int> *listNumberOne = new LinkListType<int>();
	LinkListType<int> *listNumberTwo = new LinkListType<int>();
	listNumberOne->InsertFirst(1);
	listNumberOne->InsertFirst(2);
	listNumberOne->InsertLast(3);
	listNumberOne->Print();
	listNumberTwo->InsertFirst(1);
	listNumberTwo->InsertFirst(2);
	listNumberTwo->InsertLast(3);
	listNumberTwo->InsertLast(4);
	listNumberTwo->Print();
	assert(listNumberOne->Length() == 3);
	assert(listNumberTwo->Length() == 4);
	system("pause");
}