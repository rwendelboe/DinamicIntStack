#ifndef INT_STACK_H
#define INT_STACK_H

class IntStack
{
private:
	int *Data ;  // Stack array (or pointer)
	int Size ;   // Stack size
	int Top ;    // Top of the stack

public:
	IntStack(int s) ;
	~IntStack() ;

	void Push(int v) ;
	int Pop() ;
	bool IsFull() ;
	bool IsEmpty() ;

	class IsFullException {} ;
	class IsEmptyException {} ;
};

#endif