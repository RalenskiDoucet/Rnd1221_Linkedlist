#include "Linkedlistierator.h"
#include <assert.h>
#include "LinkedListtype.h"
#include <iostream>
int main()
{
	NodeType<int> *a = new NodeType<int>{ 12 };
	NodeType<int> b = { 13 };
	NodeType<int> c = { 14 };
	a->link = &b;
	b.link = &c;
	c.link = NULL;
	LinkListIterator<int> iterator = LinkListIterator<int>(a);
	iterator.operator++();
	LinkListType<int> *listNumOne = new LinkListType<int>();
	LinkListType<int> *listNumTwo = new LinkListType<int>();
	listNumOne->InsertFirst(1);
	listNumOne->InsertFirst(2);
	listNumOne->InsertFirst(3);
	listNumOne->InsertFirst(4);
	listNumOne->InsertFirst(5);
	listNumOne->Print();
	listNumOne->DeleteNode(3);
	listNumOne->Print();

	assert(a->link == &b);
	assert(b.link == &c);
	assert(c.link == NULL);
	assert(iterator.operator*() == 12);
	assert(listNumOne->Length() == 5);
	assert(listNumOne->Front() == 5);
	assert(listNumOne->Back() == 1);
	assert(listNumOne->Search(3) == 3);
	system("pause");
}