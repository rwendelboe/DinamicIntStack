#include "IntStack.h"

// Dynamically allocate consecutive memeory spaces to hold integers

IntStack::IntStack(int s)
{
	Data = new int[s] ;
	Size = s ;
	Top = -1 ;
}

// Release all allocated memory spaces
IntStack::~IntStack()
{
	delete [] Data ;
}

void IntStack::Push(int v)
{
	if (IsFull())
	{
		//throw exception
		throw IsFullException() ;
	}
	Top++ ;
	Data[Top] = v ;
}

int IntStack::Pop()
{
	if (IsEmpty())
	{
		//throw exception
		throw IsEmptyException() ;
	}
	return Data[Top--] ;
}

bool IntStack::IsFull()
{
	if (Top == Size - 1)	
		return true ;

	return false ;
}

bool IntStack::IsEmpty()
{
	if (Top == -1)	
		return true ;

	return false ;
}