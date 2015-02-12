#ifndef DYN_STACK_H
#define DYN_STACK_H
#include <iostream>

class ListNode
{
public:
	ListNode *next ;
	char item ;

	ListNode()
	{
		next = NULL ;
	}
};

class DIntStack
{
private:
	int count ;         // stores the number of elements in the stack
	ListNode *top ;  // the head node of the linked list

public:
	DIntStack() ;
	void Push(char item) ;
	char Pop() ;
	int Size() ;
	char Top();

	class IsEmptyException {} ;

};

#endif