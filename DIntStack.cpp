#include "DIntStack.h"

DIntStack::DIntStack()
{
	top = NULL ;
	count = 0 ;
}

// Insert the new node before the top node
// Always make sure that the new node's next pointer points to the top node
// In this way, the new node becomes a top node


void DIntStack::Push (char item)
{
	ListNode *temp = new ListNode ;
	temp->item = item ;
	temp->next = top ;  // Make the new node's next pointer points to the top node
	top = temp ;        // The new node becomes a top node

	count++;
}

char DIntStack::Pop()
{
	if (count == 0)
		throw IsEmptyException() ;

	ListNode *temp = top ;   // temp is the node to be deleted
	int item = temp->item ;      // obtain the information in the to-be-deleted node
	top = temp->next ;          // Find the new top after the deleting
	count-- ;

	delete temp ;

	return item ;
}


char DIntStack::Top()
{
	return top->item ;
}


int DIntStack::Size()
{
	return count ;
}
